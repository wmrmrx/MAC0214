#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

// Binary lifting on a rooted tree
struct BLift {
	vector<int> dep;
	vector<vector<int>> dp;

	BLift(int sz, vector<int> g[], int root): dep(sz) {
		int log = 32-__builtin_clz(sz);
		dp.assign(log, vector<int>(sz));
		function<void(int,int)> dfs = [&](int v, int dad) {
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

	int jump(int v, int j) {
		for(int l=0;l<(int)dp.size();l++) if(j&(1<<l))
			v = dp[l][v];
		return v;
	}

	int lca(int a, int b) {
		if(dep[a] < dep[b]) swap(a,b);
		a = jump(a, dep[a] - dep[b]);
		if(a == b) return a;
		for(int l=(int)dp.size()-1;l>=0;l--) 
			if(dp[l][a] != dp[l][b])
				a = dp[l][a], b = dp[l][b];
		return dp[0][a];
	}

	int dist(int a, int b) {
		return dep[a] + dep[b] - 2*dep[lca(a,b)];
	}
};

constexpr size_t MAX = 2000;

vector<int> g[MAX];
bool vis[MAX][MAX];
int dp[MAX][MAX];

int calc(int i, int j, string &s, BLift& bl) {
	if(vis[i][j]) return dp[i][j];
	vis[i][j] = 1;
	auto &res = dp[i][j];
	res = -1;
	if(i == j) return res = 1;
	int lca = bl.lca(i, j);
	int d = bl.dist(i, j);
	if(d == 1) {
		return res = (s[i] == s[j] ? 2 : 1);
	}
	int pi = lca == i ? bl.jump(j, d-1) : bl.jump(i, 1);
	int pj = lca == j ? bl.jump(i, d-1) : bl.jump(j, 1);
	if(s[i] == s[j]) {
		res = max(2 + calc(pi, pj, s, bl), res);
	}
	res = max(calc(pi, j, s, bl), res);
	res = max(calc(i, pj, s, bl), res);
	return res;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	for(int i=0;i<n-1;i++) {
		int u, v; cin >> u >> v;
		--u; --v;
		g[u].pb(v);
		g[v].pb(u);
	}

	BLift bl(n, g,  0);

	int ans = 0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		ans = max(ans, calc(i, j, s, bl));
	}
	cout << ans << endl;

	//reset 
	for(int i=0;i<n;i++) {
		g[i].clear();
		for(int j=0;j<n;j++) vis[i][j] = 0;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();

}
