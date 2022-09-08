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
	vector<int> p(n);
	for(int &x: p) cin >> x;
	int ans = 0;
	sort(all(p));
	int last = 0;
	for(int x: p) {
		int y = last/x;
		last = x*y+x;
		ans += last;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	for(int i=0;i<t;i++) {
		solve();
	}
}
