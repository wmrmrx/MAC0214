#pragma GCC optimize ("Ofast, avx")  

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

const int MAXN = 204;
const int MAXV = 2000;
int psum[MAXN][MAXN][MAXV+1];
int n, m, q;

int query(int a, int b, int c, int d, int x) {
    return psum[b][d][x] - psum[b][c-1][x] - psum[a-1][d][x] + psum[a-1][c-1][x];
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            for (int k = 1; k <= MAXV; k++) {
                psum[i][j][k] = psum[i-1][j][k]+psum[i][j-1][k]-psum[i-1][j-1][k];
                psum[i][j][k] += (x == k);
            }
        }
    }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        swap(b, c);
        int sz = (b-a+1)*(d-c+1);
        int s = 0;
        int M = (sz+1)/2;
        for (int i = 1; i <= MAXV; i++) {
            s += query(a, b, c, d, i);
            // dbg(a, b, c, d, i, query(a, b, c, d, i), s);
            if (2*s > sz) {
                cout << i << "\n";
                break;
            }
        }
        // cout << "bleh";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("important.in", "r", stdin);
	int t; cin >> t;
	for(int i=1;i<=t;i++) {
		cout << "Case " << i << ":";
		cout << '\n';
		solve();
	}
}
