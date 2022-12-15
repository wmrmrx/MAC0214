#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) //{cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int m; cin >> m;
	string c[2]; cin >> c[0] >> c[1];

	array<vector<int>, 2> dp;
	for(auto &v: dp) v.resize(m);

	dp[0][0] = c[0][0] == 'B';
	dp[1][0] = c[1][0] == 'B';
	dbg(dp[0][0], dp[1][0]);

	for(int j=1;j<m;j++) {
		if(c[0][j] == c[1][j]) {
			dp[0][j] = dp[1][j-1];
			dp[1][j] = dp[0][j-1];
		} else if(c[0][j] == 'B') {
			dp[0][j] = dp[0][j-1];
		} else if(c[1][j] == 'B') {
			dp[1][j] = dp[1][j-1];
		}
	}
	if(dp[0][m-1] || dp[1][m-1]) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
