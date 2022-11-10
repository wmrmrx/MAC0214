#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(),v.end()

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &i: a) cin >> i;

	if(a[0] == *min_element(all(a))) {
		cout << "bob" << '\n';
	} else {
		cout << "alice" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
