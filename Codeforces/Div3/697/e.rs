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


#[allow(dead_code)]
mod mint {
    #[derive(Clone, Copy, Debug, Default)]
    pub struct Mint<const M: u32>(u32);

    impl<const M: u32> std::ops::Mul for Mint<M> {
        type Output = Mint<M>;
        fn mul(self, rhs: Self) -> Self::Output {
            Mint((self.0 as usize * rhs.0 as usize % M as usize) as u32)
        }
    }

    impl<const M: u32> std::ops::Div for Mint<M> {
        type Output = Mint<M>;
        fn div(self, rhs: Self) -> Self::Output {
            self * rhs.inv()
        }
    }

    impl<const M: u32> std::ops::Add for Mint<M> {
        type Output = Mint<M>;
        fn add(self, rhs: Self) -> Self::Output {
            if self.0 + rhs.0 < M {
                Mint(self.0 + rhs.0)
            } else {
                Mint(self.0 + rhs.0 - M)
            }
        }
    }

    impl<const M: u32> std::ops::Sub for Mint<M> {
        type Output = Mint<M>;
        fn sub(self, rhs: Self) -> Self::Output {
            if self.0 >= rhs.0 {
                Mint(self.0 - rhs.0)
            } else {
                Mint(M + self.0 - rhs.0)
            }
        }
    }

    impl<const M: u32> std::ops::MulAssign for Mint<M> {
        fn mul_assign(&mut self, rhs: Self) {
            *self = *self * rhs;
        }
    }

    impl<const M: u32> std::ops::DivAssign for Mint<M> {
        fn div_assign(&mut self, rhs: Self) {
            *self = *self / rhs;
        }
    }

    impl<const M: u32> std::ops::AddAssign for Mint<M> {
        fn add_assign(&mut self, rhs: Self) {
            *self = *self + rhs;
        }
    }

    impl<const M: u32> std::ops::SubAssign for Mint<M> {
        fn sub_assign(&mut self, rhs: Self) {
            *self = *self - rhs;
        }
    }

    impl<const M: u32> std::ops::Neg for Mint<M> {
        type Output = Mint<M>;
        fn neg(self) -> Self::Output {
            Mint(M - self.0)
        }
    }

    impl<const M: u32> Mint<M> {
        pub fn new(val: i64) -> Self {
            if val >= 0 {
                Mint((val % M as i64) as u32)
            } else {
                -Mint(((-val) as usize % M as usize) as u32)
            }
        }

        pub fn get(self) -> usize {
            self.0 as usize
        }

        pub fn pow(self, mut e: usize) -> Self {
            let mut res = Mint(1);
            let mut pot = self;
            while e > 0 {
                if e % 2 == 1 {
                    res *= pot;
                }
                pot *= pot;
                e /= 2;
            }
            res
        }

        pub fn inv(self) -> Self {
            self.pow((M - 2) as usize)
        }
    }
}

type Mint = mint::Mint<1_000_000_007>;

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
        let (n, k): (u64, u64) = (sc.read(), sc.read());
        let mut a = sc.read_vec::<u64>(n);
        a.sort();
        let mut val = *a.last().unwrap();
        let mut tot = 0;
        let mut rem = 0;
        for _ in 0..k {
            if val == *a.last().unwrap() {
                tot += 1;
            } else {
                val = *a.last().unwrap();
                tot = 1;
            }
            a.pop();
        }
        while let Some(x) = a.last() {
            if *x == val {
                rem += 1;
                tot += 1;
                a.pop();
            } else {
                break;
            }
        }

        let mut fat: Vec<Mint> = vec![Mint::new(1); (tot+1) as u64];

        for i in 1..=tot {
            let tmp = fat[i-1];
            fat[i] *= tmp * Mint::new(i as i64);
        }

        let ans = fat[tot] / fat[rem] / fat[tot - rem];

        bf.putln(ans.get());
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
