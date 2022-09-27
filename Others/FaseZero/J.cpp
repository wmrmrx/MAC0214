#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
	while (t--) solve();
}
