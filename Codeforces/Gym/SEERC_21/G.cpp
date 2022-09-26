#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1e5 + 10;

int n;

void solve () {
    cin >> n;
    int tot_A = 0;
    vector<int> sum;
    for (int i = 1; i <= 2 * n; i++) {
        int a, b; cin >> a >> b;
        sum.push_back (a + b);
        tot_A += min (a, b);
    }

    sort (all (sum));
    reverse (all(sum));
    int ans = -tot_A;
    for (int i = 0; i < n; i++)
        ans += sum[i];
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
