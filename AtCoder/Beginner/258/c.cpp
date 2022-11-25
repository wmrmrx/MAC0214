#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int n, q; cin >> n >> q;
	string s; cin >> s;

	int acc = 0;

	while(q--) {
		int t, x; cin >> t >> x;
		if(t == 1) {

			acc = (acc + x)%n;

		} else if(t == 2) {
			x--;
			cout << s[ (x - acc + n) % n ] << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
