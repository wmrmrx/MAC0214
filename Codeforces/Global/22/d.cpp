#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr size_t MAX = 100'100;

int n, k;

int b[MAX];

vector<int> g[MAX];
vector<int> ans;

void bfs(int s) {
	set<pair<int, int>> q;
	q.insert({0, s});

	vector<bool> vis(n+2);

	while(!q.empty()) {
		int cur = q.begin()->second;
		q.erase(q.begin());

		ans.push_back(cur);

		vis[cur] = 1;

		for(int p: g[cur])  {
			if(!vis[p]) {
				q.insert({g[p].size(), p});
				vis[p] = 1;
			}
		}
	}
}

void solve() {
	cin >> n;
	for(int i=0;i<=n+1;i++) g[i].clear();
	for(int i=1;i<=n;i++) cin >> b[i], g[b[i]].push_back(i);

	if(b[1] == 0 || b[n] == n+1 ) {
		if(b[1] == 0) cout << 0 << '\n';
		else cout << n << '\n';
		for(int i=1;i<=n;i++) cout << i << ' ';
		cout << endl;
		return;
	}

	k = 1;
	while(k < n && b[k] > k) k++;
	k--;

	ans.clear();
	for(int i=1;i<=n;i++) {
		if(b[i] == 0 || b[i] == n+1) {
			bfs(b[i]);
			break;
		}
	}

	cout << k << '\n';
	for(int i=1;i<ans.size();i++) cout << ans[i] << ' ';
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
