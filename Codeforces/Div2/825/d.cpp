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
	vector<int> v(2*n);
	for(int i=0;i<2*n;i++) v[i] = s[i] == '1';
	if(accumulate(all(v[i]), 0LL)%2 != 0) {
		cout << -1 << endl;
		return;
	}
	queue<int> st;

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
