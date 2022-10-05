#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(v) v.begin(), v.end()

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr size_t MAX = 1e6+10;

int s[MAX];
set<pair<int,int>> ord;

void add(array<int,3> p) {
	auto [x, y, v] = p;
	ord.erase({s[y], y});
	s[y] += v;
	ord.insert({s[y], y});
}

void rm(array<int,3> p) {
	auto [x, y, v] = p;
	ord.erase({s[y], y});
	s[y] -= v;
	ord.insert({s[y], y});
}

void solve() {
	int n; cin >> n;

	int total = 0;

	vector<array<int, 3>> pts(n);

	set<int> posx, posy;

	for(auto& [x,y,v]: pts) cin >> x >> y >> v;

	for(auto [x,y,v]: pts) { posx.insert(x), posy.insert(y), total += v; }
	if(posx.size() <= 3 || posy.size() <= 3) {
		cout << total << endl;
		return;
	}

	auto routine = [&]() -> int {
		sort(all(pts));

		memset(s, 0, sizeof(s));

		for(auto &[x,y,v]: pts) {
			s[y] += v;
		}
		ord.clear();
		for(int y=0;y<MAX;y++) {
			ord.insert({s[y], y});
		}
		int ans = ord.rbegin()->first + next(ord.rbegin())->first + next(next(ord.rbegin()))->first;

		vector<bool> vis(n, false);
		for(int i=0;i<n;) {
			int xsum = 0;
			int x = pts[i][0];
			int j;
			for(j=i;j<n && pts[j][0] == x;j++) {
				vis[j] = 1; 
				rm(pts[j]);
			       	xsum += pts[j][2];
			}

			ans = max(ans, xsum + ord.rbegin()->first + next(ord.rbegin())->first);

			for(int k=i;k<j;k++)
			add(pts[k]);

			i = j;
		}
		return ans;
	};

	int ans = routine();
	for(auto &[x,y,v]: pts) swap(x,y);
	ans = max(ans, routine());

	cout << ans << endl;

}

signed main() {
	ios::sync_with_stdio(false);  cin.tie(0);
	solve();
}
