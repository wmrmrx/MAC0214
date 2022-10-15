#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void solve() {
    int t; cin >> t;
    string s;
    cin >> s;

    int cur = 0, ans = 0;
    for (auto u : s) {
        if (u == 'a') {
            cur++;
        }
        else {
            if (cur > 1) ans += cur;
            cur = 0;
        }
    }
    if (cur > 1) ans += cur;
    cout << ans <<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
