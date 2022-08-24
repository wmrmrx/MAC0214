#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr size_t N = 101;
constexpr int MOD = 998244353;

int dp[N][N];

void solve() {
	int n; cin >> n;
	vector<int> a(n); 
	for(int &x: a) cin >> x;

	int ans = n;

	for(int m=2;m<=n;m++) {
		for(int i=0;i<=m;i++) {
			for(int j=0;j<m;j++) {
				dp[i][j] = 0;
			}
		}

		dp[0][0] = 1;

		for(int nu=1;nu<=n;nu++) {
			int x = a[nu-1]%m;
			for(int i = min(m, nu); i > 0; i--) {
				for(int j=0;j<m;j++) {
					dp[i][(j+x)%m] += dp[i-1][j];
					dp[i][(j+x)%m] %= MOD;
				}
			}
		}

		ans += dp[m][0];
	}

	cout << ans%MOD << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
