#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(),v.end()

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	int neg = 0, pos = 0;
	for(int x: a) {
		if(x < 0) neg += -x;
		else pos += x;
	}
	cout << max(pos-neg, neg-pos) << '\n';
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
