#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

vector<pair<int,int>> dxy;

pair<int,int> operator+(pair<int,int> a , pair<int,int> b) {
	return pair<int,int>{a.first + b.first, a.second + b.second};
}

int sq(int x) {
	if(x == 0) return x;
	int lo = 1, hi = x;
	while(lo < hi) {
		int mid = (lo+hi)/2;
		if(mid*mid < x) lo = mid+1;
		else hi = mid;
	}
	return lo;
}

constexpr size_t MAX = 401;

int vis[MAX][MAX];
int n, m; 
bool ok(int x, int y) {
	return 1 <=x && x <= n && 1 <= y && y <= n;
}

void bfs() {
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) vis[i][j] = -1;
	vis[1][1] = 0;
	queue<pair<int,int>> q;
	q.push(pair<int,int>{1,1});
	while(!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();
		for(pair<int,int> d: dxy) {
			for(auto dx: {-1, 1}) for(auto dy: {-1, 1}) {
				pair<int,int> p = cur + pair<int,int>{d.first*dx, d.second*dy};
				if(ok(p.first, p.second) && vis[p.first][p.second] == -1) {
					vis[p.first][p.second] = vis[cur.first][cur.second] + 1;
					q.push(p);
				}
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for(int i=0;i*i<=m;i++) {
		int j2 = m - i*i;
		int j = sq(j2);
		if(j*j != j2) continue;
		dxy.emplace_back(i, j);
	}
	bfs();
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cout << vis[i][j] << ' ';
		}
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
