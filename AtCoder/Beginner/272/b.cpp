#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr size_t MAX = 101;

bool same[MAX][MAX];

void solve() {
	int n; cin >> n;
	int m; cin >> m;
	for(int i=0;i<m;i++) {
		int k; cin >> k;
		vector<int> x(k);
		for(int &p: x) cin >> p;
		for(int p: x) for(int pp: x) { 
			same[p][pp] = 1;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		if(!same[i][j]) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
