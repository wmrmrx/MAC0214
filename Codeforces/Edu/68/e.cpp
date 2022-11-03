#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) // { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

struct Fenwick {
	vector<int> bit;
	Fenwick(int sz): bit(sz+1) {}

	void update(int id, int val) {
		while(id < bit.size()) {
			bit[id] += val;
			id += id&-id;
		}
	}

	int query(int id) {
		int res = 0;
		while(id > 0) {
			res += bit[id];
			id -= id&-id;
		}
		return res;
	}

	int query(int l, int r) {
		return query(r+1) - query(l);
	}
};

constexpr size_t MAX = 100001;

vector<tuple<int,int,int>> a, b;

void solve() {
	int n; cin >> n;
	for(int i=0;i<n;i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 5000;
		x2 += 5000;
		y1 += 5000;
		y2 += 5000;
		if(x1 == x2) {
			if(y1 > y2) swap(y1, y2);
			a.emplace_back(x1, y1, y2);
		} else {
			if(x1 > x2) swap(x1, x2);
			b.emplace_back(y1, x1, x2);
		}
	}
	Fenwick act(MAX);
	vector<tuple<int,int,int,int>> ev;
	int ans = 0;
	for(int i=0;i<a.size();i++) {
		ev.clear();
		auto &[ax, aly, ary] = a[i];
		dbg(i, ax, aly, ary);
		for(auto &[by, blx, brx]: b) {
			if(aly <= by && by <= ary &&
				blx <= ax && ax <= brx) {
				dbg(by, blx, brx);
				ev.emplace_back(blx, 0, 0, by);
				ev.emplace_back(brx+1, 0, 1, by); }
		}
		for(int j=i+1;j<a.size();j++) {
			auto& [jx, jly, jry] = a[j];
			ev.emplace_back(jx, 1, jly, jry);
		}
		sort(all(ev));
		for(auto &[__ignore, type, l, r]: ev) {
			dbg(__ignore, type, l, r);
			if(type == 0) {
				act.update(r+1, l == 0 ? 1 : -1);
			} else {
				int res = act.query(l, r);
				dbg(res);
				ans += res*(res-1)/2;
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
