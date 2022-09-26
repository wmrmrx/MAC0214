#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int n;
string s;

void solve() {
    cin >> n >> s;
    vector<int> freq(3);
    for (auto u : s)
        freq[u - 'A']++;
    n *= 2;
 
    // dbg (freq[0], freq[1], freq[2]);

    int dif = freq[0] - freq[2];
    
    int dir = (dif + freq[1]) / 2, esq = (freq[1] - dif) / 2;
    // dbg (esq, dir);
    if (esq < 0 || dir < 0) {
        cout << "NO\n";
        return;
    }

    // vamos pegar os esq B's e parear com os C's
    vector<pair<int, int>> ans;
    vector<int> pos_B, jafoi(n + 10);
    for (int i = 0; i < n; i++) {
        char u = s[i];
        if (u == 'B' && esq) {
            esq--;
            pos_B.push_back (i);
        }
        if (u == 'C' && pos_B.size()) {
            ans.push_back ({pos_B.back(), i});
            jafoi[pos_B.back()]++;
            jafoi[i]++;
            // dbg (pos_B.back());
            pos_B.pop_back();
        }
        // dbg (i);
        // for (auto x : pos_B)
        //     cout << x << " ";
        // cout << "\n";
    }
    // for (auto [u, v] : ans)
    //     dbg (u, v);
    vector<int> pos_A;
    for (int i = 0; i < n; i++) {
        char u = s[i];
        // dbg (u);
        if (u == 'A') {
            pos_A.push_back (i);
        }
        else if (!jafoi[i]) {
            if (!pos_A.size()) {
                cout << "NO\n";
                return;
            }
            ans.push_back ({pos_A.back(), i});
            pos_A.pop_back();
        }
    }
    if (pos_A.size()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto [u, v] : ans)
        cout << u + 1 << " " << v + 1 << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
