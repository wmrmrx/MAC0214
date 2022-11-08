#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int int64_t
#define all(v) v.begin(), v.end()

/*
    NTT - Number Theoretic Transform
    Description: Multiply two polinomials in Z_p, for p prime
    Complexity: O(N logN)
    Functions:
        multiply(a, b)
    Details:
        Not all primes can be used and p = 998244353 is the most used prime.
        To multiply it for a general modulus, use 3 different possible primes
        and use Chinese Remainder Theorem to get the answear.
    Possibilities
    { 7340033, 5, 4404020, 1 << 20 },
    { 415236097, 73362476, 247718523, 1 << 22 },
    { 463470593, 428228038, 182429, 1 << 21},
    { 998244353, 15311432, 469870224, 1 << 23 },
    { 918552577, 86995699, 324602258, 1 << 22 }
    98bcfc
*/

using ll = int;

namespace NTT {
    const ll mod = 998244353, root = 15311432, root_1 = 469870224, root_pw = 1 << 23;

    ll fastxp(ll n, ll e){
        ll ans = 1, pwr = n;
        while(e){
            if(e%2)  ans = ans * pwr % mod;
            e /= 2;
            pwr = pwr * pwr % mod;
        }
        return ans % mod;
    }


    void fft(vector<ll> & a, bool invert) {
        ll n = a.size();

        for (ll i = 1, j = 0; i < n; i++) {
            ll bit = n >> 1;
            for (; j & bit; bit >>= 1)
                j ^= bit;
            j ^= bit;

            if (i < j) swap(a[i], a[j]);
        }

        for (ll len = 2; len <= n; len <<= 1) {
            ll wlen = invert ? root_1 : root;
            for (ll i = len; i < root_pw; i <<= 1)
                wlen = wlen * wlen % mod;

            for (ll i = 0; i < n; i += len) {
                ll w = 1;
                for (ll j = 0; j < len / 2; j++) {
                    ll u = a[i+j], v = a[i+j+len/2] * w % mod;
                    a[i+j] = u + v < mod ? u + v : u + v - mod;
                    a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                    w = w * wlen % mod;
                }
            }
        }

        if (invert) {
            ll n_1 = fastxp(n, mod - 2);
            for (ll & x : a) x = x * n_1 % mod;
        }
    }

    vector<ll> multiply(vector<ll> &a, vector<ll> &b) {
        vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        ll sz = a.size() + b.size() - 1, n = 1;
        while (n < sz) n <<= 1;

        fa.resize(n), fb.resize(n);
        fft(fa, 0), fft(fb, 0);
        for (ll i = 0; i < fa.size(); i++) fa[i] = fa[i] * fb[i] % mod;

        fft(fa, 1);
        fa.resize(sz);
        return fa;
    }
};

constexpr int MOD = 998244353;
constexpr size_t MAX = 200'000;
vector<int> g[MAX];
vector<int> poly[MAX];

void dfs(int v) {
	if(g[v].empty()) {
		poly[v].clear();
		poly[v].push_back(1);
		poly[v].push_back(1);
		return;
	}

	dfs(g[v].back());
	poly[v] = move(poly[g[v].back()]);
	g[v].pop_back();

	for(int p: g[v]) {
		dfs(p);
		poly[v] = NTT::multiply(poly[v], poly[p]);
		poly[p].clear();
	}

	poly[v][1] += 1;
	if(poly[v][1] == MOD) poly[v][1] = 0;
}

void solve() {
	int n; cin >> n;
	for(int i=1;i<n;i++) {
		int dad; cin >> dad;
		g[dad-1].push_back(i);
	}
	dfs(0);
	auto &v = poly[0];
	int sz = v.size();
	for(int i=1;i<sz;i++) cout << v[i] << '\n';
	for(int i=sz;i<=n;i++) cout << "0\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
