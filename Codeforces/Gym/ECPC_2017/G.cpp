#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

const double PI = acos(-1);

int n, k; double r;

void solve() {
    cin >> n >> r >> k;
    double ans = 0, alfa = (double) 2 * PI / k;
    r /= cos (alfa / 2);
    for (int i = 1; i <= n; i++) {
        ans += r * r * (sin(alfa) * k / 2 - cos (alfa / 2) * cos (alfa / 2) * PI);
        r = r / cos (alfa / 2);
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("glorious.in", "r", stdin);
    cout << setprecision(5) << fixed;
	int t; cin >> t;
	for(int i=1;i<=t;i++) {
		cout << "Case " << t << ": ";
		// cout << '\n';
		solve();
	}
}
