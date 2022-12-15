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
	map<pair<char,char>, vector<int>> mp;
	for(int i=0;i<n-1;i++) {
		pair<char,char> p(s[i], s[i+1]);
		mp[p].push_back(i);
	}
	for(auto &[__foo, v]: mp) {
		int sz = v.size();
		if(sz > 1 && v.back() - v[0] > 1) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
