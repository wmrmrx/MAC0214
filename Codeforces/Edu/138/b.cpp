#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;

	if(n == 1) {
		cout << a[0] << endl;
		return;
	}

	int ans = accumulate(all(a), 0LL) + 2*accumulate(all(b), 0LL);

	vector<int> suf(n), pre(n);

	partial_sum(all(b), pre.begin());
	partial_sum(b.rbegin(), b.rend(), suf.rbegin());

	vector<int> res(n);

	for(int i=0;i<n;i++) {
		res[i] = pre[i] + suf[i];
	}

	cout << ans - *max_element(all(res)) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
