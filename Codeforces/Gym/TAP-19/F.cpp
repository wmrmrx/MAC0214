#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h,T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define pb push_back

const int N = 1 << 14;
const int mod = 1e9 + 7;

int pot4[10];
vector<int> masks;
int volta[N];

int bit4 (int mask, int i) {
    assert(0 <= i && i < 10);
    return (mask / pot4[i]) % 4;
}

int n, M, k;
string a[10];

void solve () {
    cin >> n >> M >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int m = 0; m < (1 << (2 * n)); m++) {
        bool add = true;
        for (int j = 0; j < n; j++) {
            if (bit4 (m, j) >= k || (j + 1 < n && bit4(m, j) == bit4(m, j + 1))) add = false;
        }
        if (add) {
            masks.pb (m);
            assert(0 <= m && m < N);
            volta[m] = masks.size() - 1;
        }
    }

    vector<int> memo (masks.size());

    auto check_col = [&] (int m, int j) {
        for (int i = 0; i < n; i++) {
            if (a[i][j] == '-') continue;
            if (j > 0 && bit4 (m, i) == (int) a[i][j - 1] - '1') return false;
            if (j + 1 < n && bit4 (m, i) == (int) a[i][j + 1] - '1') return false;
            if (bit4 (m, i) != (int) a[i][j] - '1' && a[i][j] != '-') return false;
            
        }
        return true;
    };
    for (int i = 0; i < masks.size(); i++) {
        int m = masks[i];
        // assert(m < memo.size());
        if (check_col (m, 0)) memo[i] = 1;
        // dbg (m, memo[i]);
    }
    vector<int> adj[masks.size()];

    for (int x = 0; x < masks.size(); x++) {
        int m = masks[x];
        for (int y = 0; y < masks.size(); y++) {
            int mm = masks[y];
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (bit4(mm, i) == bit4 (m, i)) ok = false;
            }
            if (ok) {
                adj[x].pb (y);
            }
        }
    }
    for (int j = 1; j < M; j++) {
        int tam = masks.size();
        vector<int> memo1 (tam);
    //     dbg (m);

        for (int x = 0; x < masks.size(); x++) {
            int m = masks[x];
            if (!check_col (m, j)) continue;

            for (auto y : adj[x]) {
                memo1[x] = (memo1[x] + memo[y]);
                if (memo1[x] >= mod) memo1[x] -= mod; 
            }
        }
        memo.swap(memo1);
    }
    int ans = 0;
    for (auto u : memo)
        ans = (ans + u) % mod;
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
    pot4[0] = 1;
    for (int i = 1; i < 10; i++)
        pot4[i] = pot4[i - 1] * 4;
	solve();
}
