#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

#define mp make_pair
#define pb push_back

const int N = 1e5 + 10;

struct SuffixArray {
    string s;
    vector<int> sa, lcp;
    SuffixArray () {}
    SuffixArray (vector<string> &v, int lim = 256) {
        for (auto str : v) {
            s += str;
            s += '$';
        }
        int n = s.size(), k = 0, a, b;
        vector<int> x(all(s) + 1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = y, iota (all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            for (int i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            for (int i = 0; i < n; i++) ws[x[i]]++;
            for (int i = 1; i < lim; i++) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap (x, y), p = 1, x[sa[0]] = 0;
            for (int i = 1; i < n; i++) a = sa[i - 1], b = sa[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for (int i = 1; i < n; i++) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);
    }
};

void 

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("evaluations.in", "r", stdin);
	int t; cin >> t;
	for(int i=1;i<=t;i++) {
		cout << "Case " << i << ": ";
		// solve();
	}
}
