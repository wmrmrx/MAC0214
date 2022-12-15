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

	int ans = 0;
	for(int i=0;i<n;i++)
		if(a[i] == 0)
			ans += (i+1) * (n - i);

	vector<array<array<int, 4>, 4>> dp(n);
	dp[0][a[0]][0] = 1;
	if(a[0] != 0) {
		ans++;
	}
	for(int i=1;i<n;i++) {
		auto &cur = dp[i];
		auto &ant = dp[i-1];
		int x = a[i];
		if(x == 0) {
			cur = ant;
			cur[0][0]++;
		} else {
			for(int l=0;l<=3;l++) for(int r=0;r<=3;r++) {
				int num = ant[l][r];
				if((l == 0) || bool(l&x)) {
					cur[x][r] += num;
				} else if(r == 0 || bool(r&x)) {
					cur[l][x] += num;
				} else {
					ans += 3 * num * (n - i);
				}
			}
			cur[x][0]++;
		}
		for(int l=0;l<=3;l++) for(int r=0;r<=3;r++) {
			if(l)
				ans += cur[l][r];
			if(r) 
				ans += cur[l][r];
		}
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
