#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() {cerr << endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr <<' '<< h; dbg_out(t...); }
#define dbg(...) // { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

namespace seg {
	int n;
	vector<pair<int, int>> mn;
	void init(int _n) {
		n = _n;
		mn.assign(4*n+1, pair<int,int>{1e9, -1});
	}

	void update(int pos, int val, int cur=1, int cl=0, int cr=n-1) {
		if(pos < cl || cr < pos) return;
		if(cl == cr) {
			mn[cur] = {val, pos};
			return;
		}
		int m = (cl + cr) / 2;
		update(pos, val, 2*cur, cl, m);
		update(pos, val, 2*cur+1, m+1, cr);
		mn[cur] = min(mn[2*cur], mn[2*cur+1]);
	}

	pair<int,int> query(int ql, int qr, int cur=1, int cl=0, int cr=n-1) {
		if(qr < cl || cr < ql) {
			return {1e9, -1};
		}
		if(ql <= cl && cr <= qr) {
			return mn[cur];
		}
		int m = (cl + cr) / 2;
		return min(
			query(ql, qr, 2*cur, cl, m),
			query(ql, qr, 2*cur+1, m+1, cr)
		);

	}
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &i: a) cin >> i;
	seg::init(n);
	for(int i=0;i<n;i++) seg::update(i, a[i]);
	for(int i=0;i<n;i++) {
		assert(bool(seg::query(i,i) == pair<int,int>(a[i], i)));
	}

	set<int> act;
	int ans = 0;

	auto add = [&](int idx) {
		auto [it, _ignore] = act.insert(idx);
		dbg("ADD", idx);
		auto nit = next(it);
		if(nit == act.end()) {
			ans += a[idx] * n;
		} else {
			ans += (a[idx] - a[*nit]) * (*nit);
		}
		if(it != act.begin()) {
			auto pit = prev(it);
			if(nit == act.end()) {
				ans -= a[*pit] * n;
			} else {
				ans -= (a[*pit] - a[*nit]) * (*nit);
			}
			ans += (a[*pit] - a[idx]) * (idx);
		}
	};
	auto rm = [&](int idx) {
		auto it = act.find(idx);
		dbg("RM", idx);
		auto nit = next(it);
		if(nit == act.end()) {
			ans -= a[idx] * n;
		} else {
			ans -= (a[idx] - a[*nit]) * (*nit);
		}
		if(it != act.begin()) {
			auto pit = prev(it);
			ans -= (a[*pit] - a[idx]) * (idx);
			if(nit == act.end()) {
				ans += a[*pit] * n;
			} else {
				ans += (a[*pit] - a[*nit]) * (*nit);
			}
		}
		act.erase(idx);
	};

	{
		add(0);
		int l = 0;
		for(int i=1;i<n;i++) {
			if(a[i] < a[l]) {
				add(i);
				l = i;
			}
		}
	}

	cout << ans << endl;

	int q; cin >> q;
	while(q--) {
		int p, v; cin >> p >> v;
		auto it = act.find(v);
		dbg(it == act.end() ? -1 : *it);
		if(p == 1) {
			seg::update(v, a[v]+1);
			if(it != act.end()) {
				rm(v); a[v]++; add(v);
				it = act.find(v);
				if(it != act.begin()) {
					auto pit = prev(it);
					if(a[*pit] == a[v])
						rm(v);
					dbg(p, v);
				}
				if(v == n-1) {
					cout << ans << endl;
					continue;
				}
				// dbg(p, v);
				auto nit = act.upper_bound(v);
				// dbg(nit == act.end());
				auto [val, pos] = seg::query(v, nit != act.end() ? (*nit)-1 : n-1);
				dbg (val, pos);
				if(pos != v) {
					add(pos);
				}
			} else {
				a[v]++;
				cout << ans << endl;
				continue;
			}
		} else if(p == 2) {
			seg::update(v, a[v]-1);
			if(it != act.end()) {
				rm(v); a[v]--; add(v);
				auto nit = next(act.find(v));
				if(nit != act.end() && a[*nit] == a[v]) {
					rm(*nit);
				}
			} else {
				a[v]--;
				int l = *prev(act.lower_bound(v));
				if(a[l] > a[v]) {
					add(v);
					auto nit = next(act.find(v));
					if(nit != act.end() && a[*nit] == a[v])
						rm(*nit);
				}
				auto x = act.upper_bound(v);
				if(x != act.end() 
						&& a[*x] == a[v]) rm(*x);
			}
		}
		cout << ans << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
