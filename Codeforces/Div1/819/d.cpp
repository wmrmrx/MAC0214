#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr int MAX = 200'000;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct dsu {
	vector<int> dad, sz;
	dsu(int n) {
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
	int n, m; cin >> n >> m;
	vector<array<int, 3>> ed(m);
	vector<int> ansed(m);
	for(int i=0;i<m;i++) {
		auto &[u, v, id] = ed[i];
		id = i;
		cin >> u >> v;
		u--; v--;
	}
	dsu r(n), b(n);
	int opt = 2*n - m;
	int ans = 2*n;
	while(ans != opt) {
		r.reset(); b.reset();
		shuffle(all(ed), rng);
		fill(all(ansed), 0);
		int res = 2*n;
		for(auto &[u, v, id] : ed) {
			if(!r.same(u,v)) {
				r.join(u, v);
				res--;
			} else {
				ansed[id] = 1;
				if(!b.same(u,v)) {
					res--;
				}
				b.join(u,v);
			}
		}
		ans = min(ans, res);
		if(ans == opt) break;
	}
	for(int i: ansed) cout << i; cout <<'\n';
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
