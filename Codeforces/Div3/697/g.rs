////////////////////////
// BEGIN DEFAULT CODE //
////////////////////////

#[allow(dead_code)]
mod util {
    use std::cell::UnsafeCell;
    use std::io::{BufReader, BufWriter, Read, Write};

    pub struct Scanner<'a, R: Read> {
        reader: BufReader<R>,
        buffer: UnsafeCell<String>,
        tokens: std::str::SplitWhitespace<'a>,
    }

    impl<'a, R: Read> Iterator for Scanner<'a, R> {
        type Item = &'a str;
        fn next(&mut self) -> Option<Self::Item> {
            use std::io::BufRead;
            loop {
                if let Some(s) = self.tokens.next() {
                    break Some(s);
                } else {
                    unsafe {
                        self.tokens = "".split_whitespace();
                        self.buffer.get_mut().clear();
                        self.reader.read_line(self.buffer.get_mut()).unwrap();
                        self.tokens = (*self.buffer.get()).split_whitespace();
                    }
                }
            }
        }
    }

    impl<R: Read> Scanner<'_, R> {
        pub fn new(reader: R) -> Self {
            Self {
                reader: BufReader::new(reader),
                buffer: UnsafeCell::new(String::new()),
                tokens: "".split_whitespace(),
            }
        }

        pub fn read<T: std::str::FromStr<Err = impl std::fmt::Debug>>(&mut self) -> T {
            self.next().unwrap().parse::<T>().unwrap()
        }

        pub fn read_vec<T: std::str::FromStr<Err = impl std::fmt::Debug>>(
            &mut self,
            size: usize,
        ) -> Vec<T> {
            (0..size).map(|_| self.read()).collect()
        }
    }

    pub struct Writer<W: Write> {
        writer: BufWriter<W>,
    }

    impl<W: Write> Writer<W> {
        pub fn new(writer: W) -> Self {
            Self {
                writer: BufWriter::new(writer),
            }
        }

        pub fn put<T: std::fmt::Display>(&mut self, t: T) -> &mut Self {
            let _ = write!(self.writer, "{t}");
            self
        }

        pub fn putln<T: std::fmt::Display>(&mut self, t: T) -> &mut Self {
            let _ = writeln!(self.writer, "{t}");
            self
        }

        pub fn ws(&mut self) -> &mut Self {
            let _ = write!(self.writer, " ");
            self
        }

        pub fn endl(&mut self) {
            let _ = writeln!(self.writer);
            self.flush()
        }

        pub fn flush(&mut self) {
            let _ = self.writer.flush();
        }
    }

    pub fn i<S: std::convert::TryInto<usize>>(i: S) -> usize
    where
        <S as std::convert::TryInto<usize>>::Error: std::fmt::Debug,
    {
        i.try_into().unwrap()
    }
}

#[allow(unused_imports)]
use std::{
    collections::{BTreeMap as Map, BTreeSet as Set, VecDeque as Deque},
    format as fmt,
    io::{Read, Write},
};
#[allow(unused_imports)]
use util::{i, Scanner, Writer};
type In<'a, R> = Scanner<'a, R>;
type Out<W> = Writer<W>;
#[allow(dead_code, non_camel_case_types)]
type u64 = usize;

//////////////////////
// END DEFAULT CODE //
//////////////////////

pub const N: usize = 200_001;

#[derive(Debug)]
struct Solver {
    cnt: [usize; N],
    dp: [usize; N],
}

impl Solver {
    fn new() -> Self {
        Self {
            cnt: [0; N],
            dp: [0; N]
        }
    }

    fn clean(&mut self) {
        for i in self.cnt.iter_mut() {
            *i = 0;
        }
        for i in self.dp.iter_mut() {
            *i = 0;
        }
    }
}

impl Solver {
    fn solve<R: Read, W: Write>(&mut self, sc: &mut In<R>, bf: &mut Out<W>) {
        let n: u64 = sc.read();
        for i in sc.read_vec::<usize>(n) {
            self.cnt[i] += 1;
        }

        let g = sieve::divs();

        self.dp[1] = self.cnt[1];

        let mut ans = self.dp[1];

        for i in 2..N {
            if self.cnt[i] == 0 {
                continue;
            }
            for &p in g[i].iter() {
                self.dp[i] = self.dp[i].max(self.dp[p] + self.cnt[i]);
            }
            ans = ans.max(self.dp[i]);
        }
        bf.put(n-ans).endl();
    }
}

fn main() {
    sieve::init();
    let mut sc = Scanner::new(std::io::stdin().lock());
    let mut bf = Writer::new(std::io::stdout().lock());
    let mut solver = Solver::new();

    //let t: u64 = 1;
    let t: u64 = sc.read();

    for case in 1..=t {
        solver.solve(&mut sc, &mut bf);
        if case != t {
            solver.clean();
        }
    }
}


#[allow(dead_code)]
mod sieve {
    use super::N;
    static mut SIEVE: [usize; N] = [0; N];
    static mut DIV: Vec<Vec<usize>> = Vec::new();

    pub fn divs() -> &'static [Vec<usize>] {
        unsafe {
            &DIV
        }
    }

    unsafe fn comp_div() {
        DIV[1].push(1);
        for i in 2..N {
            let mut n = i;
            let p = SIEVE[i];
            let mut cnt = 0;
            while n % p == 0 {
                n /= p;
                cnt += 1;
            }
            DIV[i] = DIV[n].clone();

            let sz = DIV[n].len();

            let mut pot = 1;
            for _ in 1..=cnt {
                pot *= p;
                for j in 0..sz {
                    DIV[i].push(DIV[n][j] * pot);
                }
            }
        }
        for i in 1..N {
            DIV[i].pop();
        }
    }

    #[forbid(dead_code)]
    pub fn init() {
        unsafe {
            for i in 2..N {
                if SIEVE[i] == 0 {
                    SIEVE[i] = i;
                    for j in (i * i..N).step_by(i) {
                        if SIEVE[j] == 0 {
                            SIEVE[j] = i;
                        }
                    }
                }
            }
            DIV = vec![Vec::new(); N];
            comp_div();
        }
    }
}
