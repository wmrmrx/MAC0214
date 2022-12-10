#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int MAXN = 5e5+5;
unordered_map<int, int> mp;
int n;

void solve() {
    cin >> n;
    vector<int> v, aux;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        mp[x] = 1;
    }

    while (v.size() > 1) {
        aux.clear();
        for (int i = 0; i < v.size()-1; i++) {
            int cur = __gcd(v[i], v[i+1]);
            mp[cur] = 1;
            if (aux.empty() || aux.back() != cur) {
                aux.push_back(cur);
            }
        }
        swap(v, aux);
    }

    mp[v[0]] = 1;
    mp[aux[0]] = 1;

    cout << mp.size() << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
