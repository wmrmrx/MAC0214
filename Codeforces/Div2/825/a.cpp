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
	vector<int> b(n);
	int na = 0, nb = 0;
	for(int &x: a) cin >> x, na += x;
	for(int &x: b) cin >> x, nb += x;
	int cnt =0;
	for(int i=0;i<n;i++) if(a[i] != b[i]) cnt++;
	cout << min(abs(na-nb) + 1, cnt) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
