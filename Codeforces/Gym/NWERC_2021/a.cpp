#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() {cerr <<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){ cerr << ' ' << h; dbg_out(t...);}
#define dbg(...) // { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int n = 0;
vector<char> moves;

int query(string s) {
    cout << s << endl;

    string aux;
    cin >> aux;
    cin >> aux;
    if (aux[0] == 'G') return 1e8;
    char caux;
    cin >> caux;
    int val;
    cin >> val;
    cin >> aux;
    dbg(val);
    return val;
}

void solve() {
    for (char c = 'a'; c <= 'z'; c++) moves.push_back(c);
    for (char c = 'A'; c <= 'Z'; c++) moves.push_back(c);
    for (char c = '0'; c <= '9'; c++) moves.push_back(c);


    int worst_t = 0;
    string ans = "";
    for (int i = 1; i <= 20; i++) {
        ans += 'x';
        int val = query(ans);
        if (val >= 1e8) return;
        if (val > worst_t) {
            n = i;
            worst_t = val; 
        }
    }
    dbg(n);

    ans.resize(n);

    for (int i = 0; i < n; i++) {
        worst_t = 0;
        char worst_c = 0;
        for (auto c : moves) {
            ans[i] = c;
            int val = query(ans);
            if (val >= 1e8) return;
            if (val > worst_t) {
                worst_c = c;
                worst_t = val;
            }
        }
        ans[i] = worst_c;
    }

    cout << ans << endl;
    fflush(stdout);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
