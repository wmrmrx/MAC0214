#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(v) v.begin(), v.end()
#define rmax(a, b) a = max(a,b)
#define mp make_pair

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr int INF = 1e18;

const int N = 20;

int n, k, a[N][N];
vector<int> pref[2][N][N], suf[2][N][N];

int op (int i, int j, int ii, int jj) {
    // se for k em (i, j)
    int ans = 0;
    for (auto cur : pref[1][i][j]) {
        // se for k em (ii, jj)
        auto &v = suf[1][ii][jj];
        int J = lower_bound(all(v), array<int, 3> {0, 0, 0}) - v.begin();
        ans += J;

        // se n for k em (ii, jj)
        auto &vv = suf[0][ii][jj];
        J = lower_bound(all(vv), k - cur + 1) - vv.begin();
        ans += J;
    }
    // se nao for k em (i, j)
    for (auto cur : pref[0][i][j]) {
        // se for k em (ii, jj)
        auto &v = suf[1][ii][jj];
        int J = lower_bound(all(v), k - cur + 1) - v.begin();
        ans += J;

        auto &b = suf[0][ii][jj];
        // se nao, temos que achar exatamente os que sao k - cur
        int l = lower_bound (all(b), k - cur) - b.begin();
        int r = lower_bound (all(b), k - cur + 1) - b.begin();
        ans += (r - l);
    }
    return ans;
}

void solve () {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    if (n == 1) {
        cout << (a[0][0] == k) << "\n";
        return;
    }

    for (int mask = 0; mask < (1 << (n - 2)); mask++) {
        int x = 0, y = 0, cur = a[0][0], mx = a[0][0];

        for (int j = 0; j < n - 2; j++) {
            if ((1 << j) & mask) x++;
            else y++;
            
            if (cur < 0) cur = 0;
            cur += a[x][y];
            mx = max (mx, cur);
        }
        if (mx < k) {
            pref[0][x][y].push_back (cur);
        }
        else if (mx == k) pref[1][x][y].push_back (cur);
    }
    for (int mask = 0; mask < (1 << (n - 1)); mask++) {
        int x = n - 1, y = n - 1, cur = a[n - 1][n - 1], mx = a[n - 1][n - 1];
        for (int j = 0; j < n - 1; j++) {
            if ((1 << j) & mask) x--;
            else y--;
            
            if (cur < 0) cur = 0;
            cur += a[x][y];
            mx = max (mx, cur);
        }
        if (mx < k) suf[0][x][y].push_back (cur);
        else if (mx == k) suf[1][x][y].push_back (cur);
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        sort (all (pref[0][i][j]));
        sort (all (pref[1][i][j]));
        sort (all (suf[0][i][j]));
        sort (all (suf[1][i][j]));
    }
    int ans = 0;
    // vamos iterar pela diagonal do pref
    for (int i = 0; i <= n - 2; i++) {
        int j = n - 2 - i;

        int ii = i + 1, jj = j;
        if (ii < n && jj < n) {
            ans += op (i, j, ii, jj);
        }
        ii = i, jj = j + 1;
        if (ii < n && jj < n) {
            ans += op (i, j, ii, jj);
        }
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);  cin.tie(0);
	solve();
}
