#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) //{ cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define pb push_back

map<string, int> M = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3},
                     {"Thursday", 4}, {"Friday", 5}, {"Saturday", 6}, {"Sunday", 0}};

const int N = 2e5 + 10;

int n, m, k;
vector<int> feriado[7], work[N];

ordered_set<int> worked[N][7];

int work_days (int day, int person) {
    if(day == 0) return 0;
    int ans = 0;

    for (auto d : work[person]) {
        if (d > day || (d == 0 && day < 7)) continue;

        int cima = day - d;
        if (d == 0) cima -= 7;
        ans += cima / 7 + 1;
        // dbg (cima / 7 + 1);
        int j = lower_bound (all(feriado[d]), day + 1) - feriado[d].begin ();
	j += worked[person][d].order_of_key(day + 1) ;
        ans -= j;
    }
    return ans;
}

void solve () {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        int _k; cin >> _k;
        while (_k--) {
            string d; cin >> d;
            work[i].pb (M[d]);
        }
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        feriado[x % 7].pb (x);
    }

    dbg(work_days(5, 3));

    for(int i=0;i<k;i++) {
	int p; cin >> p;
	int cur = 1;
	vector<pair<int,int>> to_work;
	while(p--) {
	    int a; cin >> a;
	    int lo = cur, hi = 1e16;
	    while(lo < hi) {
		int mid = (lo + hi) / 2;
		if(work_days(mid, a) <= work_days(cur-1, a)) lo = mid + 1;
		else hi = mid;
	    }
	    int d = lo;
	    dbg(a, cur, d);
	    to_work.emplace_back(a, d);
	    cur = d + 1;
	}
	for(auto [a, d]: to_work) worked[a][d%7].insert(d);
	cout << cur - 1 << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
