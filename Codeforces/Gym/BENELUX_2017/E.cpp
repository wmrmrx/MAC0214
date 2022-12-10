#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) // { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

struct kuhn {
    int n, m;
    vector<vector<int>> g;
    vector<int> vis, ma, mb;

    kuhn(int n_, int m_) : n(n_), m(m_), g(n), vis(n+m), ma(n, -1), mb(m, -1) {}

    void add(int a, int b) {g[a].push_back(b);}

    bool dfs(int i) {
        vis[i] = 1;
        for (int j : g[i]) if (!vis[n+j]) {
            vis[n+j] = 1;
            if (mb[j] == -1 or dfs(mb[j])) {
                ma[i] = j, mb[j] = i;
                return true;
            }
        }
        return false;
    }

    int matching() {
        int ret = 0, aum = 1;
        for (auto& i : g) random_shuffle(i.begin(), i.end());
        while (aum) {
            for (int j = 0; j < m; j++) vis[n+j] = 0;
            aum = 0;
            for (int i = 0; i < n; i++) if (ma[i] == -1 and dfs(i)) ret++, aum = 1;
        }
        return ret;
    }
};

const int MAXN = 300;
int n, b, r;
pair<int, int> pb[MAXN], pr[MAXN];

double dist(pair<int, int> p1, pair<int, int> p2) {
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return sqrt(dx*dx + dy*dy);
}

bool test(double cut) {
    auto myg = kuhn(b, r);
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < r; j++) {
            if (dist(pb[i], pr[j]) < cut) {
                myg.add(i, j);
            }
        }
    }
    int match = myg.matching();
    dbg(cut, match);
    return (b + r - match >= n);
}

double bb(double L, double R) {
    for (int k = 0; k < 60; k++) {
        double mid = (L+R) / 2;
        if (test(mid)) L = mid;
        else R = mid;
    }
    return (L+R)/2;
}

void solve () {
    cin >> n >> b >> r;
    for (int i = 0; i < b; i++) cin >> pb[i].first >> pb[i].second;
    for (int i = 0; i < r; i++) cin >> pr[i].first >> pr[i].second;

    double ans = bb(0, 1e9);
    cout << setprecision(10) << fixed;
    cout << ans;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
