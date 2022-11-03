#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

const int N = 1e2 + 10;

int n, a[N], b[N], pos_a[N], pos_b[N];

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos_a[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pos_b[b[i]] = i;
    }

    for (int i = 1; i < n; i++) {
        if ((pos_a[i] < pos_a[i + 1]) != (pos_b[i] < pos_b[i + 1])) {
            cout << "-1\n";
            return;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (a[j] != b[i]) j++;

        while (j > i) {
            ans.push_back (j - 1);
            swap (a[j - 1], a[j]);
            j--;
        }
    }

    cout << ans.size () << "\n";
    for (auto u : ans) cout << u << " ";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
