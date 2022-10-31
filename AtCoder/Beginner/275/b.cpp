#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr int MOD = 998244353;

void solve() {
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	a %= MOD;
	b %= MOD;
	c %= MOD;
	d %= MOD;
	e %= MOD;
	f %= MOD;
	a = (a*b)%MOD;
	a = (a*c)%MOD;
	d = (d*e)%MOD;
	d = (d*f)%MOD;
	a -= d;
	if(a < 0) a += MOD;
	cout << a << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
