#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int n, m; cin >> n >> m;
	vector<int> r(n), c(m);
	vector<vector<int>> marc(n, vector<int>(m));
	for(int i=0;i<n;i++) {
		string s; cin >> s;
		for(int j=0;j<m;j++) {
			if(s[j] == '*') {
				r[i]++;
				c[j]++;
				marc[i][j]++;
			}
		}
	}
	int ans = numeric_limits<int>::max();
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		int need = n + m - 1 - ( r[i] + c[j] - marc[i][j] );
		ans = min(ans, need);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q; cin >> q;
	while(q--) {
		solve();
	}
}
