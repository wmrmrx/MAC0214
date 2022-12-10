#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1e3 + 10;

int n;
vector<int> adj[N];
string a[N];

void bfs () {
    vector<int> dist (n + 1, -1), pai (n + 1, -1);
    queue<int> q;
    q.push (0);
    dist[0] = 0;

    int tot = 0;
    while (q.size ()) {
        int u = q.front (); q.pop ();
        tot++;

        for (auto v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                pai[v] = u;
                q.push (v);
            }
        }
    }

    if (tot != n) {
        cout << "impossible\n";
        exit (0);
    }
    vector<vector<int>> pos (n + 1);
    for (int i = 0; i < n; i++)
        pos[dist[i]].pb (i);

    int last = -1;
    vector<int> ans, vis (n);
    for (int i = n - 1; i >= 0; i--) {
            // dbg (i);
        for (auto u : pos[i]) {
            if (vis[u]) continue;
            vis[u]++;
            ans.pb (u);
            if (last == -1) {
                last = u;
            } 
            else {
                if (a[last][u] == '0') last = u;
            }
        }

        if (last != -1) {
            last = pai[last];
            if (last != -1) ans.pb (last);
            if (last != -1) vis[last]++;
        }
    }

    for (auto u : ans)
        cout << u << " ";
    cout << "\n";
}

void solve () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '1') {
                adj[i].pb (j);
            }
        }
    }
    
    bfs ();
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
