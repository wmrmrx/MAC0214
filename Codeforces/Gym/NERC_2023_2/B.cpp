#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define pb push_back

const int N = 1e3 + 10;

int n, k;
int ans[N];
vector<int> records[N];
vector<int> pos[N];

void find_CEO (vector<int> &v, int p) {
    // dbg (p);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        pos[i].clear ();
        tot += v[i];
    }
    
    vector<int> leaf (n + 1);
    for (int i = 0; i < k; i++) {
        int fst = -1, last = -1;
        int shift = 0;
        for (int j = 0; j < n; j++) {
            if (fst == -1) shift++;

            if (v[records[i][j]]) {
                pos[records[i][j]].pb (j - shift);
                last = records[i][j];
                if (fst == -1) fst = records[i][j];
            }
        }

        leaf[fst]++;
        leaf[last]++;
    }

    if (tot == 1) {
        for (int i = 1; i <= n; i++)
            if (v[i]) {
                ans[i] = p;
                return;
            }
    }

    pair<int, int> mn = {100000, 100000};
    for (int i = 1; i <= n; i++) {
        sort (all (pos[i]));
        pos[i].resize(unique (all (pos[i])) - pos[i].begin());

        if (pos[i].size () && !leaf[i])
            mn = min (mn, {pos[i].size (), i});
    }

    vector<int> candidates;
    for (int i = 1; i <= n; i++)
        if (pos[i].size () == mn.first && !leaf[i]) candidates.pb (i);

    auto gen_son = [&] (int i, int CEO) {
        vector<int> l (n + 1), r (n + 1);
        bool ok = true;
        for (int j = 0; j < n; j++) {
            int u = records[i][j];
            if (u == CEO) ok = false;
            else if (ok && v[u]) l[u]++;
            else if (!ok && v[u]) r[u]++;
        }
        return make_pair (l, r);
    };

    // dbg (p);

    for (auto CEO : candidates) {
        auto it = gen_son (0, CEO);
        bool ok = true;
        // dbg (CEO);
        for (int i = 1; i < k; i++) {
            auto it1 = gen_son (i, CEO);
            if ((it.first == it1.first && it.second == it1.second) || 
                (it.first == it1.second && it.second == it1.first)) {

                }
            else {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans[CEO] = p;
            find_CEO (it.first, CEO);
            find_CEO (it.second, CEO);
            return;
        }
    }
}

void solve () {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            records[i].pb (x);
        }
    }

    vector<int> v (n + 1, 1);
    find_CEO (v, -1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
