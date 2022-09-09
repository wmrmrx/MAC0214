#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() {cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

mt19937_64 rng(0);
vector<int> e, o;

bool query(int a, int b) {
	cout << " ?" << a << ' ' << b << endl;
	char c; cin >> c;
	if(c == '<') {
		return 1;
	} else if( c == '>' ) {
		return false;
	}
}

int answer() {
	cout << "! ";
	for(int x: e) cout << x << ' ';
	for(int x: o) cout << x << ' ';
	cout << endl;
}

//
void qsort(int l, int r, bool plus) {
	int piv = uniform_int_distribution<int>(l, r)(rng);
	int x = l, y = r;
	for(int cnt=1;cnt<=(r-l+1)+plus;cnt++) {
		if(query(e[piv], o[x])) {
			swap(o[x], o[y]);
			y--;
		} else {
			x++;
		}
	}
}

void solve() {
	int n; cin >> n;
	e.resize(n/2); o.resize((n+1)/2);
	iota(all(e), 0);
	iota(all(o), 0);
	qsort(0, n/2, n%2);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
