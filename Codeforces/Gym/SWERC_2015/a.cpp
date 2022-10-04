#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int MAXN = 2e4+5;
int gin[MAXN], coveredby[MAXN], covers[MAXN], marc[MAXN];
int L, R, n, m;

int dfs(int u, vector<int> gg[]) {
    marc[u] = 1;
    int ans = 1;
    for (auto v : gg[u]) {
        if (marc[v]) continue;
        ans += dfs(v, gg);
    }
    return ans;
}

vector<int> g[MAXN], rg[MAXN];
int ans[5];



void solve() {
    cin >> L >> R >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        covers[i] = dfs(i, g);
        memset(marc, 0, sizeof(marc));
    }

    for (int i = 0; i < n; i++) {
        coveredby[i] = dfs(i, rg);
        memset(marc, 0, sizeof(marc));
    }

    for (int i = 0; i < n; i++) {
        int mn = coveredby[i];
        int mx = n-covers[i]+1;
        // printf("%d %d %d // %d %d\n", i, coveredby[i], covers[i], mn, mx);
        if (L >= mx) ans[0]++;
        if (R >= mx) ans[1]++;
        if (R < mn) ans[2]++;
    }

    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2] << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
