#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

int len(int x) {
	int res = 0;
	while(x) {
		x /= 10;
		res++;
	}
	return res;
}

void solve() {
	int n; cin >> n;
	multiset<int> a, b;
	vector<int> cnt(10);
	vector<int> rem(10);
	for(int i=0;i<n;i++) {
		int x; cin >> x;
		a.insert(x);
	}
	for(int i=0;i<n;i++) {
		int x; cin >> x;
		if(a.find(x) != a.end()) {
			a.erase(a.find(x));
		} else {
			b.insert(x);
		}
	}

	int ans = 0;
	for(int x: a) {
		if(len(x) > 1) {
			x = len(x);
			ans++;
		} 
		cnt[x]++;
	}
	for(int x: b) {
		if(len(x) > 1) {
			x = len(x);
			ans++;
		} 
		rem[x] ++;
	}

	for(int i=2;i<10;i++) {
		int mn = min(rem[i], cnt[i]);
		rem[i] -= mn; cnt[i] -= mn;
		int mx = max(rem[i], cnt[i]);
		ans += mx;
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
