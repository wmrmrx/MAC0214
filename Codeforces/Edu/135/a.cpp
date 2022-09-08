#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++) {
		int x; cin >> x;
		a[i] = {x, i+1};
	}

	auto rm = [&]() {
		sort(a.rbegin(), a.rend());
		while(!a.empty() && a.back().first == 0) a.pop_back();
		sort(all(a));
	};

	auto take = [&]() {
		sort(all(a));
		int sz = a.size();
		int mn = min(a[sz-1].first, a[sz-2].first);
		a[sz-1].first -= mn;
		a[sz-2].first -= mn;
	};

	while(a.size() > 1) {
		take();
		rm();
	}
	cout << a[0].second << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
