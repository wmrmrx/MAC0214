#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr int INF = 1e9;

constexpr size_t MAX = 3001;

int dp[MAX][MAX][2];

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin >> a[i];

	for(int i=1;i<=n;i++) {
		auto &cur = dp[i];
		auto &ant = dp[i-1];
		for(int k=0;k+a[i]<=m;k++) {
			auto &val = cur[k+a[i]];
			val[0] = min({val[0], ant[k][0], ant[k][1]});
		}
		for(int k=0;k<=m;k++) {
			auto &val = cur[k];
			val[1] = min({val[1], ant[k][1], ant[k][0] + 1});
		}
	}
	for(int i=1;i<=m;i++) {
		int val = min(dp[n][i][0], dp[n][i][1]);
		if(val >= INF) {
			cout << -1 << " ";
		} else {
			cout << val << " ";
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) for(int b: {0, 1}) {
		dp[i][j][b] = INF;
	}
	dp[0][0][0] = 0;
	solve();
}
