#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr size_t MAX = 200'001, LOG = 30;

bool alt[2][LOG];

bool _get(int x, int l) {
	return (1<<l)&x;
}

void solve() {
	int n, c; cin >> n >> c;

	int x = c;

	for(int b: {0, 1}) for(int l=0;l<30;l++) alt[b][l] = b;

	for(int i=1;i<=n;i++) {
		int t, a; cin >> t >> a;
		for(int b: {0, 1}) for(int l=0;l<30;l++) {
			if(t == 1) {
				alt[b][l] = alt[b][l] and _get(a, l);
			} else if(t == 2) {
				alt[b][l] = alt[b][l] or _get(a, l);
			} else {
				alt[b][l] = alt[b][l] xor _get(a, l);
			}
		}

		int new_x = 0;
		for(int l=0;l<30;l++) {
			int b = _get(x, l);
			if(alt[b][l]) new_x += (1<<l);
		}
		x = new_x;
		cout << x << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
