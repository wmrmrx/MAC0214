#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

const int MAXN = 2e5+5;
vector<int> buck[MAXN];
int rep[MAXN];
int n;

int find(int a) {
    if (rep[a] == a) return a;
    return rep[a] = find(rep[a]);
}

void une(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (rand()&1) swap(a, b);
    rep[a] = b;
}

void solve() {
    cin >> n;

    for (int i = 0; i < MAXN; i++) {
        rep[i] = i;
        buck[i].clear();
    }

    for (int i = 1; i <= n; i++) {
        int cur;
        cin >> cur;
        for (int x = 1; x*x <= cur; x++) {
            if (cur % x == 0) {
                buck[x].push_back(i);
                buck[cur/x].push_back(i);
            }
        }
    }

    long long ans = 0;
    for (int i = MAXN-1; i >= 0; i--) {
        for (int j = 1; j < buck[i].size(); j++) {
            int cur = buck[i][j];
            int last = buck[i][j-1];
            if (find(cur) == find(last)) continue;
            une(cur, last);
            ans += i;
        }
    }

    cout << ans;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("dream.in", "r", stdin);
	int t;
    cin >> t;
    for (int ddd = 1; ddd <= t; ddd++) {
        cout << "Case " << ddd << ": ";
        solve();   
        cout << "\n";
    }
}
