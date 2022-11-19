#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	map<int,int> diff;
	int gls = 0;
	for(int i=0;i<n;i++) diff[i] = a[i];
	int q; cin >> q;
	while(q--) {
		int t; cin >> t;
		if(t == 1) {
			int xq; cin >> xq;
			diff.clear();
			gls = xq;
		} else if(t == 2) {
			int iq, xq;
			cin >> iq >> xq;
			diff[iq-1] += xq;
		} else if(t == 3) {
			int iq; cin >> iq;
			cout << diff[iq-1] + gls << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
