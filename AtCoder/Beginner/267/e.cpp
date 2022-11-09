#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr size_t MAX = 200'000;
int n, m;
vector<int> g[MAX];
int a[MAX];
int cost[MAX];
bool act[MAX];

// tests if can do with m max
int max_cost() {
	fill_n(act, n, true);
	for(int v=0;v<n;v++) {
		cost[v] = 0;
		for(int p: g[v]) 
			cost[v] += a[p];
	}
	set<pair<int,int>> pq;
	for(int i=0;i<n;i++) {
		pq.emplace(cost[i], i);
	}

	auto rm = [&](int v) {
		act[v] = false;
		for(int p: g[v]) if(act[p]) {
			pq.erase({cost[p], p});
			cost[p] -= a[v];
			pq.emplace(cost[p], p);
		}
	};

	int ans = 0;

	while(!pq.empty()) {
		auto [c, v] = *pq.begin();
		pq.erase(pq.begin());
		ans = max(ans, c);
		rm(v);
	}

	return ans;
}

void solve() {
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];

	for(int i=0;i<m;i++) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	cout << max_cost() << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
