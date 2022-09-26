#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void solve() {
	int n; cin >> n; 
	n++;
	vector<int> a(n), b(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;
	reverse(all(a));
	a.push_back(0);
	reverse(all(b));
	int ans = 0;
	for(int i=0;i<n;i++) {
		if(a[i] >= b[i]) continue;
		int d = b[i] - a[i];
		int need = (d+1)/2;
		ans += need;
		a[i+1] -= need;
	}
	if(a[n] == 0) {
		cout << ans << '\n';
	} else {
		cout << -1 << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
