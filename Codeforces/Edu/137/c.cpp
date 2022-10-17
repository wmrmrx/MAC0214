#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()


constexpr int INF = 1e10;

void solve() {
	int n; cin >> n;
	vector<bool> cover(n);
	{
		string s; cin >> s;
		for(int i=0;i<n;i++) {
			cover[i] = (s[n-1-i] == '1');
		}
	}

	vector<int> a(n);
	for(int &x: a) cin >> x;
	reverse(all(a));

	vector<array<int, 2>> dp(n, array<int, 2>{-INF, -INF});

	if(cover[0]) {
		dp[0][0] = a[0];
		dp[0][1] = 0;
	} else {
		dp[0][0] = 0;
	}

	for(int i=1;i<n;i++) {
		auto& cur = dp[i];
		auto& ant = dp[i-1];
		if(cover[i]) {
			cur[0] = a[i] + max(ant[0], ant[1]);
			cur[1] = max(a[i] + ant[1], ant[0]);
		} else {
			cur[0] = max(a[i] + ant[1], ant[0]);
		}
	}
	cout << max<int>(0, max(dp.back()[0], dp.back()[1])) << endl;
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
