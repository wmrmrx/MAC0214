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
	vector<int> even, odd;
	for(int i=0;i<n;i++) {
		int x; cin >> x;
		if(x%2) {
			odd.push_back(x);
		} else {
			even.push_back(x);
		}
	}
	sort(all(odd));
	sort(all(even));
	int ans = -1;
	if(odd.size() > 1) {
		ans = max(ans, odd[odd.size()-2] + odd.back());
	}
	if(even.size() > 1) {
		ans = max(ans, even[even.size()-2] + even.back());
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
