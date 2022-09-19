#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n,x,y;
	cin >> n >> x >> y;
	if(x != 0 && y != 0) {
		cout << -1 << endl;
		return;
	}
	if(x == 0 && y == 0) {
		cout << -1 << endl;
		return;
	}
	int r = x + y;
	if((n-1)%r != 0) {
		cout << -1 << endl;
		return;
	}
	int d = r;
	int w = 0;
	int cur = 1;
	for(int i=0;i<n-1;i++) {
		if(w < d) {
			w++;
			cout << cur  << ' ';
		} else {
			w = 1;
			cur = i;
			cout << cur << ' ';
		}
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
