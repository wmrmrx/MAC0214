#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define pb push_back
#define mp make_pair

const int N = 2e5 + 10;

int n, k, l, a[N], b[N];
multiset<int> good, bad;
int ans, cur;

void insert(int x, int y) {
    cur += x; 
    good.insert(y);
    cur += y;
    
    while (good.size() > l) {
        int val = *good.begin();
        good.erase(good.begin());
        bad.insert(val);
        cur -= val;
    }

    ans = max(ans, cur);
}

void erase(int x, int y) {
    // dbg("erasing", x, y);
    // for (auto val : good) cout << val << " "; cout << endl;
    // for (auto val : bad) cout << val << " "; cout << endl;


    cur -= x;

    auto bit = bad.find(y);
    if (bit != bad.end()) {
        bad.erase(bit);
        return;
    }

    auto gid = good.find(y);
    if (gid != good.end()) {
        cur -= *gid;
        good.erase(gid);
        
        if (!bad.empty()) {
            bit = bad.end();
            bit--;
            good.insert(*bit);
            cur += *bit;
            bad.erase(bit);
        }

        return;
    } 

    assert(0);
}

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    cin >> k >> l;

    for (int i = 1; i <= k; i++) insert(a[i], b[i]);

    for (int i = 1; i <= k; i++) {
        int aid = k-i+1;
        int rid = n-i+1;
        erase(a[aid], b[aid]);
        insert(a[rid], b[rid]);
    }

    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
