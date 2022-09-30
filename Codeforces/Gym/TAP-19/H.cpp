#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h,T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); cout << endl;}

#define pb push_back



int op () {
    int ans = 0;
    for (int i = 0; i + m <= n; i++) {
        // vamos achar o tamanho do maior prefixo comum
        int ini = 1, fim = m;
        while (ini <= fim) {
            int meio = (ini + fim) / 2;
            if (H_s (i, i + meio - 1) == H_t (0, meio - 1)) ini = meio + 1;
            else fim = meio - 1;
        }

        int pref = fim;
        if (pref >= m - 1) {
            // se for tudo igual
            ans++;
            continue;
        }

        int need = m - pref - 1;
        // dbg (i, pref, need, i + pref + 1);

        ini = 1, fim = need;
        while (ini <= fim) {
            int meio = (ini + fim) / 2;
            if (H_s (i + pref + 1, pref + 1 + i + meio - 1) == H_t (pref + 1 + 0, pref + 1 + meio - 1)) ini = meio + 1;
            else fim = meio - 1;
        }
        pref = fim;
        if (pref >= need) {
            // dbg (i);
            ans++;
        }
    }
    return ans;
}

void solve () {
    cin >> n >> s;
    H_s = str_hash<mod1> (s);

    int ans = 0;
    cin >> q >> m;
    for (int i = 1; i <= q; i++) {
        string t; cin >> t;
        H_t = str_hash<mod1> (t);
        ans += op();
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
