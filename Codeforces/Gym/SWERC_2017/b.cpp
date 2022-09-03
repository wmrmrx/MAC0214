#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

const int MAXN = 2e3+5;
const int MAXQ = 1e5+6;
const int INF = 1e9+9;
int table[MAXN][MAXN], expand[MAXN][MAXN][2];
int n, m, D, q;

vector<tuple<int, int, int>> events;
int ans[MAXQ];
int bit[MAXN];

void update(int ind, int val) {
    while (ind < MAXN) {
        bit[ind] += val;
        ind += ind&-ind;
    }
}

int query(int ind) {
    int ans = 0;
    while (ind > 0) {
        ans += bit[ind];
        ind -= ind&-ind;
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    cin >> D;
    cin >> q;
    for (int i = 0; i < D; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i < b; i++) {
            for (int j = c; j < d; j++) {
                table[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            expand[i][j][0] = (i==0) ? 1 : expand[i-1][j][0]+1;
            expand[i][j][1] = (j==0) ? 1 : expand[i][j-1][1]+1;

            if (table[i][j]) {
                expand[i][j][0] = 0;
                expand[i][j][1] = 0;
            }
            
            events.push_back({expand[i][j][0], expand[i][j][1], INF});

            // cout << table[i][j];
            // cout << expand[i][j][1];
        }
        // cout << endl;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, b, i});
    }
    
    sort(all(events));
    reverse(all(events));

    for (auto event : events) {
        int a, val, id;
        tie(a, val, id) = event;
        dbg(id, a, val);
        if (id > q) {
            // update
            update(val+1, 1);
        }
        else {
            // query
            ans[id] = query(val+1);
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
