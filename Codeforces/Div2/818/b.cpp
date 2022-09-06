#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n, k, r, c;
	cin >> n >> k >> r >> c;
	// mark all such that j%k == i;
	int sh = 0;
	while(c%k != (r+sh)%k) sh++;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		if(j%k == (i+sh)%k) cout << 'X';
		else cout << '.';
		if(j == n-1) cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
