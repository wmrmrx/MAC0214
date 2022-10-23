#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	vector<int> sa(n), xa(n);
	for(int &i: a) cin >> i;
	
	partial_sum(all(a), sa.begin());
	partial_sum(all(a), xa.begin(), bit_xor<int>());

	auto get_sum = [&](int l, int r) {
		return sa[r] - (l ? sa[l-1] : 0);
	};
	auto get_xor = [&](int l, int r) {
		return xa[r] xor (l ? xa[l-1] : 0);
	};
	auto get = [&](int l, int r) {
		return get_sum(l, r) - get_xor(l, r);
	};
	while(q--) {
		int _l, _r; cin >> _l >> _r;
		const int l = _l-1, r = _r-1;

		int mx = get(l, r);

		if(mx == 0) {
			cout << l+1 << ' ' << l+1 << '\n';
			continue;
		}

		array<int, 2> ans{l, r};

		int j = r;
		while(j-1 >= l && get(l, j-1) == mx) j--;
		for(int i=l;i<=r;i++) {
			j = max(j, i);
			while(j <= r && get(i, j) < mx) j++;
			if(j > r) break;
			if(ans[1] - ans[0] > j - i) {
				ans = {i, j};
			}
		}
		cout << ans[0] + 1 << ' ' << ans[1] + 1 << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
