#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int n; cin >> n;
	vector<bool> marc(10);
	for(int i=0;i<n;i++) {
		int d;
		cin >> d;
		marc[d] = 1;
	}
	int rem = 10 - n;
	cout << (rem * (rem-1) / 2) *6 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
