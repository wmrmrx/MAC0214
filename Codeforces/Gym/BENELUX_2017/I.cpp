#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1e2 + 10;
const int INF = 1e9;
int memo[N][N][2][2];

int dp (int n, int m, int black, int A) {
    if (memo[n][m][black][A] != INF) return memo[n][m][black][A];
    if (!m || !n) return 0;
    int ans = -1e9, cur = 0;
    if (A) {
        for (int j = 1; j <= m; j++) {
            if (n & 1) {
                if (black) {
                    if (j & 1) cur++;
                    else cur--;
                }
                else {
                    if (j & 1) cur--;
                    else cur++;
                }
            }

            if (j & 1)
                ans = max (ans, cur + dp (n, m - j, black ^ 1, A ^ 1));
            else 
                ans = max (ans, cur + dp (n, m - j, black, A ^ 1));
        }
    }
    else {
        ans = 1e9;
        int B = black;
        if ((n + m) & 1) B ^= 1;
        for (int i = 1; i <= n; i++) {
            if (m & 1) {
                if (B) {
                    if (i & 1) cur--;
                    else cur++;
                }
                else {
                    if (i & 1) cur++;
                    else cur--;
                }
            }
            ans = min (ans, cur + dp (n - i, m, black, A ^ 1));
        }
    }
    // dbg (n, m, black, A, ans);
    return memo[n][m][black][A] = ans;
}

void solve () {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < 2; k++)
                for (int p = 0; p < 2; p++)
                    memo[i][j][k][p] = INF;

    int n, m; cin >> n >> m;
    cout << dp (n, m, 1, 1) << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
