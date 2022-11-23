#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() {cerr <<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){ cerr << ' ' << h; dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

// l, r, any
map<string, array<int, 3>> mp;

void solve() {
	int n; cin >> n;
	for(int i=0;i<n;i++) {
		string type, fit; int num;
		cin >> type >> fit >> num;
		int f = -1;
		if(fit == "left") f = 0;
		if(fit == "right") f = 1;
		if(fit == "any") f = 2;
		mp[type][f] += num;
	}
	int ans = 0;
	bool possible = false;
	for(auto &[_type, arr] : mp ) {
		auto [l, r, any] = arr;
		if(l > 0 && (any + r > 0)) possible = true;
		if(r > 0 && (any + l > 0)) possible = true;
		if(any > 1) possible = true;
		ans += max<int>({1, l, r});
	}
	if(possible) cout << ans + 1 << '\n';
	else cout << "impossible" << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
