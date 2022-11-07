#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

#define rmax(a, b) a = max(a,b)

constexpr size_t MAX = 10'001;

const int INF = 1e9;

int dp[MAX][2];
bool vis[MAX][2];

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(k);
	dp[n][0] = 0;
	for(int i=0;i<=n;i++)
		dp[i][0] = -INF, dp[i][1] = INF;
	for(int i=n;i>=a[0];i--) {
		for(int o: a) {
			if(o >= i) {
				rmax(dp[i-o][1], dp[i][0] + o);

			}
		}	
	}
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
