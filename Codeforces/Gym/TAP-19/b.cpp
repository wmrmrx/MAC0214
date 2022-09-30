#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h,T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int MAXN = 1e5+3;
int n;
int v[MAXN][3];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    bool ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            int a = v[i][0]-v[j][0];
            int b = v[i][1]-v[j][1];
            double c = sqrt(a*a + b*b);
            double r1 = v[i][2];
            double r2 = v[j][2];
            if ((r1 + r2 >= c) && ((r1 + c >= r2) && (c + r2 >= r1))) ans = 0;
        }
    }  

    if (ans) cout << "SI" << endl;
    else cout << "NO" << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
