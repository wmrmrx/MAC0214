#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

int ans[999999 + 1];

void solve() {
	int n; cin >> n;
	cout << ans[n] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=999999;i++) {
		int x = i;
		while(x > 9 && x%10 == 0) {
			x /= 10;
		}
		if(x <= 9) {
			ans[i]++;
		}
		ans[i] += ans[i-1];
	}
	int t; cin >> t;
	while(t--)
		solve();
}
