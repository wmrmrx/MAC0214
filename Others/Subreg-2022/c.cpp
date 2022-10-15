#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr int MAX = 1005;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n;

int blkx[MAX][MAX];
int blky[MAX][MAX];

bool marc[MAX][MAX];

bool ok(int x, int y) {
	return x >= 0 && y >= 0 && x < MAX && y < MAX;
}

int BFS(int bx, int by) {
	queue<pair<int,int>> q;
	q.push({bx, by});
	marc[bx][by] = true;
	int cnt = 0;
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		cnt++;
		for(int k=0;k<4;k++) {
			int px = x + dx[k];
			int py = y + dy[k];
			if(!ok(px, py) || marc[px][py]) continue;
			if(dx[k]) {
				if(dx[k] == 1) {
					if(blkx[x+1][y]) {
						continue;
					 }
				} else {
					if(blkx[x][y]) {
						continue;
					 }
				}
			}
			if(dy[k]) {
				if(dy[k] == 1) {
					if(blky[y+1][x]) {
						continue;
					}
				} else {
					if(blky[y][x]) {
						continue;
					}
				}
			}
			marc[px][py] = true;
			q.push({px, py});
		}
	}
	return cnt;
}

void solve() {
	cin >> n;
	int x, y;
	cin >> x >> y;
	for(int i=1;i<=n;i++) {
		int px, py;
		cin >> px >> py;
		if(px == x) {
			blkx[x][min(y,py)]++;
			blkx[x][max(y,py)]--;
		} else {
			blky[y][min(x,px)]++;
			blky[y][max(x,px)]--;
		}
		x = px; y = py;
	}

	for(int i=0;i<MAX;i++) {
		for(int j=1;j<MAX;j++) {
			blkx[i][j] += blkx[i][j-1];
			blky[i][j] += blky[i][j-1];
		}
	}

	int ans = 0;
	for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) if(!marc[i][j]) {	
		int res = BFS(i, j);
		if(i != 0 && j != 0) {
			ans = max(ans, res);
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
