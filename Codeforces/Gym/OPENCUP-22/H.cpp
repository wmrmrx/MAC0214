#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(v) v.begin(), v.end()

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 5e5 + 10;
const int mod = 1e9 + 7;

int n, a[N], pos[N], mx[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
        mx[i] = max (mx[i - 1], a[i]);
    }

    int cur = 0;
    vector<int> acum (n + 10);
    acum[n + 1] = 1;
    for (int i = n + 1; i > 1; i--) {
        cur = (cur + acum[i]) % mod;
        int j = pos[mx[i - 1]];
        dbg (j, cur);
        acum[j] = (acum[j] + cur) % mod;
        if (i == n + 1) cur = 0;
    }
    cur = (cur + acum[1]) % mod;
    cout << cur << "\n";
}

signed main() {
	ios::sync_with_stdio(false);  cin.tie(0);
	solve();
}
