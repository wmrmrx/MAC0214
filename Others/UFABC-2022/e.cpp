#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void solve() {
	int n; cin >> n;
	vector<vector<char>> v(n);
	for(int i=0;i<n;i++) {
		string s; cin >> s;
		v[i].reserve(s.size());
		for(char c: s) v[i].push_back(c);
		sort(all(v[i]));
	}

	sort(all(v));

	int ans = 0;

	int l = 0;
	while(l < n) {
		int r = l;
		while(r+1 < n && v[l] == v[r+1]) {
			r++;
		}
		int sz = r-l+1;
		ans += sz*(sz-1)/2;
		l = r+1;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}

