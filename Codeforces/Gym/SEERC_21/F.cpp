#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1e5 + 10;

int n, X, R, P, K;
string s;

int check (int k) {
    // se escolhermos cancelar os k primeiros R
    int ans = X * n;
    int sobra = K - k;
    assert (k >= 0 and sobra >= 0);
    // dbg (k, sobra);
    for (int i = 0; i < n; i++) {
        char u = s[i];
        if (u == '0') {
            if (sobra) {
                sobra--;
                ans += P * (n - i);
            }
        }
        else {
            if (k) {
                ans += P * (n - i);
                k--;
            }
            else ans -= R * (n - i);
        }
    }
    return ans;
}

void solve () {
    cin >> n >> X >> R >> P >> K;
    cin >> s;
    int lim = 0;
    for (auto u : s)
        lim += u - '0';
    // for (int i = 0; i <= K; i++)
    //     dbg (check (i));
    int ini = 0, fim = min (K, lim);
    while (ini < fim) {
        int meio = (ini + fim) / 2;
        if (check (meio) <= check (meio + 1)) ini = meio + 1;
        else fim = meio;
    }
    cout << check (ini) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
