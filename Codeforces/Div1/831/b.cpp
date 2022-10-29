#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	int ans = 0;
	for(auto& val: v) {
		int x, y; cin >> x >> y;
		ans += 2*min(x,y);
		val = max(x,y);
	}
	sort(all(v));
	for(int i=0;i<n-1;i++) {
		ans += abs(v[i+1] - v[i]);
	}
	ans += v[0] + v[n-1];
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
