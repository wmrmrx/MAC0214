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
	vector<int> ans;

	for(int msk=n;msk>0;msk=(msk-1)&n) {
		ans.push_back(msk);
	}
	ans.push_back(0);
	reverse(all(ans));
	for(int i: ans) cout << i << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
