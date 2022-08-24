#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// iterator find_by_order(size_t index), size_t order_of_key(T key)
template <typename T>
using ordered_set=__gnu_pbds::tree<T, __gnu_pbds::null_type,std::less<T>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr int MAX = 300'001;

ordered_set<int> occ[MAX];

using lim = numeric_limits<int>;

int c[MAX], x[MAX], inv[MAX];

void solve() {
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> c[i];
	for(int i=1;i<=n;i++) cin >> x[i];
	for(int i=1;i<=n;i++) occ[c[i]].insert(i);

	ordered_set<pair<int,int>> tot;
	vector<ordered_set<pair<int,int>>> os(MAX+1);
	for(int i=1;i<=n;i++) {
		// num of bigger
		inv[i] = i - 1 - tot.order_of_key({x[i], lim::max()});
		// minus num of bigger of same color
		inv[i] -= (os[c[i]].size() - os[c[i]].order_of_key({x[i], lim::max()}));
		tot.insert({x[i], i});
		os[c[i]].insert({x[i], i});
	}

	//for(int i=1;i<=n;i++) cerr << inv[i] << " \n"[i==n];

	vector<pair<int,int>> ord; ord.reserve(n);
	for(int i=1;i<=n;i++) ord.emplace_back(x[i], i);

	sort(all(ord));

	int ans = 0;

	for(int ra=1;ra<=n;ra++) {
		auto [_, i] = ord[ra-1];
		ans += inv[i];
		occ[c[i]].erase(i);
	}

	cout << ans << endl;

}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
