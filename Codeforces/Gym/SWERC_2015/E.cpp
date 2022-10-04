#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 2e3 + 10;
const int mod = 2147483647;

int n, a[N];

void solve () {
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    
    vector<int> memo(n + 10), pref (n + 10);
    memo[a[0]] = 1;
    for (int i = 1; i <= n + 1; i++) pref[i] = pref[i - 1] + memo[i];

    // dbg (1);
    // for (int j = 1; j <= n; j++)
    //     cout << memo[j] << " ";
    // cout << "\n";
    // for (int j = 1; j <= n + 1; j++)
    //     cout << pref[j] << " ";
    // cout << "\n";

    for (int i = 2; i <= n; i++) {
        int xi = a[i - 1];
        vector<int> memo1 (n + 10);
        for (int j = 1; j <= n + 1; j++) {
            if (j == a[i]) continue;
            int l = min (j, a[i]), r = max (j, a[i]);
            // vamos fazer o intervalo [l, r]
            // dbg (l, r);
            if (xi < l) {
                memo1[j] = (memo1[j] + memo[r]) % mod;
            }
            else if (r < xi) {
                memo1[j] = (memo1[j] + memo[l]) % mod;
            }
            else if (r == xi) {
                // temos que pegar todo mundo da esquerda
                memo1[j] = (memo1[j] + pref[xi - 1]) % mod;
            }
            else if (l == xi) {
                memo1[j] = (memo1[j] + pref[n + 1] - pref[xi] + mod) % mod;
            }
            else {
                memo1[j] = (memo1[j] + memo[l] + memo[r]) % mod;
            }
        }
        swap (memo, memo1);
        // dbg (i);
        // for (int j = 1; j <= n + 1; j++)
        //     cout << memo[j] << " ";
        // cout << "\n";

        for (int j = 1; j <= n + 1; j++)
            pref[j] = pref[j - 1] + memo[j];
    }
    int ans = 0;
    for (int i = 1; i <= n + 1; i++)
        ans = (ans + memo[i]) % mod;
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
