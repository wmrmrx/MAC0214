#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int uint64_t
#define all(v) v.begin(), v.end()

void solve() {
	int n; cin >> n;
	int x; cin >> x;
	vector<pair<int,int>> v(n);
	for(auto &[a,b]: v) cin >> a >> b;

	vector<int> pre(n);
	pre[0] = v[0].first + v[0].second;
	for(int i=1;i<n;i++) pre[i] = pre[i-1] + v[i].first + v[i].second;

	int ans = numeric_limits<int>::max();

	for(int i=0;i<n;i++) {
		ans = min(ans, pre[i] + (x-(i+1)) * v[i].second);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
