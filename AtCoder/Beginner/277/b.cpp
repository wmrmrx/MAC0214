#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int n; cin >> n;
	vector<string> s(n);
	for(auto &xs: s) cin >> xs;
	
	sort(all(s));
	s.resize(unique(all(s)) - s.begin());
	if(s.size() < n) {
		cout << "No" << endl;
		return;
	}

	for(auto &xs: s) {
		char c = xs[0];
		if(!(c == 'H' || c == 'D' || c == 'C' || c == 'S')) {
			cout << "No" << endl;
			return;
		}
		c = xs[1];
		if( !( ('2' <= c && c <= '9') || c == 'A' || c == 'T' || c == 'J' || c == 'Q' || c == 'K') ) {
			cout << "No" << endl;
			return;
		}
	}

	cout << "Yes" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
