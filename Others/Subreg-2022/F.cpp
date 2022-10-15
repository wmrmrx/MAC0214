#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define mp make_pair

const int N = 1e4 + 10;

int n, c, pot[13];
string s[N];

int id (string t) {
    int hash = 0;
    for (int j = 0; j < t.size (); j++) {
        hash += (t[j] - 'a' + 1) * pot[j];
    }
    return hash;
}

void solve () {
    cin >> n >> c;
    map<pair<int, int>, int> M;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < c; j++) {
            if (s[i][j] == '*') {
                M[mp (id(s[i].substr (0, j)), id(s[i].substr (j + 1, c - j - 1)))]++;
            }
        }
    }

    auto op = [&] (string t) {
        int ans = 0;
        for (int j = 0; j < c; j++) {
            if (M.find (mp (id(t.substr (0, j)), id(t.substr (j + 1, c - j - 1)))) != M.end ())
                ans += M[mp (id(t.substr (0, j)), id(t.substr (j + 1, c - j - 1)))];
        }
        return ans;
    };

    int ans = 0; string resp = "";
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] == '*') {
                for (char l = 'a'; l <= 'z'; l++) {
                    s[i][j] = l;
                    int X = op (s[i]);
                    if (ans < X) {
                        ans = X;
                        resp = s[i];
                    }
                    else if (ans == X) {
                        resp = min (resp, s[i]);
                    }
                }
            }
        }
    }
    cout << resp << " " << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    pot[0] = 1;
    for (int i = 1; i < 13; i++) pot[i] = pot[i - 1] * 27;
	solve();
}
