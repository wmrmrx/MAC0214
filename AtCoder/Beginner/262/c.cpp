#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x, x--;

	int ans = 0;
	for(int i=0;i<n;i++) if(a[i] == i) ans++;
	ans = (ans)*(ans-1)/2;

	for(int i=0;i<n;i++) if(a[i] != i) {
		int j = a[i];
		if(i < j && a[j] == i) {
			ans++;
		}
	}

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
