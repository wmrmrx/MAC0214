#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

static int MOD;

struct Z {
	int64_t x;
	Z(int64_t x=0): x(x%MOD < 0 ? x%MOD+MOD : x%MOD) {}
	Z operator+(Z rhs) { int64_t res = x + rhs.x; if(res >= MOD) res -= MOD; return Z{res}; }
	Z operator-(Z rhs) { int64_t res = x - rhs.x; if(res <0) res += MOD; return Z{res}; }
};

map<array<int, 3>, Z> mp;

Z brute(int p, int s, int m, int i = 2) {
	if(p - s
	auto it = mp.find({p,s,m});
	if(it != mp.end()) return *it;
}

void solve() {
	int n; cin >> n >> MOD;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
