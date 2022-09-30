#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h,T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1e2 + 10;

int n, m, x, y;

void solve () {
    cin >> n >> m >> x >> y;

    if ((x * m + y * n) * (n + m) == 2 * (x + y) * n * m) {
        cout << "C\n";
    }
    else if ((x * m + y * n) * (n + m) > 2 * (x + y) * n * m) {
        cout << "A\n";
    }
    else {
        cout << "B\n";
    }
}
signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
