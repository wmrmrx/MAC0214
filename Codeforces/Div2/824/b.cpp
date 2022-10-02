#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;

	int mn = *min_element(all(a));
	
	int ans = 0;
	for(int x: a) {
		if(x < 2*mn) continue;
		ans += (x-1)/ (2*mn - 1);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>> t;
	while(t--)
	solve();
}
