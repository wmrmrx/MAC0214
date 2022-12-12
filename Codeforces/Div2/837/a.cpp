#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	sort(all(a));
	int d = *max_element(all(a)) - *min_element(all(a));
	if(d == 0) {
		cout << n * (n-1) << endl;
		return;
	}
	else {
		int l = 0, r = n-1;
		int cl = 1, cr = 1;
		while(l+1 < n && a[l+1] == a[0]) l++, cl++;
		while(r-1 >= 0 && a[r-1] == a[n-1]) r--, cr++;
		cout << 2 * cl * cr << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
