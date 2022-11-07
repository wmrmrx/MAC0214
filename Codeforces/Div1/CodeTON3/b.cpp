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
	string s; cin >> s;
	vector<int> v(n);
	for(int i=0;i<n;i++) v[i] = s[i] == '1';

	int n0 = 0, n1 = 0;
	for(int b: v) {
		if(b == 0) n0++;
		else n1++;
	}

	int ans = n0*n1;

	for(int i=0;i<n;i++) {
		int j = i;
		while(j+1<n && v[j+1] == v[i]) j++;
		ans = max(ans, (j-i+1)*(j-i+1));
		i = j;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}

