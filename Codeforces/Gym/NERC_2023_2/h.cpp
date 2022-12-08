#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int MAX = 1000000;

map<string, int> mp;
string query(int x, int y) {
	cout << x << ' ' << y << endl;
	string s;
	while(s.empty()) {
		getline(cin, s);
	}
}

bool found(string &s) {
	return s.back() == '!';
}

void solve() {
	string ini = query(0, 0);
	if(found(ini)) {
		return;
	}
	string sx = query(1, 0);
	if(found(sx)) {
		return;
	}
	query(0, 0);
	string sy = query(0, 1);
	if(found(sy)) {
		return;
	}

	int rx = -1, ry = -1;

	if(sx == sy) {
		mp[sx] = 1;
		mp[query(0, 0)] = -1;
	} else {
		// x == 0 or y == 0
		ini = query(MAX, 0);
		if(found(ini)) return;
		string s = query(MAX-1, 0);
		if(found(s)) return;
		mp[s] = 1;
		mp[query(MAX, 0)] = -1;
		if(s == sx) {
			ry = 0;
		} else {
			rx = 0;
		}
	}

	if(rx == -1) {
		int lo = 0, hi = 1'000'000;
		query(0, 0);
		while(lo < hi) {
			int mid = (lo + hi) / 2;
			string s = query(mid, 0);
			if(mp[s] == 1) {
			}
		}
	}

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
