#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){ cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr size_t MAX = 100'001;
vector<int> g[MAX];

void solve() {
	int n, m; cin >> n >> m;
	for(int i=0;i<m;i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) sort(all(g[i]));

	for(int i=1;i<=n;i++) {
		cout << g[i].size() << ' ';
		for(int p: g[i]) cout << p << ' ';
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
