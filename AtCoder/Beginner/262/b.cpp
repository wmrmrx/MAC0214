#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg(__VA_ARGS__); }

constexpr size_t MAX = 100;

bool adj[MAX][MAX];

void solve() {
	int n, m; cin >> n >> m;
	while(m--) {
		int u,v; cin >> u >> v; u--; v--;
		adj[u][v] = adj[v][u] = 1;
	}
	int ans = 0;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++) {
		if(adj[i][j] && adj[i][k] && adj[j][k]) ans++;
	}
	cout << ans << endl;

}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
