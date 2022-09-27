#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}

#define dbg(...) {cerr<<#__VA_ARGS__<<":";dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	if(n%2 == 1) {
		cout << 0 << endl;
		return;
	}
	int ans = 0;
	ans += (n/2)*((n-1)/2);
	if(n%4 == 0) {
		ans -= n/4;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
