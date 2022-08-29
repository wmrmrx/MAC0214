#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define endl '\n'

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr int MAX = 200'000;

namespace dsu {
	int dad[MAX], sz[MAX];

	int find(int v) {
		return dad[v] == v ? v : dad[v] = find(dad[v]);
	}

	void join(int u, int v) {
		 u = find(u); v = find(v);
		 if(u == v) return;
		 if(sz[u] > sz[v]) swap(u,v);
		 dad[u] = v;
		 sz[v] += sz[u];
	}

	void init(int n) {
		fill_n(sz, n, 1);
		iota(dad, dad+n, 0);
	}
}

vector<int> g[MAX];
int deg[MAX];

void solve() {
	int n; cin >> n;

	for(int i=0;i<n;i++) {
		int a,b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		deg[a]++; deg[b]++;
		g[b].push_back(a);
	}

	dsu::init(n);

	set<pair<int,int>> ord;

	for(int i=0;i<n;i++) {
		ord.insert({deg[i], i});
	}

	while(!ord.empty()) {
		auto &[d, v] = *ord.begin();
		ord.erase(ord.begin());
		if(d > 1) break;
		if(d == 0) continue;
		deg[v] = 0;
		for(int p: g[v]) if(deg[p]) {
			dsu::join(v, p);
			ord.erase({deg[p], p});
			ord.insert({--deg[p], p});
		}
	}

	int q; cin >> q;
	while(q--) {
		int a,b; cin >> a >> b; a--; b--;
		if(dsu::find(a) == dsu::find(b)) {
			cout << "Yes";
		} else {
			cout << "No";
		}
		cout << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
