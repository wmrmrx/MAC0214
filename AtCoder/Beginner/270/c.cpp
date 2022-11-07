#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

constexpr size_t MAX = 200'000;
vector<int> g[MAX];
int dep[MAX], dad[MAX];

void dfs(int v) {
	for(int p: g[v]) if(p != dad[v]) {
		dep[p] = dep[v] + 1;
		dad[p] = v;
		dfs(p);
	}
}

void solve() {
	int n, x, y; cin >> n >> x >> y;
	--x; --y;
	for(int i=0;i<n-1;i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0);

	vector<int> ux, uy;
	ux.push_back(x);
	uy.push_back(y);
	while(dep[x] > dep[y]) {
		x = dad[x];
		ux.push_back(x);
	}
	while(dep[y] > dep[x]) {
		y = dad[y];
		uy.push_back(y);
	}
	while(x != y) {
		x = dad[x];
		y = dad[y];
		ux.push_back(x);
		uy.push_back(y);
	}
	ux.pop_back();
	reverse(all(uy));
	for(int i: ux) cout << i+1 << ' ';
	for(int i: uy) cout << i+1 << ' ';
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
