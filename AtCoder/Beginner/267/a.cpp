#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void solve() {

	map<string, int> mp;
	mp["Monday"] = 5;
	mp["Tuesday"] = 4;
	mp["Wednesday"] = 3;
	mp["Thursday"] = 2;
	mp["Friday"] = 1;

	string s;
	cin >> s;
	cout << mp[s] << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
