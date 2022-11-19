#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

int n;
vector<int> g[16];
bool vis[1<<16][16];
// 1 if who plays win
bool dp[1<<16][16];

bool wins(int mask, int last) {
	if(vis[mask][last]) return dp[mask][last];
	vis[mask][last] = 1;
	bool &cur = dp[mask][last];
	cur = false;
	for(int next: g[last]) if( (mask & (1<<next)) == 0 ) {
		if( ! wins( mask | (1<<next) , next ) ) {
			cur = true;
		}
	}
	return cur;
}

void solve() {
	cin >> n;
	vector<string> s(n);
	for(auto &xs: s) cin >>xs;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i != j) {
		if(s[i].back() == s[j][0]) {
			g[i].push_back(j);
		}
	}

	bool ans = 0;
	for(int i=0;i<n;i++) {
		if( ! wins(1<<i, i) ) {
			ans = 1;
		}
	}

	cout << (ans ? "First" : "Second") << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
