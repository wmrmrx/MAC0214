#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

namespace dsu {
	int dad[(int)2e5];

	int find(int v) {
		return v == dad[v] ? v : dad[v] = find(dad[v]);
	}

	void une(int u, int v) {
		u = find(u);
		v = find(v);
		if(u != v) {
			if(u < v) {
				swap(u, v);
			}
			dad[u] = v;
		}
	}
}

void solve() {
	int n, d; cin >> n >> d;
	iota(dsu::dad, dsu::dad + d + 1, 0);

	vector<pair<int,int>> v(n);

	for(auto &[x, y]: v) {
		cin >> y >> x;
	}

	sort(v.rbegin(), v.rend());

	int ans = 0;

	for(auto &[x, y]: v) {
		int pos = d - y + 1;
		if(pos <= 0 || pos > d) continue;
		pos = dsu::find(pos);
		if(pos != 0) {
			ans += x;
			dsu::une(pos, pos-1);
		} 
	}

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}

