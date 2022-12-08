#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1e3 + 10;

int esp[N];
int d[N];
bool adj[N][N];

void build (int n) {
    // nao precisamos ter aresta e esp = 0
    if (n == 1 || n == 2) return;
    // dbg (n);
    build (n - 1);
    // vamos fazer aresta em todo mundo com grau maior que esp[n - 1]
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (d[i] > esp[n - 1]) {
            adj[i][n] = 1;
            d[i]++;
            d[n]++;
        }
        else if (d[i] == esp[n - 1] && ok) {
            ok = false;
            adj[i][n] = 1;
            d[i]++;
            d[n]++;
        }
    }
    esp[n] = d[n];
}

int n, k;

void solve () {
    cin >> n >> k;
    if (k == n) {
        cout << "NO\n";
        return;
    }
    int sa = n;
    n = k + 1;
    build (n);
    
    vector<pair<int, int>> ans;
    for (int i = 1; i <= sa; i++) {
        for (int j = i + 1; j <= sa; j++) {
            if (not adj[i][j]) ans.push_back ({i, j});
        }
    }

    cout << "YES\n";
    cout << ans.size () << "\n";
    for (auto [a, b] : ans)
        cout << a << " " << b << "\n";
    cout << k << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
