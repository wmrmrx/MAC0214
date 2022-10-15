#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int n, x, y;

void solve() {
    cin >> n;
    cin >> x >> y;
    
    int bit_x = 0, bit_y = 0;
    for (int j = 0; j < n; j++) {
        if ((1 << j) & x) {
            bit_x = j;
            break;
        }
    }
    for (int j = 0; j < n; j++) {
        if ((1 << j) & y) {
            bit_y = j;
            break;
        }
    }
    if (bit_x != bit_y) {
        cout << n << "\n";
    }
    else {
        cout << n - bit_x - 1 << "\n";
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
