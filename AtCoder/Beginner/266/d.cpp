#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(), v.end()

void dbg_out() {cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << h << ' '; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':'; dbg_out(__VA_ARGS__);}

constexpr int INF = 1e18;

void solve() {
	int n; cin >> n;
	vector<array<int, 3>> snu(n);
	for(auto &[t, x, a]: snu) cin >> t >> x >> a;
	sort(snu.rbegin(), snu.rend());

	vector<int> cur(5, -INF), ant(5, -INF);
	cur[0] = 0;
	for(int t=1;!snu.empty();t++) {
		swap(cur, ant);
		cur[0] = max(ant[0], ant[1]);		
		for(int i=1;i<4;i++) {
			cur[i] = max({ant[i-1], ant[i], ant[i+1]});
		}
		cur[4] = max(ant[3], ant[4]);		
		while(!snu.empty() && snu.back()[0] == t) {
			auto [_t, x, a] = snu.back();
			snu.pop_back();
			cur[x] += a;
		}
	}
	cout << *max_element(all(cur)) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
