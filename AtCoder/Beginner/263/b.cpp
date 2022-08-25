#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void solve() {
	int n; cin >> n; vector<int> p(n+1);
	for(int i=2;i<=n;i++) cin >> p[i];
	int cur = n, ans = 0;
	while(cur != 1) {
		ans++;
		cur = p[cur];
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
