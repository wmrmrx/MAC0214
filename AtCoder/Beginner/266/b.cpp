#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(), v.end()

void dbg_out() {cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << h << ' '; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':'; dbg_out(__VA_ARGS__);}

int MOD = 998244353;

void solve() {
	int n; cin >> n;
	n = n%MOD;
	if(n < 0) n+=MOD;
	cout << n << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
