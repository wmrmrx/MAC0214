#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()


void solve() {
	int n;  cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	
	vector<int> ans(n);

	vector<int> v(all(a));
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());

	for(int x: a) {
		int leq = lower_bound(all(v), x) - v.begin() + 1;
		int ge = v.size() - leq;
		ans[ge]++;
	}

	for(int x: ans) cout << x << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
