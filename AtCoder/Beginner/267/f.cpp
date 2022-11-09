#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

struct LCA {
	int sz, log;
	vector<vector<int>> dp;
	vector<int> dep;
	LCA(int _sz, int root, vector<int> g[]): sz(_sz), log(32-__builtin_clz(sz)), dp(log, vector<int>(sz)), dep(sz) {
		function<void(int, int)> dfs = [&](int v, int dad) {
			dp[0][v] = dad;
			for(int p: g[v]) if(p != dad) {
				dep[p] = dep[v] + 1;
				dfs(p, v);
			}
		};
		dfs(root, root);
		for(int l=1;l<log;l++) {
			auto &cur = dp[l], &ant = dp[l-1];
			for(int i=0;i<sz;i++)
				cur[i] = ant[ant[i]];
		}		
	}

	int query(int u, int v) {
		if(dep[u] < dep[v]) swap(u,v);
		u = jump(u, dep[u] - dep[v]);
		if(u == v) return u;
		for(int l=log-1;l>=0;l--) {
			auto &cur = dp[l];
			if(cur[u] == cur[v]) continue;
			u = cur[u]; v = cur[v];
		}
		return (u == v ? u : dp[0][u]);
	}

	int jump(int v, int j) {
		for(int i=0;i<log;i++) if(j&(1<<i)) {
			v = dp[i][v];
		}
		return v;
	}

	int dist(int u, int v) {
		return dep[u] + dep[v] - 2*dep[query(u,v)];
	}
};

constexpr size_t MAX = 200'000;
vector<int> g[MAX];
int n;
// vertex of diameters
int a, b;

int farthest(int ini_v) {
	vector<int> dist(n);
	function<void(int,int)> dfs = [&](int v, int dad) {
		for(int p: g[v]) if(p != dad) {
			dist[p] = dist[v] + 1;
			dfs(p, v);
		}
	};
	dfs(ini_v, ini_v);
	return max_element(all(dist)) - dist.begin();
}

int test(int v, int u, int k, LCA& lca) {
	int d = lca.dist(v, u);
	if(d < k) {
		return -1;
	}

	if(k >= lca.dist(v , lca.query(u,v))) {
		return lca.jump(u, d-k);
	} else {
		return lca.jump(v, k);
	}
}

void solve() {
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	LCA lca(n, 0, g);
	a = farthest(0);
	b = farthest(a);
	int q; cin >> q;
	while(q--) {
		int v, k; cin >> v >> k; --v;
		int res = test(v,a,k,lca);
		if(res != -1) {
			cout << res+1 << endl;
			continue;
		}
		res = test(v,b,k,lca);
		cout << (res == -1 ? -1 : res+1) << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
