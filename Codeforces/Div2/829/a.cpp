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
	int q = 0, a = 0;
	for(int i=0;i<n;i++) {
		if(s[i] == 'Q') q++;
		else a++;
		if(a >= q) {
			q = 0; a = 0;
		}
	}
	cout << (a >= q ? "Yes" : "No")<< endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
