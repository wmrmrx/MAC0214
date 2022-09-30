#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h,T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); cout << endl;}

#define pb push_back

const int N = 1e4 + 10;

int n, d, a[N], p[N];
vector<int> path[N];

void solve () {
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        // vamos definir o pai
        int pai; cin >> pai;
        p[i] = pai;
    }

    vector<int> maiores;
    for (int i = 1; i <= n; i++) {
        int j = i;
        for (int k = 0; k < d && j != -1; k++) {
            path[i].pb (a[j]);
            j = p[j];
        }
        if(path[i].size() != d) path[i].clear();
        reverse(all(path[i]));
        // dbg (i);
        // for (auto j : path[i]) cout << j << " ";
        // cout << "\n";
        if (path[i].size()) {
            maiores.pb (i);
            // dbg (i);
        }
    }

    for (int i = 0; i < d; i++) {
        vector<int> x0, x1;
        for (auto j : maiores) {
            // dbg (j);
            if (path[j][i] == 1) x1.pb (j);
            else x0.pb (j);
        }

        if (x1.size()) swap (maiores, x1);
        else swap (maiores, x0);
    }
    // dbg (maiores[0]);
    for (auto u : path[maiores[0]])
        cout << u << " ";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
