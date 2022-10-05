#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(v) v.begin(), v.end()

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1e5 + 10;

int n, Q, a[N];
int dist[3][N];
queue<int> q[3];

void bfs (int pulo) {
    while (q[pulo].size()) {
        int i = q[pulo].front (); q[pulo].pop ();

        int j = (i - pulo + n) % n;
        if (dist[pulo][j] == 1e9) {
            dist[pulo][j] = dist[pulo][i] + 1;
            q[pulo].push (j);
        }
        j = (i + pulo + n) % n;
        if (dist[pulo][j] == 1e9) {
            dist[pulo][j] = dist[pulo][i] + 1;
            q[pulo].push (j);
        }
    }
}

void solve () {
    for (int i = 0; i < N; i++) dist[0][i] = dist[1][i] = dist[2][i] = 1e9;

    cin >> n >> Q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 2) {
            dist[1][i] = 0;
            q[1].push (i);
        }
        else {
            dist[2][i] = 0;
            q[2].push (i);
        }
    }

    bfs (1);
    bfs (2);

    for (int i = 0; i < n; i++) {
        cout << dist[1][i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << dist[2][i] << " ";
    }
    cout << "\n";
    
    while (Q--) {
        int i, j; cin >> i >> j;
        i--; j--;
        if (a[i] != a[j]) {
            cout << "0\n";
            continue;
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);  cin.tie(0);
	solve();
}
