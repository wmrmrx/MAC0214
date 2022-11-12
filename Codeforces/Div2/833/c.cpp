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
	vector<int> a(n), pre(n);
	for(int &i: a) cin >> i;
	partial_sum(all(a), pre.begin());
	vector<int> occ;
	for(int i=0;i<n;i++) if(a[i] == 0) {
		occ.push_back(i);
	}
	
	if(occ.empty()) {
		int ans = 0;
		for(int i=0;i<n;i++) {
			if(pre[i] == 0) {
				ans++;
			}
		}
		cout << ans << '\n';
		return;
	}

	int ans = 0;
	for(int i=0;i<occ[0];i++) {
		if(pre[i] == 0) {
			ans++;
		}
	}

	for(int p=0;p<occ.size();p++) {
		int l = occ[p], r = (p == occ.size()-1 ? n : occ[p+1]);
		map<int,int> cnt;
		for(int i=l+1;i<r;i++) {
			cnt[pre[i]-pre[l]]++;
		}
		int mx = 1;
		for(auto [sum, qtd]: cnt) {
			mx = max(mx, qtd + (sum == 0));
		}
		ans += mx;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
