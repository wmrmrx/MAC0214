#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(), v.end()

void dbg_out() {cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...)//{cerr<<#__VA_ARGS__<<':'; dbg_out(__VA_ARGS__);}

constexpr size_t MAX = 200'000;
vector<int> g[MAX];

struct DSU {
	vector<int> dad, sz;
	DSU(int n) {
		dad = vector<int>(n);
		iota(all(dad), 0);
		sz = vector<int>(n, 1);
	}
	int find(int v) {
		return v == dad[v] ? v : dad[v] = find(dad[v]);
	}
	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if(u != v) {
			if(sz[u] > sz[v]) swap(u,v);
			dad[u] = v;
			sz[v] += sz[u];
		}
	}
	bool same(int u, int v) {
		return find(u) == find(v);
	}
	void reset() {
		iota(all(dad), 0);
		fill(all(sz), 0);
	}
};

void solve() {
	int n; cin >> n;
	DSU dsu(n);
	vector<int> deg(n);
	for(int i=0;i<n;i++) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}

	vector<bool> out(n);
	set<pair<int,int>> pq;

	for(int i=0;i<n;i++) {
		pq.emplace(deg[i], i);
	}

	while(pq.begin()->first == 1) {
		auto [_d, v] = *pq.begin();
		out[v] = 1;
		pq.erase(pq.begin());
		for(int p: g[v]) if(!out[p]) {
			pq.erase({deg[p], p});
			deg[p]--;
			pq.insert({deg[p], p});
		}
	}


	function<void(int,int)> dfs = [&](int v, int dad) {
		dbg(v, dad);
		for(int p: g[v]) if(out[p] && p != dad) {
			dsu.join(p, v);
			dfs(p, v);
		}
	};
	for(int v=0;v<n;v++) if(!out[v]) {
		dfs(v, -1);
	}

	int q; cin >> q;
	while(q--) {
		int x, y; cin >> x >> y; --x; --y;
		if(dsu.same(x, y)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
