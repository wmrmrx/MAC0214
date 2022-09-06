#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void print(vector<int> a) {
	for(int x: a) cout << x << ' ';
	cout << '\n';
}

void solve() {
	int n, m; cin >> n >> m;
	if(n > m) {
		cout << "No\n";
		return;
	}

	if(n == 1) {
		cout << m << '\n';
		return;
	}

	if(n == 2 && m%2 != 0) {
		cout << "No\n";
		return;
	} else {
		cout << m/2 << ' ' << m/2 << '\n';
		return;
	}

	int p = 1;
	while(m%2 == 0) {
		m /= 2; p = 1;
	}

	vector<int> a(n, 1);
	if((m - (n-1))%2 == 0) {
		a.back() = m-(n-1);
		print(a);
		return;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
