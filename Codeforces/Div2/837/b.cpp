#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n, m; cin >> n >> m;
	vector<int> good(n, n);
	for(int i=0;i<m;i++) {
		int x, y; cin >> x >> y;
		x--; y--;
		if(x > y) swap(x, y);
		good[x] = min(good[x], y);
	}
	int ans = 0;
	for(int i=n-1;i>=0;i--) {
		if(i+1 < n) {
			good[i] = min(good[i], good[i+1]);
		}
		ans += good[i] - i;
	}
//	dbg(good.size());
//	for(int x: good) dbg(x);
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
