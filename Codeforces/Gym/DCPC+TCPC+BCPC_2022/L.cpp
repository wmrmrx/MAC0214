#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(v) v.begin(),v.end()
 
void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<":";dbg_out(__VA_ARGS__);}

#define pb push_back

const int N = 5e2 + 10;

int n;

bool check (vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        vector<int> M(N + 2);
        for (int j = i + 1; j < a.size(); j++) {
            // se tem a mesma paridade
            if ((a[i] + a[j]) % 2 == 0) {
                if (M[(a[i] + a[j]) / 2]) {
                    // dbg (a[i], a[j]);
                    // dbg (M[(a[i] + a[j]) / 2], (a[i] + a[j]) / 2);
                    return false;
                }
            }
            M[a[j]]++;
        }
    }
    return true;
}

vector<int> memo[N];

vector<int> build (int x) {
    if (!x) return {};
    if (x == 1) return {1};
    if (memo[x].size()) return memo[x];

    auto odd = build ((x + 1) / 2), even = build (x / 2);
    vector<int> ans;
    for (auto u : odd)
        ans.pb (2 * u - 1);
    for (auto u : even)
        ans.pb (2 * u);

    return memo[x] = ans;
}

void solve () {
    int n; cin >> n;
    auto bs = build (n);
    // for (auto u : a)
    //     dbg (u);
    // assert (check (a));

    vector<int> ans[n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i].pb (bs[j] * n - n + i);
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < n; j++)
    //         cout << ans[i][j] << " ";
    //     cout << "\n";
    //     assert (check (ans[i]));
    // }

    vector<int> pos(n + 10);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout <<  ans[bs[i]][j] << " ";
        cout << "\n";
    }
}
// 0 8 4 2 1 6 9 5 3 7

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}
