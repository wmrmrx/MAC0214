#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int dp[2][5001], bonus[5001];
int x[5001];

void solve() {
	int n, m; cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> x[i];
	for(int i=0;i<m;i++) {
		int c, y; cin >> c >> y;
		bonus[c] = y;
	}

	for(int i=1;i<=n;i++) {
		int *cur = dp[i&1], *ant = dp[!(i&1)];
		int mx = -1;
		for(int c=i;c>0;c--) {
			cur[c] = ant[c-1] + x[i];	
			cur[c] += bonus[c];
		}
		cur[0] = *max_element(ant, ant+i);
	}

	cout << *max_element(dp[n&1], dp[n&1]+n+1) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
