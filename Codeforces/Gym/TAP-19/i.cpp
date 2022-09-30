#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h,T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int BASE = 1e4+3;
const int MAXN = 2e4+9;
bitset<MAXN> bit[MAXN];
int n, m, q;

void update(int id, int i) {
    while (i < MAXN) {
        bit[id][i] = !bit[id][i];
        i += (i&-i);
    }
}

bool query(int id, int i) {
    bool ans = 0;
    while (i > 0) {
        ans ^= bit[id][i];
        i -= (i&-i);
    }
    return ans;
}


void solve() {
    cin >> n >> m >> q;
    while (m--) {
        int k, a, b;
        cin >> k >> a >> b;
        if (a > b) swap(a, b);
        int id = a-b+BASE;
        update(id, a);
        update(id, a+k);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int id = a-b+BASE;
        bool ans = query(id, a);
        if (ans) cout << "SI\n";
        else cout << "NO\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
