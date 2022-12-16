#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	array<array<int, 2>, 3> p;
	for(int i=0;i<3;i++) cin >> p[i][0] >> p[i][1];
	bool x = true, y = true;
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(i != j) {
		if(p[i][0] == p[j][0]) {
			x = false;
		}
		if(p[i][1] == p[j][1]) {
			y = false;
		}
	}
	if(x || y) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
