#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int MAXN = 4e5 + 10;
int MOD = 1;

struct Z {
	int64_t x;
	Z(int64_t x=0): x(x) {}
	Z operator+(Z rhs) { int64_t res = x + rhs.x; if(res >= MOD) res -= MOD; return Z{res}; }
	Z operator-(Z rhs) { int64_t res = x - rhs.x; if(res <0) res += MOD; return Z{res}; }
	Z operator*(Z rhs) { return Z{x * rhs.x % MOD}; }
    Z operator/(Z rhs) { return (*this) * rhs.inv(); }
    Z inv() { return this->fexp(MOD-2); }
    bool operator == (Z zhs) {return x == zhs.x;}

    Z fexp(int e) {
        Z res = Z(1);
        for(Z copy=*this;e>0;e/=2,copy=copy*copy) if(e&1) res = res * copy;
        return res;
    }
};

Z ans[MAXN];
Z fat[MAXN], inv[MAXN];

void init() {
    fat[0] = inv[0] = Z(1);
    for(int i=1;i<MAXN;i++) {
        fat[i] = fat[i-1] * Z{i};
        inv[i] = fat[i].inv();
    }
}
int n;

Z baixo = Z(1);
int M[MAXN];

void backtracking(int quant, int last, int P, int S) {
    if(quant + P - S > n) return;
    if(P >= S) {
        int x1 = P - S;
        Z cima = fat[quant + x1];
        Z bbaixo = inv[x1] * baixo;
        // dbg (quant + x1, cima.x, baixo.x);
        // if (quant + x1 == 5) {
        //     dbg (x1, quant, last, P, S, cima.x, bbaixo.x, (cima / bbaixo).x, M[2], baixo.x);
        // }
        ans[quant + x1] = ans[quant + x1] + cima * bbaixo;
    }
    for(int x = last; P * x - (S + x) + quant + 1 <= n; x++) {
        if (quant == 0 && x * x > 2 * n) break;
        if (M[x]) baixo = baixo * fat[M[x]];
        M[x]++;
        baixo = baixo * inv[M[x]];
        backtracking(quant + 1, x, P*x, S+x);
        baixo = baixo * fat[M[x]];
        M[x]--;
        if (M[x]) baixo = baixo * inv[M[x]];
    }
}

void solve () {
    cin >> n >> MOD;
    init ();
    backtracking (0, 2, 1, 0);
    for (int i = 2; i <= n; i++)
        cout << ans[i].x << " ";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
