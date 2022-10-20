#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
//#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
#define dbg(...)

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int h, w; cin >> h >> w;
	int rs, cs; cin >> rs >> cs;
	array<int, 2> pos{rs, cs};
	int n; cin >> n;
	vector<array<int,2>> walls(n);
	for(auto &[r, c]: walls) cin >> r >> c;

	int q; cin >> q;

	array<map<int, vector<int>>, 2> blk;

	for(auto &v: walls) {
		for(int b: {0, 1}) {
			auto& cur = blk[b];
			if(cur.find(v[b]) == cur.end()) {
				cur[v[b]] = vector<int>();
			}
			cur[v[b]].push_back(v[!b]);
		}
	}

	for(auto &cur: blk) {
		for(auto &[key, val]: cur) {
			sort(all(val));
		}
	}

	for(int i=0;i<q;i++) {
		char c; int len;
		cin >> c >> len;

		bool fixed_dir = c == 'U' || c == 'D';
		int sign = 1;
		if(c == 'L' || c == 'U') sign = -1;

		dbg(fixed_dir, sign, len);

		const auto &fixed = pos[fixed_dir];
		auto &var = pos[!fixed_dir];

		if(blk[fixed_dir].find(fixed) != blk[fixed_dir].end()) {
			auto& v = blk[fixed_dir][fixed];

			if(sign == 1) {
				auto it = lower_bound(all(v), var);
				int wall = it == v.end() ? numeric_limits<int>::max() : *it;
				var = min(var + len, wall - 1);
			} else {
				auto it = lower_bound(all(v), var);
				int wall = it == v.begin() ? numeric_limits<int>::min() : *prev(it);
				var = max(var - len, wall + 1);
			}
		} else {
			var += sign*len;
		}

		pos[0] = max<int>(1, pos[0]);
		pos[0] = min<int>(h, pos[0]);
		pos[1] = max<int>(1, pos[1]);
		pos[1] = min<int>(w, pos[1]);

		cout << pos[0] << ' ' << pos[1] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
