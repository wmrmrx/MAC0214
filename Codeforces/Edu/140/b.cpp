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
	int one = 0;
	cin >> one;
	if(n == 1) {
		cout << one << endl;
		return;
	}
	n--;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	sort(all(a));
	for(int h: a) {
		if(h <= one) continue;
		one += (h - one + 1) / 2;
	}
	cout << one << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
