#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define rmin(a, b) a = min(a,b)

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr int MAX = 5000;
constexpr int INF = 1e18;

int cost[MAX];

int dp[MAX][MAX][2];

void solve() {
	string a, b;
	int n, x, y; cin >> n >> x >> y;
	cin >> a >> b;
	vector<int> occ;
	for(int i=0;i<n;i++) {
		if(a[i] != b[i]) occ.push_back(i);
	}

	if(occ.size()%2 == 1) {
		cout << -1 << endl;
		return;
	}
	if(occ.empty()) {
		cout << 0 << endl;
		return;
	}
	if(y <= x) {
		if(occ.size() > 2) {
			cout << y*occ.size()/2 << endl;
		} else if(occ[0] + 1 == occ[1]) {
			cout << min(x, 2*y) << endl;
		} else {
			cout << y << endl;
		}
		return;
	}

	n = occ.size();
	for(int i=1;i<n;i++) {
		cost[i] = min(x*(occ[i]-occ[i-1]), y);
	}

	for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<2;k++)
		dp[i][j][k] = INF;

	dp[0][0][1] = 0;
	dp[0][1][0] = 0;
	for(int i=1;i<n;i++) {
		auto& cur = dp[i];
		auto& ant = dp[i-1];
		for(int j=i;j>=0;j--) {
			rmin(cur[j][1], ant[j][0]);
			if(j-1 >= 0) rmin(cur[j][1], ant[j-1][1]);

			rmin(cur[j][0], ant[j][1] + cost[i]);
			rmin(cur[j][0], ant[j][1] + y);
			rmin(cur[j][0], ant[j+1][0] + y);

//////			cout << "dp[" << i << "][" << j << "][0]: " << dp[i][j][0] << endl;
//////			cout << "dp[" << i << "][" << j << "][1]: " << dp[i][j][1] << endl;
		}
	}

//	dbg("DBG");
//	for(int i=0;i<n;i++) cerr << dp[i][0][0] << ' '; cout << endl;

	if(dp[n-1][0][0] == INF) {
		cout << -1 << endl;
	} else {
		cout << dp[n-1][0][0] << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
