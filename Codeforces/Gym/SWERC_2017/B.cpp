#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

#define pb push_back

const int N = 2e3 + 10;

struct Node {
    int freq, val;
    Node () : freq(0), val(0) {}
    Node (int freq, int val) : freq(freq), val(val) {}
    Node operator + (const Node &o) const {
        return Node (freq + o.freq, val + o.val);
    }
};

Node node[4 * N];

void upd (int no, int ini, int fim, int k, int val) {
    if (ini == fim) {
        node[no].freq += val;
        node[no].val += val * ini;
        return;
    }
    int meio = (ini + fim) / 2;
    if (k <= meio) upd (2 * no, ini, meio, k, val);
    else upd (2 * no + 1, meio + 1, fim, k, val);
    node[no] = node[2 * no] + node[2 * no + 1];
}

Node qq (int no, int ini, int fim, int l, int r) {
    if (l <= ini and fim <= r) return node[no];
    if (fim < l or r < ini) return Node () ;
    int meio = (ini + fim) / 2;
    return qq(2 * no, ini, meio, l, r) + qq(2 * no + 1, meio + 1, fim, l, r);
}

int pai[N][N], sz[N][N];

int find_pai (int i, int j) {
    if (pai[i][j] == i) return i;
    return pai[i][j] = find_pai (pai[i][j], j);
}

void merge (int i, int ii, int j) {
    i = find_pai (i, j);
    ii = find_pai (ii, j);
    if (i == ii) return;
    upd (1, 1, N - 1, sz[i][j], -1);
    upd (1, 1, N - 1, sz[ii][j], -1);
    sz[i][j] += sz[ii][j];
    pai[ii][j] = i;
    upd (1, 1, N - 1, sz[i][j], 1);
}

int n, m, R, q;

void solve () {
    cin >> n >> m >> R >> q;
    swap(n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pai[i][j] = i;
            sz[i][j] = 1;
        }
    }

    vector<vector<int>> a(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= R; i++) {
        int x,y,xx,yy; cin >> x >> xx >> y >> yy;
        x++; y++;
        swap (x, y);
        swap (xx, yy);
        for (int j = x; j <= xx; j++)
            for (int k = y; k <= yy; k++)
                a[j][k] = 1;
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++)
    //         cout << a[i][j] << " ";
    //         cout << "\n";
    // }

    for (int i = 1; i <= n; i++) a[i][m + 1] = 1;
    vector<array<int, 3>> events;
    vector<vector<int>> dir (n + 2, vector<int> (m + 2, 0));

    for (int i = 1; i <= n; i++) {
        dir[i][m + 1] = 0;
        for (int j = m; j >= 1; j--) {
            if (!a[i][j]) {
                dir[i][j] = dir[i][j + 1] + 1;
                events.pb({dir[i][j], i, j});
                // dbg (dir[i][j], i, j);
            }
        }
    }
    
    sort(events.rbegin(), events.rend());
    vector<array<int, 3>> op;
    for (int i = 1; i <= q; i++) {
        int x, y; cin >> x >> y;
        op.pb({x, y, i});
    }

    sort(op.rbegin(), op.rend());

    int p = 0;
    vector<int> ans(q + 10);
    vector<vector<int>> ativo(n + 2, vector<int>(m + 2));
    for (auto [x, y, obj] : op) {
        // dbg (x, y, obj);
        while (p < events.size() && events[p][0] >= x) {
            // vamos adicionar esse evento
            int I = events[p][1], J = events[p][2]; p++;
                upd (1, 1, N - 1, 1, 1);
                ativo[I][J]++;
            // dbg (I, J);
            auto unite = [&] (int i, int ii, int j) {
                if (ii > n or ii <= 0) return;
                if (!a[ii][j] && ativo[ii][j]) {
                    merge (i, ii, j);
                }
            };
            unite (I, I + 1, J);
            unite (I, I - 1, J);
        }

        auto it = qq(1, 1, N - 1, y, N - 1);
        // dbg (it.freq, it.val);
        ans[obj] = it.val - it.freq * (y - 1);
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << "\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
