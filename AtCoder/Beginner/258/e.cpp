#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) //{ cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

constexpr size_t MAX = 200'000;
constexpr size_t LOG = 60;

int nxt[MAX];
int num[MAX];
int dp[LOG][MAX];

void solve() {
	int n, q, x; cin >> n >> q >> x;
	vector<int> w(n), sw(2*n);
	for(int &weight: w) cin >> weight;

	for(int i=0;i<n;i++) w.push_back(w[i]);
	partial_sum(all(w), sw.begin());

	auto get = [&](int l, int r) {
		return (r ? sw[r-1] : 0) - (l ? sw[l-1] : 0);
	};

	for(int i=0;i<n;i++) {
		int d = n * ( x / sw[n-1] );
		int rem = x % sw[n-1];
		dbg(rem);

		int lo = 0, hi = n;
		while(lo < hi) {
			int m = (lo + hi) / 2;
			if( get(i, i+m) >= rem ) hi = m;
			else lo = m+1;
		}

		dbg(lo, i);

		nxt[i] = (i + lo) % n;
		num[i] = d + lo;
		dbg(i, nxt[i], num[i]);
	}

	for(int i=0;i<n;i++) dp[0][i] = nxt[i];
	for(int l=1;l<LOG;l++)  {
		auto &cur = dp[l];
		auto &ant = dp[l-1];
		for(int i=0;i<n;i++) {
			cur[i] = ant[ant[i]];
		}
	}

	while(q--) {
		int k; cin >> k;
		k--;
		int cur = 0;
		for(int l=LOG-1;l>=0;l--) {
			if(k >= (1LL<<l)) {
				k -= (1LL<<l);
				cur = dp[l][cur];
			}
		}
		assert(k == 0);
		dbg(cur);
		cout << num[cur] << '\n';
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
