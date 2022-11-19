#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

map<int, set<int>> m;

void solve() {
	int n; cin >> n;
	int q; cin >> q;
	while(q--) {
		int t,a,b; cin >> t >> a >> b;
		if(t == 1) {
			m[a].insert(b);
		} else if(t == 2) {
			m[a].erase(b);
		} else {
			if(m[a].count(b) && m[b].count(a)) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
