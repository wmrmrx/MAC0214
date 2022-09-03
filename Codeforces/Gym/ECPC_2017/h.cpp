#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

const int MAXN = 5e6+5;
int prime[MAXN], p10[20];
int L, R;

int get_len(int val) {
    for (int i = 1; i < 20; i++) {
        if (val < p10[i]) return i;
    }
    assert(0);
}

int get_pos(int val, int len) {
    return val % p10[len];
}

int get_pre(int val, int len) {
    int n = get_len(val);
    for (int i = 1; i <= n-len; i++) val /= 10;
    return val;
}

void crivo() {
    for (int i = 0; i < MAXN; i++) prime[i] = i;

    for (int i = 2; i < MAXN; i++) {
        if (prime[i] != i) continue;
        for (int j = 2*i; j < MAXN; j += i) {
            prime[j] = min(prime[j], i);
        }
    }
}

int find_best(const int pre, const int maxpos, int shift) {
    int ans = -1;
    int cur = pre;
    while (cur > 1) {
        int candidate = (maxpos/prime[cur]) * prime[cur];
        int val = pre*p10[shift] + candidate;
        // dbg(val, candidate, pre);
        if (val >= L && val <= R && candidate != 0 && __gcd(candidate, pre) > 1) ans = max(ans, val);
        int p = prime[cur];
        assert(p != 0);
        while (prime[cur] == p) cur /= p;
    }
    // dbg(pre, maxpos, ans);
    return ans;
}

int calc(int val, bool keep_pos) {
    if (val < 10) return -1;
    int n = get_len(val);
    if (!keep_pos) {
        val -= get_pos(val, n-(n/2));
        val += p10[n-(n/2)]-1;
    }
    // cout << "chama " << val << endl;
    int ans = find_best(get_pre(val, n/2), get_pos(val, n-(n/2)), n-(n/2));
    // dbg(val, keep_pos, ans);
    return ans;
} 

void solve() {
    cin >> L >> R;
    
    int cur = R;

    int ans = -1;

    ans = max(ans, calc(cur, true));
    
    for (int i = 0; i < 3; i++) {
        int n = get_len(cur);
        cur -= p10[n/2];
        cur
        dbg(cur, n);
        // if (n - n/2 == 2) cur += 90;
        ans = max(ans, calc(cur, false));
    }

    // for (int i=0;i<3;i++) {
    //     int n = get_len(R);
    //     R -= p10[n-n/2];
    //     int m = get_len(R);
    //     if (n != m) {
            
    //     }
    // }



    if (ans < 10) {
        cout << "impossible";
    }
    else {
        cout << ans;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("halfnice.in", "r", stdin);
	
    p10[0] = 1;
    for (int i = 1; i <= 18; i++) p10[i] = p10[i-1]*10;
    crivo();
    
    int t; cin >> t;
  	for(int i=1;i<=t;i++) {
		cout << "Case " << i << ": ";
		solve();
		cout << '\n';
	}
}
