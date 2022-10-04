#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

struct SCC {
    int N, ti = 0; vector<vector<int>> adj;
    vector<int> disc, comp, st, comps;
    void init (int _N) {
        N = _N;
        adj.resize (N);
        disc.resize (N);
        comp = vector<int> (N, -1);
    }
    void add_edge (int x, int y) { adj[x].push_back (y); }
    int dfs (int x) {
        int low = disc[x] = ++ti; st.push_back (x);
        for (auto y : adj[x]) if (comp[y] == -1) {
            auto b = disc[y] ? : dfs (y); auto &a = low;
            b < a ? a = b, 1 : 0;
        }
        if (low == disc[x]) {
            comps.push_back(x); for (int y = -1; y != x;)
                comp[y = st.back()] = x, st.pop_back ();
        }
        return low;
    }
    void gen () {
        for (int i = 0; i < N; i++) if (!disc[i]) dfs (i);
        reverse (all(comps));
    }
};

struct TwoSAT {
    int N; SCC S; vector<bool> ans;
    void init (int _N) {
        N = _N;
        S.init (2 * N);
        ans.resize (N);
    }
    int addVar () {
        return N++;
    }
    void either (int x, int y) {
        x = max (2 * x, -1 - 2 * x), y = max (2 * y, -1 - 2 * y);
        S.add_edge (x ^ 1, y); S.add_edge (y ^ 1, x);
    }
    void add_cl (int x, int y) {
        implies (~x, y);
    }
    void add_xor (int x, int y) {
        add_cl (x, y);
        add_cl (~x, ~y);
    }
    void implies (int x, int y) {
        either (~x, y);
    }
    void must (int x) {
        either (x, x);
    }
    void atMostOne (const vector<int> &li) {
        if (li.size() <= 1) return;
        int cur = ~li[0];
        for (int i = 2; i < li.size(); i++) {
            int next = addVar ();
            either (cur, ~li[i]); either (cur, next);
            either (~li[i], next); cur = ~next;
        }
        either (cur, ~li[1]);
    }
    bool solve (int _N = -1) {
        if (_N != -1) N = _N, S.init (2 * N);
        S.gen (); reverse (all (S.comps));
        for (int i = 0; i < 2 * N; i += 2) 
            if (S.comp[i] == S.comp[i ^ 1]) return 0;
        vector<int> tmp (2 * N); for (auto i : S.comps) if (!tmp[i])
            tmp[i] = 1, tmp[S.comp[i ^ 1]] = -1;
        for (int i = 0; i < N; i++) if (tmp[S.comp[2 * i]] == 1) ans[i] = 1;
        return 1;
    }
};

int q;

void solve () {
    cin >> q;
    vector<array<int, 4>> op;
    for (int i = 1; i <= q; i++) {
        string S; int det; int quant;
        cin >> S >> det >> quant;
        op.push_back ({S[0] - 'A', S[1] - 'A', det, quant});
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            for (int k = j + 1; k < 26; k++) {
                bool add = true;
                TwoSAT sat;
                sat.init (26);
                for (auto [x, y, det, quant] : op) {
                    if (x > y) swap (x, y);
                    if (x == i or x == j or x == k) {
                        if (y == i or y == j or y == k) {
                            if (quant) {
                                add = false;
                                break;
                            }
                            continue;
                        }

                        // temos que adicionar somente o y
                        if (quant == 2) {
                            add = false;
                            break;
                        }
                        if (quant == 1) {
                            if (det == 1) sat.must (y);
                            else sat.must (~y);
                        }
                        else if (quant == 0) {
                            if (det == 1) sat.must (~y);
                            else sat.must (y);
                        }
                        continue;
                    }
                    if (y == i or y == j or y == k) {
                        if (quant == 2) {
                            add = false;
                            break;
                        }
                        if (quant == 1) {
                            if (det == 1) sat.must (x);
                            else sat.must (~x);
                        }
                        else if (quant == 0) {
                            if (det == 1) sat.must (~x);
                            else sat.must (x);
                        }
                        continue;
                    }
                    // se os 2 nao estao no grupo
                    if (quant == 2) {
                        if (det == 1) {
                            sat.must (x);
                            sat.must (y);
                        }
                        else {
                            sat.must (~x);
                            sat.must (~y);
                        }
                    }
                    else if (!quant) {
                        if (det == 2) {
                            sat.must (x);
                            sat.must (y);
                        }
                        else {
                            sat.must (~x);
                            sat.must (~y);
                        }
                    }
                    else {
                        // deve fazer x xor y
                        sat.add_xor (x, y);
                    }
                }
                if (add) {
                    if (sat.solve ()) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
