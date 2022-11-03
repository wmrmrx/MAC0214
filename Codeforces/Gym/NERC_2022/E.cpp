#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

const int N = 1e3 + 10;
const int mod = 998244353;

struct Cell {
    int L, R, U, D;
    Cell () : L(0), R (0), D(0), U(0) {}
    void fixed () {
        L = R = D = U = -1;
    }
    bool ok () {
        if (L == -1) return true;
        if (L + R + D + U > 2) return false;
        if ((L and R) or (D and U)) return false;
        return true;
    }
};

int n;
string a[N];
Cell cell[N][N];

void solve () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#') {
                cur = 1;
                cell[i][j].fixed ();
            }
            else if (a[i][j] == '.') {
                cur = 0;
                cell[i][j].fixed ();
            }
            else {
                cell[i][j].R = cur;
            }
        }
        
        cur = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (a[i][j] == '#') {
                cur = 1;
                cell[i][j].fixed ();
            }
            else if (a[i][j] == '.') {
                cur = 0;
                cell[i][j].fixed ();
            }
            else {
                cell[i][j].L = cur;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == '#') {
                cur = 1;
                cell[i][j].fixed ();
            }
            else if (a[i][j] == '.') {
                cur = 0;
                cell[i][j].fixed ();
            }
            else {
                cell[i][j].D = cur;
            }
        }
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i][j] == '#') {
                cur = 1;
                cell[i][j].fixed ();
            }
            else if (a[i][j] == '.') {
                cur = 0;
                cell[i][j].fixed ();
            }
            else {
                cell[i][j].U = cur;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!cell[i][j].ok ()) {
                cout << "0\n";
                return;
            }
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cell[i][j].L == 0 and cell[i][j].R == 0) {
                int jj = j;
                while (jj < n && (cell[i][jj].L == 0 && cell[i][jj].R == 0)) jj++;
                ans = ans * (jj - j + 1) % mod;
                j = jj;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (cell[i][j].U == 0 and cell[i][j].D == 0) {
                int ii = i;
                while (ii < n && (cell[ii][j].D == 0 && cell[ii][j].U == 0)) ii++;
                ans = ans * (ii - i + 1) % mod;
                i = ii;
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
