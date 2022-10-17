#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int n; cin >> n;
	vector<int> p(n);
	iota(all(p), 1);
	swap(p[1], p[n-1]);
	for(int i: p) cout << i << ' ';
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
