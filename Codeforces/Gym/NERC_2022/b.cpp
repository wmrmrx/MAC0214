#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() {cerr << endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr <<' '<< h; dbg_out(t...); }
#define dbg(...) // { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int MAXN = 1e6+5;
string board[MAXN];
int auxi[MAXN], auxj[MAXN];
int best[4][MAXN];
string s;
int t, n, m;

void update(int k, int ind, int val) {
    // if (k == 2) dbg("update", k, ind, val);
    ind++;
    while (ind > 0 && ind < MAXN) {
        best[k][ind] = max(best[k][ind], val);
        int jump = ind&-ind;
        if (k >= 2) ind -= jump;
        else ind += jump;
    }
}

int query(int k, int ind) {
    ind++;
    int ans = -1;
    // if (k == 2) dbg("query", k, ind);
    while (ind > 0 && ind < MAXN) {
        ans = max(ans, best[k][ind]);
        int jump = ind&-ind;
        if (k >= 2) ind += jump;
        else ind -= jump; 
    }
    // if (k == 2) dbg(">", ans);
    return ans;
}

void precalc() {
    memset(best, -1, sizeof(best));

    for (int i = 0; i < n; i++) auxi[i] = 0;
    for (int j = 0; j < m; j++) auxj[j] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auxi[i] = (board[i][j] == '.') ? auxi[i]+1 : 0;
            auxj[j] = (board[i][j] == '.') ? auxj[j]+1 : 0;
            update(0, j, max(auxi[i], auxj[j]));
            update(1, i, max(auxi[i], auxj[j]));
        }
    }
    for (int i = 0; i < n; i++) auxi[i] = 0;
    for (int j = 0; j < m; j++) auxj[j] = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            auxi[i] = (board[i][j] == '.') ? auxi[i]+1 : 0;
            auxj[j] = (board[i][j] == '.') ? auxj[j]+1 : 0;
            update(2, j, max(auxi[i], auxj[j]));
            update(3, i, max(auxi[i], auxj[j]));
        }
    }
}

int solve() {
    int ans = -1;
    for (int i = 0; i < n; i++) auxi[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auxi[i] = (board[i][j] == '.') ? auxi[i]+1 : 0;
            if (auxi[i] == 0) continue;
            if (j != m-1 && board[i][j+1] == '.') continue;
            int r = j;
            int l = j-auxi[i]+1;
            // i, l, r
            int a = query(0, l-1);
            int b = query(1, i-1);
            int c = query(2, r+1);
            int d = query(3, i+1);
            dbg("nova fileirinha", i, l, r);
            dbg(auxi[i], a, b, c, d);
            ans = max(ans, auxi[i]+a);
            ans = max(ans, auxi[i]+b);
            ans = max(ans, auxi[i]+c);
            ans = max(ans, auxi[i]+d);
        }
    }

    for (int j = 0; j < m; j++) auxj[j] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auxj[j] = (board[i][j] == '.') ? auxj[j]+1 : 0;
            if (auxj[j] == 0) continue;
            if (i != n-1 && board[i+1][j] == '.') continue;
            int r = i;
            int l = i-auxj[j]+1;
            // i, l, r
            int a = query(0, j-1);
            int b = query(1, l-1);
            int c = query(2, j+1);
            int d = query(3, r+1);
            dbg("nova fileirinha", i, l, r);
            dbg(auxj[j], a, b, c, d, ans);
            ans = max(ans, auxj[j]+a);
            ans = max(ans, auxj[j]+b);
            ans = max(ans, auxj[j]+c);
            ans = max(ans, auxj[j]+d);
        }
    }

    return ans;
}

void Xsolve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) board[i].clear();

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    precalc();
    cout << solve() << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> t;
	while (t--) Xsolve();
}
