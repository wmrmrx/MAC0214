#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(v) v.begin(), v.end()

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1 << 10;

int n, k, m, a[11];
int cor[11]; // mascara de cores
int pieces[11];
int memo[N][N];

int bfs () {
    queue<pair<int, int>> q;
    q.push ({cor[0], 0});
    memo[cor[0]][0] = 0;
    while (q.size()) {
        auto it = q.front (); q.pop ();
        int mask_c = it.first, mask_p = it.second;
        int &ans = memo[mask_c][mask_p];
        dbg (mask_c, mask_p, ans);

        int ball = 0;
        for (int i = 0; i < m; i++) {
            if ((1 << i) & mask_p) ball |= pieces[i];
            if (memo[mask_c][mask_p ^ (1 << i)] == -1) {
                memo[mask_c][mask_p ^ (1 << i)] = ans + 1;
                q.push ({mask_c, mask_p ^ (1 << i)});
            }
            // ans = min (ans, dp (mask_c, mask_p ^ (1 << i)) + 1);
        }
        // invertemos a bola
        ball = ((1 << n) - 1) ^ ball;

        // se vamos pintar de alguma cor
        for (int i = 0; i < k; i++) {
            bool ok = true;
            // int vez = (cor[i] & (cor[i] ^ ball));
            int vez = mask_c;
            for (int j = 0; j < n; j++) {
                // temos que ver se a cor esta correta
                if ((1 << j) & ball) {
                    if (a[j] == i) vez |= (1 << j);
                    else if (vez & (1 << j)) vez -= (1 << j);
                }
            }
            if (memo[vez][mask_p] == -1) {
                memo[vez][mask_p] = ans + 1;
                q.push ({vez, mask_p});
            }
            // if (ok) {
            //     ans = min (ans, dp (vez, mask_p) + 1);
            // }
        }
    }
    int ans = memo[(1 << n) - 1][0];
    return ans;
}

void solve () {
    memset (memo, -1, sizeof (memo));

    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        a[i] = x;
        cor[x] |= (1 << i);
    }

    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        while (c--) {
            int x; cin >> x; x--;
            pieces[i] |= (1 << x); 
        }
    }

    int ans = bfs ();
    if (ans > 1e3) ans = -1;
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);  cin.tie(0);
	solve();
}
