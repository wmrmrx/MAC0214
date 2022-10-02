#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
//#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}
#define dbg(...)

void solve() {
	int n; cin >> n;
	string t; cin >> t;
	set<int> rem;
	for(int i=0;i<26;i++) rem.insert(i);
	vector<int> g(26, -1);
	for(int i=0;i<n;i++) {
		int c = t[i] - 'a';
		if(g[c] == -1) {
			if(rem.size() == 1) {
				g[c] = *rem.begin();
			}
			for(auto it: rem) {
				if(g[it] == -1) {
					g[c] = it;
					break;
				}
			}
			rem.erase(g[c]);
		}
		t[i] = g[c] + 'a';
	}
	cout << t << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
	solve();
}
