#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h,T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1e2 + 10;

int n;

void solve() {
    cin >> n;
    int x; cin >> x;
    vector<int> a(n - 1);
    for (auto &u : a) cin >> u;

    sort (all (a));

    int falta = n - 1;
    for (auto u : a) {
        x -= falta * u - 1;
        falta--;
    }
    if (x > 0) {
        cout << "SI\n";
    }
    else cout << "NO\n";
    // while (a.size()) {
    //     vector<int> b = a;
    //     int mn = 1e10;
    //     for (auto u : a) mn = min (mn, u);

    //     x -= a.size() * (mn - 1);
    //     for (auto u : a) {
    //         if (u == mn) continue;
    //         x--;
            
    //     }
    // }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
