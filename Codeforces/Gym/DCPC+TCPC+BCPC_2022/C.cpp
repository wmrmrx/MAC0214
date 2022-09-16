#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<":";dbg_out(__VA_ARGS__);}

const int N = 1e6 + 2;

int fat[N];

void crivo () {
    for (int i = 2; i < N; i++) {
        if (!fat[i]) {
            for (int j = i; j < N; j += i) fat[j]++;
        }
    }
    // for (int i = 1; i <= 30; i++)
    //     cout << fat[i] << " ";
}

int n, l, r, a[N];

void solve () {
    cin >> n >> l >> r;

    bitset<N> memo[r + 1];
    memo[0][0] = 1;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
        for (int ugli = r - fat[a[i]]; ugli >= 0; ugli--) {
            memo[ugli + fat[a[i]]] |= (memo[ugli] << a[i]);
        }
    }

    int ans = 1e10;
    for (int i = l; i <= r; i++) {
        for (int j = 0; j < N; j++) {
            if (memo[i][j]) {
                ans = min(ans, abs (tot - 2 * j));
            }
        }
    }
    if (ans > 1e9) ans = -1;
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
    crivo ();
    int t; cin >> t;
    while (t--)
	    solve();
}
