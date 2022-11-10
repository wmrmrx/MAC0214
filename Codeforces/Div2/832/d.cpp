#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...){ cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void solve() {
	int n, q;  cin >> n >> q;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin >> a[i];
	vector<int> pxor(n+1), psum(n+1);
	partial_sum(all(a), psum.begin());
	partial_sum(all(a), pxor.begin(), bit_xor<int>());

	map<int, vector<int>> occ[2];
	for(int i=0;i<=n;i++) {
		auto it = occ[i%2].find(pxor[i]);
		if(it == occ[i%2].end()) {
			occ[i%2][pxor[i]] = vector<int>();
			it = occ[i%2].find(pxor[i]);
		}
		it->second.push_back(i);
	}

	while(q--) {
		int l, r; cin >> l >> r;
		if((pxor[r] xor pxor[l-1]) != 0) {
			cout << -1 << '\n';
			continue;
		}

		if(psum[r] - psum[l-1] == 0) {
			cout << 0 << '\n';
			continue;
		}

		if((r-l+1)%2 == 1) {
			cout << 1 << '\n';
			continue;
		}

		if(a[l] == 0 || a[r] == 0) {
			cout << 1 << '\n';
			continue;
		}

		if(occ[l%2].find(pxor[l-1]) == occ[l%2].end()) {
			cout << -1 << '\n';
			continue;
		}

		const auto &v = occ[l%2][pxor[l-1]];
		auto it = upper_bound(all(v), l-1);
		if(it == v.end() || *it > r) {
			cout << -1 << endl;
			continue;
		}
		cout << 2 << '\n';
		continue;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
