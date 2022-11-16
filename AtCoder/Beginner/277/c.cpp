#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

map<int, vector<int>> g;
set<int> vis;

int ans = 1;

void dfs(int v) {
	if(vis.find(v) != vis.end()) return;
	vis.insert(v);
	ans = max(ans, v);
	for(int p: g[v]) {
		dfs(p);
	}
}

void solve() {
	int n; cin >> n;
	for(int i=0;i<n;i++) {
		int a, b; cin >> a >> b;
		if(g.find(a) == g.end()) {
			g[a] = vector<int>();
		} 
		if(g.find(b) == g.end()) {
			g[b] = vector<int>();
		} 
		g[a].push_back(b);
		g[b].push_back(a);
	}

	if(g.find(1) == g.end()) {
		cout << 1 << endl;
		return;
	}
	dfs(1);

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
