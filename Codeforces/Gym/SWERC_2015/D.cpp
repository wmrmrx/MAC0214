#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int a, b;

void solve() {
    cin >> a >> b;
    vector<int> freq (a + b + 2);

    int mx = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) freq[i + j]++, mx = max (mx, freq[i + j]);
    }

    for (int i = 1; i <= a + b; i++) {
        if (freq[i] == mx) cout << i << "\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
