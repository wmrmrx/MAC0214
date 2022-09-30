#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h,T... t) { cerr << ' ' << h; dbg_out(t...); }
//#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
#define dbg(...) 

constexpr size_t MAX = 2022;

bool valid[MAX][MAX];
bool marc[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int cnt = 0;
vector<pair<int,int>> center;

void dfs(int ox, int oy) {
	queue<pair<int,int>> q;
	marc[ox][oy] = true;
	q.push({ox, oy});
	cnt = 1;
	dbg(cnt, ox, oy);
	center.clear();
	while(!q.empty()) {
		auto [x, y] = q.front();
		dbg(x, y);
		q.pop();
		int deg = 0;
		for(int k=0;k<4;k++) {
			int px = x + dx[k], py = y + dy[k];
			if(valid[px][py]) deg++;
			if(valid[px][py] && !marc[px][py]) {
				marc[px][py] = 1;
				q.push({px, py});
				cnt++;
				dbg(cnt, px, py);
			}
		}
		if(deg == 4 && center.size() <= 1) center.emplace_back(x, y);
	}
}

void solve() {
	int h, w; cin >> h >> w;
	for(int i=0;i<h;i++) {
		string s; cin >> s;
		for(int j=0;j<s.size();j++) {
			valid[i+1][j+1] = s[j] == '*';
		}
	}

	int ans = 0;
	for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) {
		if(!marc[i][j] && valid[i][j]) {
			dfs(i, j);
			if(center.size() != 1) continue;

			dbg(center.back().first, center.back().second, cnt);

			vector<int> ex(4);

			for(int k=0;k<4;k++) {
				auto [x, y] = center[0];
				while(true) {
					int px = x + dx[k], py = y + dy[k];
					if(!valid[px][py]) break;
					ex[k]++;
					x = px;
					y = py;
				}
			}

			if( ex[1] > 0 && ex[1] == ex[2] && ex[3] == ex[2] && ex[0] > ex[1]
			    && ex[0] + ex[1] + ex[2] + ex[3] + 1 == cnt ) {
				ans++;
			}
		}
	}

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
