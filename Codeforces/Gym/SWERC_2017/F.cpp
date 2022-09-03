#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

int w, n;

void solve() {
    cin >> w >> n;
    int area = 0;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        area += x * y;
    }
    cout << area / w << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
