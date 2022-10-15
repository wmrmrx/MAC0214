#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int MAXN = 1e6+10;
int mp[MAXN];
int n;

void solve() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur;
        cin >> cur;
        mp[cur]++;
        ans++;

        if (mp[cur+1]) {
            mp[cur+1]--;
            ans--;
        }
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
