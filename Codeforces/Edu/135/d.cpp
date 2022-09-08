#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

int nim[2000][2000][3];
string s;
// 0: A, 1: D, 2: B

int brute(int l, int r, int b) {
	if(nim[l][r][b] != -1) return nim[l][r][b];
	int& res = nim[l][r][b];
	if(l > r) return res = b;
	if(r - l + 1 == 2) {
		if(s[l] == s[r]) {
			return res = b;
		} else {
			return res = 0;
		}
	}

	res = 2;

	auto calc = [&](char x, char y) -> int {
		if(x == y) return b;
		if(x < y) return 0;
		return 2;
	};

	// PICK[l]
	{
		int cur = 0;
		cur = max(cur, brute(l+1, r-1, calc(s[l], s[r])));
		cur = max(cur, brute(l+2, r, calc(s[l], s[l+1])));
		res = min(cur, res);
	}

	{
		int cur = 0;
		cur = max(cur, brute(l+1, r-1, calc(s[r], s[l])));
		cur = max(cur, brute(l, r-2, calc(s[r], s[r-1])));
		res = min(cur, res);
	}

	return res;
}

void solve() {
	cin >> s;
	int sz = s.size();
	for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) for(int b: {0,1,2}) nim[i][j][b] = -1;
	int res = brute(0, sz-1, 1);
	if(res == 0) {
		cout << "Alice";
	} else if(res == 1) {
		cout << "Draw";
	} else {
		cout << "Bob";
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
