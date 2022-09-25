#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n, c;
	cin >> n >> c;
	vector<vector<int>> v(101);
	for(int i=0;i<n;i++) {
		int x; cin >> x;
		v[x].push_back(i);
	}
	int ans = 0;
	for(int i=0;i<v.size();i++) {
		if(v[i].size() > c) {
			ans += c;
		} else {
			ans += v[i].size();
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
