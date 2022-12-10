#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define all(v) v.begin(), v.end()
#define pb push_back

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 20;
bool vis[1<<N];
uint32_t num[1<<N];
int saldo[N];
int tot[1<<N];
bool ok[1<<N];

uint32_t calc(uint32_t msk) {
	if(vis[msk]) return num[msk];
	vis[msk] = 1;
	auto &res = num[msk];
	res = 1;
	for(uint32_t sub=(msk-1)&msk;sub>0;sub=(sub-1)&msk) if(ok[sub]) {
		res = max<uint32_t>(res, calc(sub) + calc(msk-sub));
	}
	return res;
}

void solve() {
	int n; cin >> n;
	{
		int foo; cin >> foo;
		while(foo--) {
			int a, b, p; cin >> a >> b >> p;
			saldo[a] += p;
			saldo[b] -= p;
		}
	}

	{
		vector<int> s;
		for(int i=0;i<n;i++) if(saldo[i] != 0) s.push_back(saldo[i]);
		n = s.size();
		for(int i=0;i<n;i++) saldo[i] = s[i];
	}

	if(n == 0) {
		cout << 0 << endl;
		return;
	}

	for(uint32_t m=0;m<(1<<n);m++) {
		for(uint32_t b=0;b<n;b++) if( (1<<b)&m ) {
			tot[m] += saldo[b];
		}
		ok[m] = tot[m] == 0;
	}

	cout << n - calc( (1<<n) - 1 ) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}

