#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr size_t MAX = 500;
namespace dsu {
	int dad[MAX];
	vector<int> comp[MAX];

	int find(int v) {
		return v == dad[v] ? v : dad[v] = find(dad[v]);
	}

	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if(u != v) {
			dad[v] = u;
		}
	}

	void init(int n) {
		iota(dad, dad+n, 0);
	}
}

namespace kuhn {
	vector<int> g[MAX];
	int n, m;
	int ml[MAX], mr[MAX];
	bool vis[MAX];

	void add_edge(int a, int b) {
		g[a].push_back(b);
	}

	void init(int _n, int _m) {
		n = _n;
		m = _m;
		fill_n(ml, n, -1);
		fill_n(mr, m, -1);
	}
	
	bool dfs(int v) {
		if(vis[v]) return false;
		vis[v] = 1;
		for(int p: g[v]) {
			if(mr[p] == -1 || dfs(mr[p])) {
				ml[v] = p;
				mr[p] = v;
				return true;
			}
		}
		return false;
	}

	int matching() {
		int res = 0;
		bool t = true;
		while(t) {
			t = false;
			fill_n(vis, n, false);
			for(int i=0;i<n;i++) if(ml[i] == -1) {
				if(dfs(i)) {
					t = 1;
					res++;
				}
			}
		}
		return res;
	}
}

bitset<MAX> a[MAX];
bitset<MAX> aT[MAX];

bool vis[MAX];
vector<int> g[MAX];
bitset<MAX> reach[MAX];

void dfs(int v) {
	if(vis[v]) return;
	vis[v] = 1;
	for(int p: g[v]) {
		dfs(p);
		reach[v] |= reach[p];
	}
}

void solve() {
	int n, m; cin >> n >> m;
	kuhn::init(m, m);
	for(int i=0;i<n;i++) {
		string s; cin >> s;
		for(int j=0;j<m;j++) {
			a[i][j] = s[j] == '1';
			aT[j][i] = a[i][j];
		}
	}

	for(int i=0;i<m;i++) for(int j=i+1;j<m;j++) {
		if( (aT[i] | aT[j] ) == aT[i]) {
			reach[i][j] = 1;
			g[i].push_back(j);
		} else if( ( aT[i] | aT[j] ) == aT[j]) {
			reach[j][i] = 1;
			g[j].push_back(i);
		}
	}

	for(int i=0;i<m;i++) {
		dfs(i);
	}

	for(int i=0;i<m;i++) for(int j=0;j<m;j++) if(reach[i][j])
		kuhn::add_edge(i, j);

	vector<int> lvl(m, 0), grp(m);
	int k = m - kuhn::matching();
	vector<vector<int>> access(n, vector<int>(k, 1));
	
	cout << k << endl;
	
	fill_n(vis, m, false);
	int grp_cnt = 0;
	function<void(int)> get_lvl = [&](int v) {
		if(vis[v]) return;
		vis[v] = true;
		if( kuhn::ml[v] == -1 ) {
			lvl[v] = 1e8;
			grp[v] = grp_cnt++;
		}
		else {
			get_lvl(kuhn::ml[v]);
			lvl[v] = lvl[kuhn::ml[v]] - 1;
			grp[v] = grp[kuhn::ml[v]];
		}
	};
	for(int i=0;i<m;i++) get_lvl(i);

	for(int x: grp) cout << x + 1 << ' ';
	cout << endl;
	for(int x: lvl) cout << x << ' ';
	cout << endl;

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) if(a[i][j]) {
			access[i][grp[j]] = max(access[i][grp[j]], lvl[j]);
		}
		for(int x: access[i]) cout << x << ' ';
		cout << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
