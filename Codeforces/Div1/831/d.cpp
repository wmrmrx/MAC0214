#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n,m,k; cin >> n >> m >> k;
	vector<int> a(k);
	for(int &x: a) cin >> x, x--;
	set<int> taken;
	int mx = k-1;
	for(int v: a) {
		taken.insert(v);
		if(taken.size() == n*m-2) {
			cout << "TIDAK" << '\n';
			return;
		}
		while(!taken.empty() && *taken.rbegin() == mx) {
			taken.erase(*taken.rbegin());
			mx--;
		}
	}
	if(taken.empty()) {
		cout << "YA" << '\n';
	} else {
		cout << "TIDAK" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
