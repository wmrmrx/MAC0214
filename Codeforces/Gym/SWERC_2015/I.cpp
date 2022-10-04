#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1e5 + 10;

int END;
int q, w;

template <typename T> struct RMQ {
    vector<vector<T>> dp;
    T ops(T a, T b) { return min(a,b); }
    RMQ() {}
    RMQ(int sz, T v[]) {
        int log = 64-__builtin_clzll(sz);
        dp.assign(log, vector<T>(sz));
        for(int i=0;i<sz;i++) dp[0][i] = v[i];
        for(int l=1;l<log;l++) for(int i=0;i<sz;i++) 
          dp[l][i] = ops(dp[l-1][i],dp[l-1][min(i+(1<<(l-1)), sz-1)]);
    }
    T query(int a, int b) {
        if(a==b) return min(w , dp[0][a]);
        int pot = 63-__builtin_clzll(b-a);
        return min(w, ops(dp[pot][a], dp[pot][b-(1<<pot)+1]));
    }
};

struct SuffixArray {
    string s;
    vector<int> sa, lcp;
    SuffixArray () {}
    SuffixArray (vector<string> v, int lim = 256) {
        for (auto str : v) {
            s += str;
            s += '$';
        }
        int n = s.size(), k = 0, a, b;
        vector<int> x(all(s) + 1), y(n), ws(max(n, lim)), rank (n);
        sa = lcp = y, iota (all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max (1ll, j * 2), lim = p) {
            p = j, iota (all(y), n - j);
            for (int i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill (all (ws), 0);
            for (int i = 0; i < n; i++) ws[x[i]]++;
            for (int i = 1; i < lim; i++) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap (x, y), p = 1, x[sa[0]] = 0;
            for (int i = 1; i < n; i++) a = sa[i - 1], b = sa[i], x[b] =
                (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for (int i = 1; i < n; i++) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k) 
            for (k && k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);
    }
};

string s;

void solve () {
    cin >> s;
    SuffixArray SA ({s});

    int n = s.size();

    cin >> q >> w;
    if (w == 1) {
        for (int i = 1; i <= q; i++) {
            int x; cin >> x;
            cout << "1\n";
        }
        return;
    }

    vector<int> memo (n + 10);
    // memo[i] = num subtrings de [i, i + w - 1]
    vector<int> inv (n + 10);
    for (int i = 0; i <= n; i++) inv[SA.sa[i]] = i;

    RMQ<int> rmq (SA.lcp.size(), SA.lcp.data());

    int cur = 0;
    set<int> pos;
    for (int i = 0; i < w; i++) {
        pos.insert (inv[i]);
    }
    for (auto it = pos.begin(); next(it) != pos.end(); it++) {
        int x = *it, y = *next (it);
        cur += rmq.query(x + 1, y);
    }
    // dbg (cur);
    // dbg (w * w - (w - 1) * w / 2 - cur);
    
    auto add = [&] (int i) {
        auto it = pos.lower_bound (inv[i]);
        if (it == pos.end()) {
            int l = *pos.rbegin ();
            cur += rmq.query (l + 1, inv[i]);
        }
        else if (it == pos.begin()) {
            int r = *pos.begin ();
            cur += rmq.query (inv[i] + 1, r);
        }
        else {
            int l = *prev (it), r = *it;
            cur -= rmq.query (l + 1, r);
            cur += rmq.query (l + 1, inv[i]);
            cur += rmq.query (inv[i] + 1, r); 
        }
        pos.insert (inv[i]);
    };
    auto rem = [&] (int i) {
        auto it = pos.find (inv[i]);
        if (next(it) == pos.end()) {
            int l = *prev(it);
            cur -= rmq.query (l + 1, inv[i]);
        }
        else if (it == pos.begin()) {
            int r = *next (it);
            cur -= rmq.query (inv[i] + 1, r);
        }
        else {
            int l = *prev (it), r = *next (it);
            cur += rmq.query (l + 1, r);
            cur -= rmq.query (l + 1, inv[i]);
            cur -= rmq.query (inv[i] + 1, r); 
        }
        pos.erase (inv[i]);
    };

    memo[0] = cur;
    for (int r = w; r < n; r++) {
        add (r);
        rem (r - w);
        memo[r - w + 1] = cur;
    }

    for (int i = 1; i <= q; i++) {
        int x; cin >> x;
        cout << w * w - (w - 1) * w / 2 - memo[x - 1] << "\n";
    }

    // W * W - (W - 1) * W / 2 - sum (SA.lcp)
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
