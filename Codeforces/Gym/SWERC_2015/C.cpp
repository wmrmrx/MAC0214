#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 3e5 + 10;

int n, a[N];

void solve() {
    cin >> n;
    multiset<int> num;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        num.insert (a[i]);
    }


    int ans = 0;
    while (num.size() > 1) {
        int x = *num.begin(), y = *next (num.begin());
        num.erase (num.find (x));
        num.erase (num.find (y));

        ans += x + y;
        num.insert (x + y);
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--)
	solve();
}
