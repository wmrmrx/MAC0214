#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

const int MAXN = 5e3+5;
int n, m;
int va[MAXN], 

point proj(segment r, point p) {
	auto [a, b] = r;
	p = p - a;
	point v = b-a;
	return a + v*((p*v)/(v*v));
}vb[MAXN];
map<int, int> mp;

void solve() {
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) cin >> va[i];
    for (int i = 1; i <= m; i++) cin >> vb[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mp[vb[j]-va[i]]++;
        }
    }

    int ans = 0; int best = -1;
    for (auto mit : mp) {
        if (mit.first > 0 && mit.second > best) {
            best = mit.second;
            ans = mit.first;
        }
    }

    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
