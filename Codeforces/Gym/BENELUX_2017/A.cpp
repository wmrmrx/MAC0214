#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int n, m;
double R;
const double PI = acos(-1);
int x1, x2, Y1, y2;


void solve() {
    cin >> n >> m >> R;
    cin >> x1 >> Y1 >> x2 >> y2;
    
    double best = 1e18;

    for (int k = 0; k <= m; k++) {
        double RR = k * (R / m);
        double da = abs(Y1-k) * (R/m);
        double db = abs(y2-k) * (R/m);
        double dr = (RR * PI * abs(x1-x2)) / n;
        double cur = da+db+dr;
        if (cur < best) best = cur;
    }

    cout << setprecision(10) << fixed;
    cout << best << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
