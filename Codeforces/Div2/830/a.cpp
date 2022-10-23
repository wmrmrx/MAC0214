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
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin >> a[i];
	int acc = a[1];
	for(int i=2;i<=n;i++) acc = __gcd(acc, a[i]);

	if(acc == 1) {
		cout << 0 << endl;
		return;
	}

	set<pair<int, int>> cur;
	cur.emplace(acc, 0);
	set<pair<int,int>> nxt;

	for(int i=n;i>=1;i--) {
		int cost = n - i + 1;
		vector<pair<int,int>> nxt;
		for(auto [num, c]: cur) {
			nxt.emplace_back(__gcd(num, i), c + cost);
		}
		for(auto p: nxt) 
			cur.insert(p);
	}
	cout << cur.begin()->second << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
