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
	vector<int> b(n);
	for(int &x: b) cin >> x;

	array<vector<int>, 2> ord;
	for(int i=0;i<n;i++) {
		ord[a[i]].push_back(b[i]);
	}

	sort(all(ord[0]));
	sort(all(ord[1]));

	reverse(all(ord[0]));
	reverse(all(ord[1]));

	int s[2] = {ord[0].size(), ord[1].size()};
	if(s[0] < s[1]) {
		swap(s[0], s[1]);
		ord[0].swap(ord[1]);
	}

	// s[0] >= s[1];
	//
	if(s[1] == 0) {
		cout << accumulate(all(ord[0]), 0LL) << endl;
		return;
	}
	
	if(s[0] == s[1]) {
		int sum = 0;
		for(int i: {0, 1}) sum += accumulate(all(ord[i]), 0LL);
		int ans = 2*sum - min(ord[0].back(), ord[1].back());
		cout << ans << endl; 
		return;
	}	

	int ans = 2*accumulate(all(ord[1]), 0LL) + accumulate(all(ord[0]), 0LL);
	ans += accumulate(ord[0].begin(), ord[0].begin() + s[1], 0LL);
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
