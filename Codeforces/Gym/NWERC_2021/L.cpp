#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() {cerr <<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){ cerr << ' ' << h; dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define pb push_back

int n, ini, k;

vector<double> transicao (vector<double> p) {
    vector<double> suf (n + 3);
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + (double) 1 / i;
    }

    vector<double> q (n + 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // se for de i para j
            if (i < j) {
                q[j] += (double) p[i] / n * suf[j]; 
            }
            else if (j < i) {
                q[j] += (double) p[i] / n * suf[i];
            }
            else q[j] += p[i] / n * (suf[i] + j - 1);
        }
    }
    return q;
}

void solve () {
    cin >> n >> ini >> k;

    vector<double> p (n + 2);
    p[ini] = 1;
    while (k--) p = transicao (p);
    
    double ans = 0;
    for (int j = 1; j <= n; j++) {
        ans += p[j] * j;
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cout << setprecision (15) << fixed;
	solve();
}
