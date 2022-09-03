#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

#define mp make_pair
#define pb push_back

int n, x, y, k;
double p, memo[3010][51][51];

bool check (int pos) {
    return 0 <= pos and pos < n - 1;
}

double dp (int k, int x1, int x2) {
    if (memo[k][x1][x2] > -1e-8) return memo[k][x1][x2];
    if (k == 0) return ((x1 == x) and (x2 == y));
    double ans = 0;

    if (x1 == x2) {
        double NVP = n - 1 - check(x1) - check(x1 - 1);
        ans += dp(k - 1, x1, x2) * (1 - p + p * NVP / (n - 1));
        if (x1) ans += dp (k - 1, x1 - 1, x2 - 1) * p / (n - 1);
        if (x1 < n - 1) ans += dp (k - 1, x1 + 1, x2 + 1) * p / (n - 1);
    }
    // se nao estao vizinhos
    else if (abs (x1 - x2) > 1) {
        double NVP = n - 1 - check (x1 - 1) - check (x1) - check (x2 - 1) - check (x2);
        ans += dp (k - 1, x1, x2) * (1 - p + p * NVP / (n - 1));
        if (x1) ans += dp (k - 1, x1 - 1, x2) * p / (n - 1);
        if (x2) ans += dp (k - 1, x1, x2 - 1) * p / (n - 1);
        if (x1 < n - 1) ans += dp (k - 1, x1 + 1, x2) * p / (n - 1);
        if (x2 < n - 1) ans += dp (k - 1, x1, x2 + 1) * p / (n - 1);
    }
    // se eles estao vizinhos
    else {
        int NVP = n - 1;
        if (x1 + 1 == x2) {
            NVP -= check (x1 - 1) + check(x2) + check(x1);
            ans += dp (k - 1, x1, x2) * (1 - p + p * NVP / (n - 1));
            if (x1) ans += dp (k - 1, x1 - 1, x2) * p / (n - 1);
            if (x2 < n - 1) ans += dp (k - 1, x1, x2 + 1) * p / (n - 1);
            ans += dp (k - 1, x2, x1) * p / (n - 1);
        }
        else {
            // x2, x1
            NVP -= check (x2 - 1) + check(x2) + check(x1);
            ans += dp (k - 1, x1, x2) * (1 - p + p * NVP / (n - 1));
            if (x2) ans += dp (k - 1, x1, x2 - 1) * p / (n - 1);
            if (x1 < n - 1) ans += dp (k - 1, x1 + 1, x2) * p / (n - 1);
            ans += dp (k - 1, x2, x1) * p / (n - 1);
        }
    }
    return memo[k][x1][x2] = ans;
}

void solve () {
    cin >> n >> p >> x >> y >> k;

    if (n == 1) {
        cout << "1.00000\n";
        return;
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                memo[i][j][k] = -1;
        }
    }
    cout << dp (k, y, x) << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("assessment.in", "r", stdin);
    cout << setprecision(5) << fixed;
	int t; cin >> t;
	for(int i=1;i<=t;i++) {
		cout << "Case " << i << ": ";
		solve();
	}
}
