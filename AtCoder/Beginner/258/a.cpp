#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int k; cin >> k;
	int h, m;
	h = 21; m = 0;
	while(k--) {
		m += 1;
		if(m == 60) {
			m = 0;
			h += 1;
		}
	}
	cout << h << ':';
	if(m < 10) cout << 0;
	cout << m << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
