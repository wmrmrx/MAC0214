#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr size_t MAX = 2500;

int dp[MAX];
bool vis[MAX], visrev[MAX];
vector<int> g[MAX];
vector<int> grev[MAX];

void dfs(int v) {
	vis[v] = 1;
	for(auto p: g[v]) if(!vis[p]) {
		dfs(p);
	}
}

void dfsrev(int v) {
	visrev[v] = 1;
	for(auto p: grev[v]) if(!visrev[p]) {
		dfsrev(p);
	}
}

void solve() {
	int n, m, p; cin >> n >> m >> p;

	vector<array<int, 3>> ed(m);
	
	for(int i=0;i<m;i++) {
		int x, y, c; cin >> x >> y >> c;
		x--; y--; c -= p;
		ed[i] = {x,y,c};
		g[x].push_back(y);
		grev[y].push_back(x);
	}

	dfs(0);
	dfsrev(n-1);

	fill_n(dp, n, numeric_limits<int>::min()/2);
	dp[0] = 0;

	sort(all(ed));

	for(int i=0;i<n-1;i++) {
		for(auto &[x,y,c]: ed) {
			if(!vis[x] || !visrev[y]) {
				continue;
			}
			dp[y] = max(dp[x] + c, dp[y]);
		}
	}
	for(auto &[x,y,c]: ed) {
		if(!vis[x] || !visrev[y]) continue;
		if(dp[y] < dp[x] + c) {
			cout << -1 << endl;
			return;
		}
	}
	cout << max<int>(0, dp[n-1]) << endl;
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}

