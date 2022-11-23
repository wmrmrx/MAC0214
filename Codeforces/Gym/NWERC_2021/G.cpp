#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() {cerr <<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){ cerr << ' ' << h; dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define pb push_back

const int N = 5e5 + 10;
const int INF =  1e9;

int n, s[N];

int pai[N], l[N], sz[N], r[N], v[N];

int find_pai (int x) {
    return pai[x] = (pai[x] == x ? x : find_pai (pai[x]));
}

void merge (int a, int b, int meta) {
    a = find_pai (a); b = find_pai (b);
    if (a == b) return;
    sz[a] += sz[b];

    // vamos mergir b em a

    v[a] += v[b] - meta;

    if ((r[a] + 1) % n == l[b]) {
        r[a] = r[b];
    }
    else {
        l[a] = l[b];
    }

    pai[b] = a;
}

bool check (int meta) {
    for (int i = 0; i < n; i++) {
        pai[i] = i;
        l[i] = r[i] = i;
        sz[i] = 1;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        v[i] = s[i] + meta;
        if (meta >= s[i]) {
            q.push (i);
        }
    }

    auto next = [&] (int x) {
        return (x + 1) % n;
    };
    auto prev = [&] (int x) {
        return (x - 1 + n) % n;
    };

    while (q.size ()) {
        int i = q.front (); q.pop ();

        if (i != find_pai (i)) continue;

        bool add = false;
        int R = next(r[i]);
        // dbg (i, v[i], l[i], r[i]);

        while (find_pai (R) != find_pai (i) && (sz[find_pai (R)] > 1 || v[find_pai (i)] >= s[R])) {
            merge (i, R, meta);
            R = next (r[find_pai (i)]);
            add = true;
        }

        int L = prev (l[find_pai (i)]);

        while (find_pai (L) != find_pai (i) && (sz[find_pai (L)] > 1 || v[find_pai (i)] >= s[L])) {
            merge (i, L, meta);
            L = prev (l[find_pai (i)]);
            add = true;
        }
        if (add) q.push (find_pai (i));
    }

    return sz[find_pai (1)] == n;
}

void solve () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];

    // dbg(check (3));
    int ini = 0, fim = 1e13;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (check (meio)) fim = meio - 1;
        else ini = meio + 1;
    }
    cout << ini << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
