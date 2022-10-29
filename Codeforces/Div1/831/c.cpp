#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr int INF  = 1e18;

void solve() {
	int n; cin >> n;
	vector<int> a(n), d(n);
	for(int &x: a) cin >> x;
	sort(all(a));
	int ans = 0;
	for(int i=0;i<n-2;i++) {
		ans = max(ans, a[n-1]-a[i]+a[i+1]-a[i]);
	}
	for(int i=n-1;i>=2;i--) {
		ans = max(ans, a[i]-a[0]+a[i]-a[i-1]);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
