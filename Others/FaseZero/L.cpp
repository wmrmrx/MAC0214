#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<":";dbg_out(__VA_ARGS__);}


// forbidden
bitset<500*500> fbx[500], fby[500];
int p[500]

int num[500][500];

void solve() {
	int n; cin >> n;
	for(int i=0;i<n;i++) {
		fbx[i].reset();
		fby[i].reset();
	}
	set<int> av;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			for(int k=0;k<n*n;k++) {
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
