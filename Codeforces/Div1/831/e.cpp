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
	vector<int> p(n);
	for(int i=1;i<n;i++) {
		cin >> p[i], p[i]--;
	};
	vector<int> dp(n), prof(n, 1);
	vector<vector<int>> g(n);
	for(int i=1;i<n;i++) g[p[i]].push_back(i);

	function<void(int)> dfs = [&](int v) {
		if(g[v].empty()) {
			dp[v] = 1;
			return;
		}
		for(int px: g[v]) {
			dfs(px);
			prof[v] = max(prof[px]+1, prof[v]);
			dp[v] += dp[px];
		}
		dp[v] = max(dp[v], prof[v]);
	};
	dfs(0);
	cout << dp[0] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
