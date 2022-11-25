#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

bool a[MAX][MAX];

void solve() {
	int n; cin >> n;
	for(int i=0;i<n;i++) {
		string s; cin >> s;
		for(int j=0;j<n;j++) a[i][j] = s[i][j] == '1';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
