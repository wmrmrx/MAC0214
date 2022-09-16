#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<":";dbg_out(__VA_ARGS__);}

const int MAXN = 2e5+5;
const int MOD =  1e9+7;
int N, M, a, b, K;
int acumul[MAXN];

int calc(int c, int d) {
    int ans = min(c / a, N);
    ans *= min(d / b, M);
    return (N*M) - ans;
}

int expo(int val, int e) {
    if (e == 0) return 1;
    if (e == 1) return val % MOD;
    if (e&1) return (val*expo(val, e-1)) % MOD;
    int aux = expo(val, e/2) % MOD;
    return (aux*aux) % MOD;
} 

int inv(int val) {
    return expo(val, MOD-2);
}

void solve() {
    cin >> N >> M >> a >> b >> K;
    
    acumul[0] = acumul[1] = 1;
    for (int i = 2; i <= K; i++) acumul[i] = (acumul[i-1]*i) % MOD;

    int ans = 0;

    for (int i = 0; i <= K; i++) {
        int cur = calc(i, K-i) % MOD;
        // dbg(i, K, cur);
        
        cur = (cur * acumul[K]) % MOD;
        cur = (cur * inv(acumul[i])) % MOD;
        cur = (cur * inv(acumul[K-i])) % MOD;    

        cur = (cur * inv(expo(2, K))) % MOD;

        ans += cur;
        ans %= MOD;
    }

    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
	while (t--) solve();
}

