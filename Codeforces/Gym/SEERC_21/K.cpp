#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define pb push_back

const int N = 2e5 + 10;
const int INF = 1e12;

struct Node {
    int mn;
    Node () : mn(INF){};
    Node (int mn) : mn (mn) {}
    Node operator + (const Node &o) const {
        if (mn < o.mn) return *this;
        return o;
    }
};


int n, d[N];
vector<int> adj[N];

int pont = 0;
int pos[N], sz[N];

void dfs (int x, int p = -1) {
    sz[x] = 1;
    pos[x] = pont++;
    for (auto u : adj[x]) {
        if (u == p) continue;
        dfs (u, x);
        sz[x] += sz[u];
    }
}

Node node[4 * N];

void att (int no, int ini, int fim, int k, int val) {
    if (ini == fim) {
        node[no] = Node (val);
        return;
    }
    int meio = (ini + fim) / 2;
    if (k <= meio) att (2 * no, ini, meio, k, val);
    else att (2 * no + 1, meio + 1, fim, k, val);
    node[no] = node[2 * no] + node[2 * no + 1];
}

Node qq (int no, int ini, int fim, int l, int r) {
    if (l <= ini and fim <= r) return node[no];
    if (fim < l or r < ini) return Node ();
    int meio = (ini + fim) / 2;
    return qq (2 * no, ini, meio, l, r) + qq (2 * no + 1, meio + 1, fim, l, r);
}

Node qq_subtree (int i) {
    return qq (1, 0, n - 1, pos[i], pos[i] + sz[i] - 1);
}

void add_node (int i) {
    // vamos adicionar o no i na seg
    // dbg ("adicionei", i, pos[i], i);
    att (1, 0, n - 1, pos[i], i);
}

void rem_node (int i) {
    // dbg ("removi", i);
    att (1, 0, n - 1, pos[i], INF);
    for (auto j : adj[i]) {
        d[j]--;
        // dbg (i, j, d[j]);
        if (d[j] == 1) add_node (j);
    }
    d[i] = INF;
}

void dfs_ans (int x, int p, vector<int> &ans) {
    // vamos achar os melhores filhos
    // dbg (x, p, qq_subtree (x).mn);
    vector <pair<int, int>> son;
    for (auto u : adj[x]) {
        if (u == p) continue;
        son.pb ({qq_subtree (u).mn, u});
    }
    sort (all(son));
    bool adiciona = true;
    for (auto [leaf, u] : son) {
        if (qq_subtree (x).mn == x) {
            // vamos remover o x
            rem_node (x);
            ans.pb(x);
            adiciona = false;
        }
        dfs_ans (u, x, ans);
    }
    rem_node (x);
    if (p != -1 && adiciona) {
        ans.pb(x);
    }
}

void solve () {
    cin >> n;
    pont = 0;
    for (int i = 0; i <= n; i++) 
        adj[i].clear(), d[i] = 0, sz[i] = 0;
    for (int i = 0; i <= 4 * n; i++)
        node[i] = Node ();
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        d[a]++;
        d[b]++;
    }
    if (n == 2) {
        cout << "1 2\n";
        return;
    }
    int r = n + 1;

    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) {
            r = min (r, i);
            break;
        }
    }
    // dbg (r);
    dfs (r);
    // pegamos a melhor folha e enraizaremos nela
    // for (int i = 1; i <= n; i++)
    //     dbg (pos[i], sz[i]);
    for (int i = 1; i <= n; i++) 
        if (d[i] == 1)
            add_node (i);
    
    vector<int> ans;
    ans.pb(r);
    // adicionamos r na resposta
    rem_node (r);

    dfs_ans (r, -1, ans);
    for (auto u : ans)
        cout << u << " ";
    cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}
