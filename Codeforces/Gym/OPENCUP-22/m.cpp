#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(v) v.begin(), v.end()

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
//#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
#define dbg(...)

constexpr int MAX = 1'000'000;
constexpr int DMAX = 2'000'000;

template <size_t N>
struct arr: array<int, N> {
	void operator+=(arr<N> rhs) {
		for(size_t i=0;i<N;i++) (*this)[i] += rhs[i];
	}
	arr<N> operator-(arr<N> rhs) {
		arr<N> ret = (*this);
		for(size_t i=0;i<N;i++) ret[i] -= rhs[i];
		return ret;
	}
};

template <typename T>
struct fenwick {
	vector<T> bit;
	fenwick(int n): bit(n+1) {}

	void update(int id, T val) {
		while(id < bit.size()) {
			bit[id] += val;
			id += id&-id;
		}
	}

	T query(int id) {
		T res;
		res.fill(0);
		while(id > 0) {
			res += bit[id];
			id -= id&-id;
		}
		return res;
	}

	T get(int l, int r) {
		if(r < l) return query(0);
		return query(r) - query(l-1);
	}
};

void solve() {
	int n; cin >> n;
	vector<pair<int,int>> pts(n);
	for(int i=0;i<n;i++) cin >> pts[i].first;
	for(int i=0;i<n;i++) cin >> pts[i].second;

	auto diag = [](int x, int y) {
		return x - y + MAX;
	};

	// [0] is x [1] is y [2] is num
	fenwick<arr<2>> fx(MAX), fy(MAX);
	fenwick<arr<3>> fd(DMAX);

	auto cmp = [](pair<int,int> a, pair<int,int> b) -> bool {
		int sa = a.first + a.second, sb = b.first + b.second;
		if(sa == sb) return a.second < b.second;
		else return sa < sb;
	};

	sort(all(pts), cmp);	

	int ans = 0;

	auto add = [&](int x, int y) {
		arr<2> fxv; fxv[0] = x; fxv[1] = 1;
		fx.update(x, fxv);
		arr<2> fyv; fyv[0] = y; fyv[1] = 1;
		fy.update(y, fyv);
		arr<3> fdv; fdv[0] = x; fdv[1] = y; fdv[2] = 1;
		fd.update(diag(x, y), fdv);
	};

	for(auto& [x, y]: pts) {

		dbg(x, y);

		auto fx1 = fx.get(x, MAX);
		int sx1 = fx1[0], nx1 = fx1[1];

		auto fx2 = fd.get(diag(x,y), DMAX);
		int sx2 = fx2[0], nx2 = fx2[2];
		dbg(sx2, nx2);

		sx2 -= sx1; nx2 -= nx1;
		ans += sx1 - x*nx1;
		ans -= sx2 - x*nx2;

		auto fy1 = fy.get(y, MAX);
		int sy1 = fy1[0], ny1 = fy1[1];

		auto fy2 = fd.get(1, diag(x,y)-1);
		int sy2 = fy2[1], ny2 = fy2[2];

		sy2 -= sy1; ny2 -= ny1;
		ans += sy1 - y*ny1;
		ans -= sy2 - y*ny2;

		dbg(sx1, sx2, nx1, nx2, sy1, sy2, ny1, ny2);

		dbg(ans);

		add(x, y);

	}
	cout << 2*ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);  cin.tie(0);
	solve();
}
