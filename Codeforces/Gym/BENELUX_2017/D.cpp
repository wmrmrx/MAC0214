#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int MAXN = 1e5+5;
const int INF = 1e18;
vector<pair<int, int> > g[MAXN];
int dist[MAXN];
bool visited[MAXN];
int n, m;

void dijkstra(int ori) {
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[ori] = 0;
    for (int i = 0; i < n; i++) s.insert({dist[i], i});
    while (!s.empty()) {
        int u = s.begin()->second;
        s.erase(s.begin());
        for (auto &[v, w] : g[u]) {
            if (dist[u] + w >= dist[v]) continue;
            s.erase({dist[v], v});
            dist[v] = dist[u] + w;
            s.insert({dist[v], v});
        }
    }
}

bool dfs(int u, int target, vector<int> &ans) {
    if (u == target) return true;
    if (visited[u]) return false;
    visited[u] = 1;

    for (auto &[v, w] : g[u]) {
        if (visited[v]) continue;
        if (dist[v] + w == dist[u]) continue;
        if(dfs(v, target, ans)) {
            ans.push_back(u);
            return true;
        }
    }

    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dijkstra(1);
    //for (int i = 0; i < n; i++) cout << dist[i] << " "; cout << endl;
    vector<int> ans;
    dfs(0, 1, ans);

    reverse(ans.begin(), ans.end());
    ans.push_back(1);

    if (ans.size() > 1) {
        cout << ans.size() << " ";
        for (auto val : ans) cout << val << " "; cout << "\n";
    }
    else {
        cout << "impossible\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
