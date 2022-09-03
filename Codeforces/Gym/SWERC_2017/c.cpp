#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
//#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}
#define dbg(...)

constexpr int MAX = 1<<8;

constexpr int MOD = 1'000'000'000;
struct Z {
	int x;
	Z(int x=0): x(x) {}
	Z operator+(Z rhs) { return Z{x+rhs.x >= MOD ? x+rhs.x-MOD : x+rhs.x}; }
	Z operator*(Z rhs) { return Z{x*rhs.x%MOD}; }
	void operator+=(Z rhs) { x += rhs.x; if(x >= MOD) x-=MOD; }
};

struct matrix {
	int r, c;
	vector<Z> m;

	matrix(int r, int c): r(r), c(c), m(r*c) {}

	Z* operator[](int i) {
		assert(i < r);
		return &m[i*c];
	}

	matrix operator*(matrix rhs) {
		assert(c == rhs.r);
		matrix res(r, rhs.c);
		for(int i=0;i<r;i++) {
			for(int k=0;k<c;k++) {
				for(int j=0;j<rhs.c;j++) {
					res[i][j] += (*this)[i][k] * rhs[k][j];
				}
			}
		}
		return res;
	}

	matrix fexp(int num) {
		assert(r == c);
		int n = r;
		matrix res(n, n);
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) res[i][j] = Z{i == j};
		for(matrix copy=*this;num;num/=2,copy=copy*copy)
			if(num&1) res = res*copy;
		return res;
	}
};

int N, M;
int s;
Z f[9];

Z ok(int a, int b) {
	for(int k=0;k<N;k++) {
		if(b&(1<<k)) {
			if(a&(1<<k)) {
				return Z(0);
			}
			a |= (1<<k);
		}
	}

	Z res(1);

	for(int k=0;k<N;k++) {
		if(a&(1<<k)) continue;
		int j = k;
		while(j+1 < N && !(a&(1<<(j+1)))) j++;
		res = res*f[j-k+1];
		dbg(a, b, k, j);
		k = j;
	}
	return res;
}

void solve() {
	cin >> N >> M;
	s = 1<<N;

	f[0] = 1; f[1] = 1;
	for(int i=2;i<9;i++) f[i] = f[i-1] + f[i-2];

	matrix st(1, s), tr(s, s);

	st[0][0] = Z{1};

	for(int a=0;a<s;a++) for(int b=0;b<s;b++) 
			tr[a][b] = ok(a,b);

	tr = tr.fexp(M);

	st = st * tr;

	cout << st[0][0].x << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
