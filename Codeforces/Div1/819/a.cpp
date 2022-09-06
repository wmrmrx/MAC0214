#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	if(n == 1) {
		cout << 0 << endl;
		return;
	}
	int mn = *min_element(a.begin(), a.end()-1);
	int mx = *max_element(a.begin()+1, a.end());
	int ans = a[n-1] - a[0];
	for(int i=0;i<n-1;i++) {
		ans = max(ans, a[i]-a[i+1]);
	}
	ans = max({ans, mx-a[0], a[n-1]-mn});
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
