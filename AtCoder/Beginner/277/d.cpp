#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int n, m; cin >> n >> m;
	map<int, int> mp;
	int sum = 0;
	for(int i=0;i<n;i++) {
		int x; cin >> x;
		mp[x] += 1;
		sum += x;
	}

	int ans = 0;
	while(!mp.empty()) {
		int cnt = 0;
		auto [p, b] = *mp.begin();
		mp.erase(mp.begin());

		cnt += p*b;

		for(int i=(p+1)%m;mp.find(i) != mp.end();i=(i+1)%m) {
			cnt += i*mp[i];
			mp.erase(mp.find(i));
		}
		for(int i=(p-1+m)%m;mp.find(i) != mp.end();i=(i-1+m)%m) {
			cnt += i*mp[i];
			mp.erase(mp.find(i));
		}

		ans = max(ans, cnt);
	}

	cout << sum - ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
