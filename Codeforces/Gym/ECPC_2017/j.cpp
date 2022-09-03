#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr int MAX = 501;

int p[MAX];

void solve() {
	int N; cin >> N;
	for(int i=1;i<=N;i++) {
		cin >> p[i];
	}
	int q; cin >> q;
	while(q--) {
		int ans = numeric_limits<int>::max();
		int n, m; cin >> n >> m;
		for(int a=1;a<=n;a++) {
			int k = (a+1)*m-n;
			if(k < 0 || k > m) continue;
			if(a == n && m-k > 0) continue;
			ans = min(ans, k*p[a] + (m-k)*p[a+1]);
			//dbg(a, p[a], k, n, m);
		}
		if(ans == numeric_limits<int>::max()) {
			cout << "impossible" << '\n';
		} else {
			cout << ans << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("jacking.in", "r", stdin);
	int t; cin >> t;
	for(int i=1;i<=t;i++) {
		cout << "Case " << i << ": ";
		cout << '\n';
		solve();
	}
}
