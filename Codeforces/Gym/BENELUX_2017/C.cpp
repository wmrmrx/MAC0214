#pragma GCC optimize ("Ofast") 
#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

template <typename T> struct RMQ {
	vector<vector<T>> dp;
	T ops(T a, T b) { return __gcd(a, b); }
	RMQ() {}
	RMQ(vector<T> v) {
		int n = v.size();
		int log = 32 - __builtin_clz(n);
		dp.assign(log, vector<T>(n));
		copy(all(v), dp[0].begin());
		for(int l=1;l<log;l++) for(int i=0;i<n;i++) {
			auto &cur = dp[l], &ant = dp[l-1];
			cur[i] = ops(ant[i], ant[min(i+(1<<(l-1)), n-1)]);
		}
	}
	T query(int a, int b) {
		if(a == b) return dp[0][a];
		int p = 31-__builtin_clz(b-a);
		auto &cur = dp[p];
		return ops(cur[a], cur[b-(1<<p)+1]);
	}
};

const int N = 5e5 + 10;

int n;

void solve() {
	cin >> n;
	vector<ll> a (n);
	for (auto &u : a) cin >> u;

	RMQ<ll> rmq (a);
	
	unordered_map<ll, int> ans;
	for (int i = 0; i < n; i++) {
		// temos que achar o ultimo que eh igual

		ll last = a[i]; int j = i;
		while (j <= n) {
			ans[last]++;
			int ini = j, fim = n;
			while (ini <= fim) {
				int meio = (ini + fim) / 2;
				if (rmq.query (i, meio) == last) ini = meio + 1;
				else fim = meio - 1;
			}
			if (ini <= n) last = rmq.query (i, ini);
			j = ini;
		}
	}
	cout << ans.size () << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
