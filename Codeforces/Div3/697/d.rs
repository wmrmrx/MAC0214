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

#[derive(Debug, Default)]
struct Solver {}

impl Solver {
    fn new() -> Self {
        Self::default()
    }

    fn clean(&mut self) {
        *self = Solver::new();
    }
}

impl Solver {
    fn solve<R: Read, W: Write>(&mut self, sc: &mut In<R>, bf: &mut Out<W>) {
        let (n, m): (u64, u64) = (sc.read(), sc.read());
        let a = sc.read_vec::<u64>(n);
        let b = sc.read_vec::<u64>(n);

        let mut reg: Vec<u64> = Vec::new();
        let mut imp: Vec<u64> = Vec::new();

        for (x, y) in a.into_iter().zip(b.into_iter()) {
            if y == 1 {
                reg.push(x);
            } else {
                imp.push(x);
            }
        }

        reg.sort();
        reg.reverse();
        imp.sort();
        imp.reverse();

        let (a, b) = (reg.len(), imp.len());

        let mut sreg = vec![0; a];
        let mut simp = vec![0; b];

        if a > 0 {
            sreg[0] = reg[0];
        }
        if b > 0 {
            simp[0] = imp[0];
        }

        for i in 1..a {
            sreg[i] = reg[i] + sreg[i-1];
        }
        for i in 1..b {
            simp[i] = imp[i] + simp[i-1];
        }

        drop(imp);
        drop(reg);

        let mut ans: u64 = u64::MAX;

        for (i, &f) in sreg.iter().enumerate() {
            if f >= m {
                ans = ans.min(i+1);
                break;
            }
        }

        for (i, &f) in simp.iter().enumerate() {
            if f >= m {
                ans = ans.min(2*(i+1));
                break;
            }
        }

        let search = |need| -> u64 {
            let (mut lo, mut hi) = (0, a);
            while lo < hi {
                let m = (lo + hi) / 2;
                if sreg[m] < need {
                    lo = m + 1;
                } else {
                    hi = m;
                }
            }
            return lo;
        };

        for i in 0..b {
            if simp[i] >= m {
                break;
            }
            let j = search(m - simp[i]);
            if j < a {
                ans = ans.min(2*(i+1) + (j+1));
            }
        }

        if ans == u64::MAX {
            bf.putln(-1);
        } else {
            bf.putln(ans);
        }

    }
}

fn main() {
    let mut sc = Scanner::new(std::io::stdin().lock());
    let mut bf = Writer::new(std::io::stdout().lock());
    let mut solver = Solver::new();

    //let t: u64 = 1;
    let t: u64 = sc.read();

    for case in 0..t {
        solver.solve(&mut sc, &mut bf);
        if case != t - 1 {
            solver.clean();
        }
    }
}
