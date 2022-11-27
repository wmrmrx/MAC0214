#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void solve() {
	int n; cin >> n;
	if(n%2 == 0) {
		cout << n/2 << ' ' << n/2 << endl;
		return;
	}
	int a = 1;
	for(int d=2;d*d<=n;d++) if(n%d == 0) {
		if(n-d < n - a) {
			a = d;
		} 
		if(max( n / d, n - n / d ) < n - a) {
			a = min(n / d, n - n / d);
		}
	}
	cout << a << ' ' << n-a << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
}
