#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() {cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	pair<int,int> v[3];
	for(int i=0;i<3;i++) {
		cin >> v[i].first;
	}
	v[0].second = 2;
	v[1].second = 1;
	v[2].second = 0;
	sort(v, v+3); reverse(v, v+3);
	int x = v[0].first, y = v[1].first, z = v[2].first;

	int inv[3];
	for(int i=0;i<3;i++) {
		inv[v[i].second] = i;
	}

	if(x > z*y) {
		cout << "-1" << endl;
		return;
	}

	vector<array<int, 3>> vx, vy, vz, extra;
	for(int i=0;i<z;i++) {
		vz.push_back({0, i, 0});
	}
	for(int i=0;i<y;i++) {
		vy.push_back({0, 0, i});
	}

	int cnt = 0;
	for(int k=1;true;k++) {
		if(y*z >= x && x >= y+z-1) {
			int rem = x - (y+z-1);
			for(int i=1;i<y;i++) for(int j=1;j<z;j++) {
				if(!rem) break;
				vx.push_back({0, j, i});
				rem--;
			}
			set<array<int, 3>> ans;
			for(auto &p: vx) ans.insert(p);
			for(auto &p: vy) ans.insert(p);
			for(auto &p: vz) ans.insert(p);

			cout << ans.size() << '\n';

			for(auto p: ans) {
				cout << p[inv[0]] << ' ' << p[inv[1]] << ' ' << p[inv[2]] << '\n';
			}

			return;
		}
		vz.pop_back();
		z--;
		vy.pop_back();
		y--;
		if(z == 0 || y == 0) {
			break;
		}
		vx.push_back({k, -k, -k});
		x--;
	}
	cout << "-1\n";

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
