#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1ll << 30;
const int mod = 1e9 + 7;

int L[3], R[3];
vector<array<int, 3>> ranges[3];

int find_bit (int a, int b) {
    for (int j = 30; j >= 0; j--) {
        if (((a >> j) & 1) != ((b >> j) & 1))
            return j;
    }
    return -1;
}

void itera (int id, int l1, int r1) {
    if (r1 < L[id] or R[id] < l1) return;
    if (L[id] <= l1 and r1 <= R[id]) {
        ranges[id].push_back ({l1, r1, find_bit (l1, r1)});
        return;
    }
    int meio = (l1 + r1) / 2;
    itera (id, l1, meio);
    itera (id, meio + 1, r1);
}


int fast_exp (int b, int e) {
    if (e == 0) return 1;
    int ans = fast_exp (b, e / 2);
    ans = ans * ans % mod;
    if (e & 1) ans = ans * b % mod;
    return ans;
}

void solve() {
    for (int i = 0; i < 3; i++) {
        cin >> L[i] >> R[i];
        itera (i, 0, N - 1);
    }
    int freq[4];
    int ans = 0;
    for (auto &[l1, r1, x1] : ranges[0]) {
        for (auto &[l2, r2, x2] : ranges[1]) {
            for (auto &[l3, r3, x3] : ranges[2]) {
                // dbg (l1, r1, l2, r2, l3, r3);

                bool ok = true;
                freq[0] = freq[1] = freq[2] = freq[3] = 0;
                for (int j = 30; j >= 0; j--) {
                    int f1 = 0;
                    int coringa = 0;
                    if (j > x1) {
                        if ((l1 >> j) & 1) f1++;
                        // M[(l1 >> j) & 1]++;
                    }
                    else coringa++;

                    if (j > x2) {
                        if ((l2 >> j) & 1) f1++;
                        // M[(l2 >> j) & 1]++;
                    }
                    else coringa++;

                    if (j > x3)  {
                        if ((l3 >> j) & 1) f1++;
                        // M[(l3 >> j) & 1]++;
                    }
                    else coringa++;
                    
                    if ((f1 & 1) && !coringa) {
                        ok = false;
                        break;  
                    }
                    freq[coringa]++;
                    // dbg (coringa);
                }
                if (ok) {
                    // dbg (freq[1], freq[2], freq[3]);
                    ans = (ans + (1ll << (freq[2] + 2 * freq[3]))) % mod;
                }
            }
        }
    }

    int baixo = 1;
    for (int i = 0; i < 3; i++)
        baixo = baixo * (R[i] - L[i] + 1) % mod;
    ans = (baixo - ans + mod) % mod;
    // dbg (ans, baixo);
    cout << ans * fast_exp(baixo, mod - 2) % mod << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    // for (int i = 1; i <= 100; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         if (j * fast_exp (i, mod- 2) % mod == 580000005) {
    //             dbg (j, i);
    //             exit (0);
    //         }
    //     }
    // }
    // return 0;
    // queremos 940 / 1000
	solve();
}
