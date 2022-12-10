#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1e4;

int n, a[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort (a, a + n);
    reverse (a, a + n);

    int A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) B += a[i];
        else A += a[i];
    }
    cout << A << " " << B << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
