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

	int odd = n%2;
	n -= odd;

	vector<int> p(n+1);

	int d = n / 2;
	int cnt = 1;

	for(int i=n/2;i>=1;i--,cnt++) {
		p[2*cnt-1] = i;
		p[2*cnt] = i+d;
	}

	if(odd) cout << n+1 << ' ';
	for(int i=1;i<=n;i++) 
		cout << p[i] << " \n"[i==n];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
