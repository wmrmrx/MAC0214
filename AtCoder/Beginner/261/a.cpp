#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int col[101];

void solve() {
	int l, r; cin >> l >> r;
	for(int i=l;i<=r;i++) col[i]++;
	cin >> l >> r;
	for(int i=l;i<=r;i++) col[i]++;
	l = 0, r = 100;
	while(l <= 100 && col[l] != 2) l++;
	while(r >= 0 && col[r] != 2) r--;
	cout << max<int>(r-l, 0) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
