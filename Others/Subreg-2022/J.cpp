#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int n;

void solve () {
    cin >> n;
    int J = 0, M = 0;
    vector<int> freq(20);
    for (int i = 0; i < 2; i++) {
        int x; cin >> x; freq[x]++;
        x = min (x, 10ll);
        J += x;
    }
    for (int i = 0; i < 2; i++) {
        int x; cin >> x; freq[x]++;
        x = min (x, 10ll);
        M += x;
    }
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; freq[x]++;
        x = min (x, 10ll);
        J += x;
        M += x;
    }

    for (int i = 1; i <= 13; i++) {
        if (freq[i] == 4) continue;
        int x = min (i, 10ll);
        if (x + M > 23) break;
        if (x + M == 23) {
            cout << i << "\n";
            return;
        }
        if (x + J > 23) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
 