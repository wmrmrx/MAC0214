#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int n; cin >>n;
	vector<int> a(n);
	for(int &x: a) cin >> x;


	sort(all(a));

	int ans = 0;

	for(int k=1;k<=n;k++) {
		multiset<int> s(all(a));
		bool ok = true;
		for(int i=1;i<=k;i++) {
			int num = k - i + 1;
			while(!s.empty() && *s.rbegin() > num) s.erase(*s.rbegin());
			if(s.empty()) {
				ok = false;
				break;
			} else {
				s.erase(s.find(*s.rbegin()));
				if(!s.empty()) {
					s.erase(s.begin());
				}
			}
		}
		if(ok) ans = max(ans, k);
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
