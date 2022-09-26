#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int MAXN = 4e5+5;
int v[MAXN], last[MAXN];
string s1, s2;
int n;

void solve() {
    cin >> n;
    
    cin >> s1;
    cin >> s2;

    last[n] = n;
    for (int i = n-1; i >= 0; i--) {
        if (s1[i] == s2[i]) {
            v[i] = 0;
            last[i] = last[i+1];
        }
        else if (s1[i] < s2[i]) {
            v[i] = 1;
            last[i] = i;
        }
        else {
            v[i] = -1;
            last[i] = n;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        // cout << last[i] << " ";
        ans += (n-last[i]);
    }

    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
