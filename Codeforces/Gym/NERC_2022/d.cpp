#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

void dbg_out() {cerr << endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr <<' '<< h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

using cubo = array<array<int, 2>, 3>;

int n;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, -1, 0};

inline void sw(array<int, 2> &a) {
	swap(a[0], a[1]);
}
inline void sw(array<int, 2> &a, array<int,2> &b) {
	swap(a,b);
}

inline cubo tr(cubo c, const int k) {
	if(k == 0) {
		sw(c[0]);
		sw(c[0], c[1]);
	} else if(k == 1) {
		sw(c[0]);
		sw(c[0], c[2]);
	} else if(k == 2) {
		sw(c[1]);
		sw(c[0], c[1]);
	} else {
		sw(c[2]);
		sw(c[0], c[2]);
	}	
	return c;
}

bool ok(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void solve() {
	cin >> n;
	vector<vector<int>> col(n, vector<int>(n));
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> col[i][j];
	set<tuple<cubo, int, int>> vis;
	vector<tuple<cubo, int, int>> q;
	cubo ini;
	for(int i=0;i<3;i++) for(int j=0;j<2;j++) ini[i][j] = -1;
	ini[0][0] = col[0][0];
	vis.emplace(ini, 0, 0);
	q.emplace_back(ini, 0, 0);
	while(!q.empty()) {
		auto [c, x, y] = q.back();
		if(x == n-1 && y == n-1) {
			cout << "Yes" << endl;
			return;
		}
		q.pop_back();
		for(int k=0;k<4;k++) {
			int px = x + dx[k], py = y + dy[k];
			if(!ok(px, py)) continue;
			cubo pc = tr(c, k);
			if(pc[0][0] != -1 && pc[0][0] != col[px][py]) continue;
			pc[0][0] = col[px][py];
			auto [ign, found] = vis.emplace(pc, px, py);
			if(found) {
				q.emplace_back(pc, px, py);
			}
		}
	}
	cout << "No" << endl;

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
}
