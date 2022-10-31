#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	vector<string> s(9);
	for(auto &i: s) cin >> i;
	auto ok = [&](int x, int y) {
		return 0 <= x && x < 9 && 0 <= y && y < 9 && s[x][y] == '#';
	};

	int ans = 0;
	for(int i=0;i<9;i++) for(int j=0;j<9;j++) {
		for(int kx=-9;kx<9;kx++) for(int ky=-9;ky<9;ky++) if(kx || ky) {
			bool sq = true;
			int x = i, y = j;
			int dx = kx, dy = ky;
			for(int k=0;k<4;k++) {
				if(!ok(x,y)) {
					sq = false;
					break;
				}
				x += dx;
				y += dy;
				swap(dx, dy);
				dx = -dx;
			}
			if(sq) {
				ans++;
			}

		}
	}
	cout << ans / 4<< endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
