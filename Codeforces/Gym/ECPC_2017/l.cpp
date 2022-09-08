#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	cout << n-1 << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("lazy.in", "r", stdin);
	int t;
	cin >> t;
	for(int i=1;i<=t;i++) {
		cout << "Case " << i << ": ";
		solve();
	}
}