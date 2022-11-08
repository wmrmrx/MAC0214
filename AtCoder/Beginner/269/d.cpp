#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, -1, 1, 0, 1};

constexpr size_t MAX = 2001;

bool vis[MAX][MAX];
bool black[MAX][MAX];

bool ok(int x, int y) {
	return 0 <= x && x < MAX && 0 <= y && y < MAX && black[x][y];
}

void dfs(int x, int y) {
	vis[x][y] = 1;
	for(int k=0;k<6;k++) {
		int px = x + dx[k], py = y + dy[k];
		if(ok(px, py) && !vis[px][py]) {
			dfs(px, py);
		}
	}
}

void solve() {
	int n; cin >> n;
	vector<pair<int,int>> v(n);
	for(auto &[x, y]: v) {
		cin >> x >> y;
		x += 1000;
		y += 1000;
		black[x][y] = 1;
	}

	int ans = 0;
	for(auto [x, y]: v) if(!vis[x][y]) {
		ans++;
		dfs(x,y);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
