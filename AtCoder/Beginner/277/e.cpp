#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

constexpr size_t MAX = 400'000;
constexpr size_t INF = 1e18;

vector<pair<int,int>> g[MAX];

int bfs(int n) {
	vector<int> dist(2*n, INF);
	deque<int> dq;
	dist[0] = 0;
	dq.push_back(0);
	while(!dq.empty()) {
		int v = dq.front();
		dq.pop_front();
		for(auto [p, b]: g[v]) if(dist[p] > dist[v] + b) {
			dist[p] = dist[v] + b;
			if(b == 0) {
				dq.push_front(p);
			} else {
				dq.push_back(p);
			}
		}
	}
	int res = min(dist[n-1], dist[2*n-1]);

	if(res == INF) {
		return -1;
	} else {
		return res;
	}
}

void solve() {
	int n, m, k; cin >> n >> m >> k;
	for(int i=0;i<m;i++) {
		int u, v, a; cin >> u >> v >> a;
		--u; --v;
		if(a == 1) {
			g[u].emplace_back(v, 1);
			g[v].emplace_back(u, 1);
		} else {
			g[n+u].emplace_back(n+v, 1);
			g[n+v].emplace_back(n+u, 1);
		}
	}
	for(int i=0;i<k;i++) {
		int s; cin >> s;
		--s;
		g[s].emplace_back(s+n, 0);
		g[s+n].emplace_back(s, 0);
	}
	cout << bfs(n) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
