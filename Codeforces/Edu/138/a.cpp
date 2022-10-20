#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int n, m; cin >> n >> m;
	vector<int> l(n), c(n);
	vector<pair<int,int>> r(m);
	for(auto& [x,y]: r) {
		cin >> x >> y;
		--x; --y;
		l[x]++;
		c[y]++;
	}
	for(auto &[x, y]: r) {
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i != x || j != y) {
			l[x]--;
			c[y]--;
			l[i]++;
			c[j]++;
			bool ok = true;
			for(int k=0;k<n;k++) {
				if(l[k] > 1 || c[k] > 1) {
					ok = false;
				}
			}
			if(ok) {
				cout << "YES" << endl;
				return;
			}
			l[i]--;
			c[j]--;
			l[x]++;
			c[y]++;
		}
	}
	cout << "NO" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
