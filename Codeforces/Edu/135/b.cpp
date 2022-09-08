#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	vector<int> p(n-2);
	iota(all(p),1);
	reverse(all(p));
	if(n%2 == 1) {
		swap(p[0], p[1]);
	}
	p.push_back(n-1);
	p.push_back(n);
	for(int x: p) cout << x << ' ';
	cout << '\n';
	return;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
