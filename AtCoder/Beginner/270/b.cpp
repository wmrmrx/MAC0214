#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int x,y,z;
	cin >> x >> y >> z;
	if(x < 0) {
		x = -x;
		y = -y;
		z = -z;
	}
	if(y < 0) {
		cout << x << endl;
		return;
	}

	if(y < x) {
		if(y < z) {
			cout << -1 << endl;
		} else {
			if(z < 0) {
				cout << 2*abs(z) + x << endl;
			} else {
				cout << x << endl;
			}
		}
	} else {
		cout << x << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
