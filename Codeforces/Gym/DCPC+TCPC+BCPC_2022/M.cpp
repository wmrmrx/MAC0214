#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<":";dbg_out(__VA_ARGS__);}

int x, y;

void solve() {
    cin >> x >> y;

    __int128 ini = 1, fim = 4e9;
    while (ini <= fim) {
        __int128 meio = (ini + fim) / 2;
        // dbg (meio);
        if (meio * (meio + 1) / 2 < x + y) ini = meio + 1;
        else fim = meio - 1;
    }
    cout << (int) ini << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--)
	solve();
}

