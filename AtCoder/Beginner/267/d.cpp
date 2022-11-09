#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr size_t MAX = 2001;

int dp[MAX];

void solve() {
	int n, m; cin >> n >> m;
	fill_n(dp+1, m, numeric_limits<int>::min()/4);
	vector<int> a(n);
	for(int &x: a) cin >> x;

	for(int i=1;i<=n;i++) for(int k=i;k>=1;k--) {
		int x = a[i-1];
		dp[k] = max(dp[k], dp[k-1] + k*x);
	}

	cout << dp[m] << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
