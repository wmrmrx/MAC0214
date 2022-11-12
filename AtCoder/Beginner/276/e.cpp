#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){ cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) // { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

vector<vector<bool>> road, vis;

int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool ok(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && road[x][y];
}

void bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.emplace(x, y);
	vis[x][y] = true;
	dbg("BFS", x, y);
	while(!q.empty()) {
		auto [cx, cy] = q.front();
		dbg(cx, cy);
		q.pop();
		for(int k=0;k<4;k++) {
			int px = cx + dx[k], py = cy + dy[k];
			if(ok(px, py) && !vis[px][py]) {
				vis[px][py] = 1;
				q.emplace(px, py);
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	road.assign(n, vector<bool>(m));
	vis.assign(n, vector<bool>(m));
	int x, y;
	for(int i=0;i<n;i++) {
		string s; cin >> s;
		for(int j=0;j<m;j++) {
			char c = s[j];
			if(c == '.') {
				road[i][j] = true;
			} else if(c == 'S') {
				x  = i; y = j;
			}
		}
	}


	for(int k=0;k<4;k++) {
		int px = x + dx[k], py = y + dy[k];
		if(!ok(px, py)) continue;
		vis.assign(n, vector<bool>(m, false));
		bfs(px, py);
		for(int kk=0;kk<4;kk++) if(kk != k) {
			int ppx = x + dx[kk], ppy = y + dy[kk];
			if(ok(ppx, ppy) && vis[ppx][ppy]) {
				dbg(k, kk);
				cout << "Yes\n";
				return;
			}
		}
	}

	cout << "No" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
