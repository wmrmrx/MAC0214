#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr size_t MAXN = 200'001;

set<int> xs;
vector<int32_t> active[MAXN];
vector<int64_t> kvals, xvals;

int kget_id(int k) {
	auto it = lower_bound(all(kvals), k);
	return it - kvals.begin();
};

int xget_id(int x) {
	auto it = lower_bound(all(xvals), x);
	return it - xvals.begin();
};

struct Intervals {
	set<pair<int32_t,int32_t>> inner;
	int32_t kid;

	Intervals(): kid(1e9) {}

	void erase(int xid) {
		if(inner.empty()) return;
		int cur = xvals[xid] / kvals[kid];
		auto [l, r] = *prev(inner.upper_bound({cur, cur}));
		inner.erase({l, r});
		if(l <= cur-1) {
			inner.emplace(l, cur-1);
		}
		if(cur+1 <= r) {
			inner.emplace(cur+1, r);
		}
	}

	void update() {
		int cur = query(), k = kvals[kid];
		while(xs.find(cur*k) != xs.end()) {
			int xid = xget_id(cur*k);
			active[xid].push_back(kid);
			if(cur == 1) {
				if(!inner.empty() && inner.begin()->first == 2) {
					int r = inner.begin()->second;
					inner.erase(inner.begin());
					inner.emplace(1, r);
				} else {
					inner.emplace(1, 1);
				}
			} else {
				auto it = inner.upper_bound({cur, cur});
				auto pit = prev(it);
				auto [l, inr] = *pit;
				auto [inl, r] = *it;
				if(inr + 1 == inl - 1) {
					inner.erase({l, inr});
					inner.erase({inl, r});
					inner.emplace(l, r);
				} else {
					inner.erase({l, inr});
					inner.emplace(l, inr+1);
				}
			}
			cur = query();
		}
	}

	int query() {
		if(inner.empty()) return 1;
		else {
			auto [l, r] = *inner.begin();
			if(l == 1) return r+1;
			else return 1;
		}
	}
};

Intervals intervals[MAXN];

void solve() {
	int q; cin >> q;
	vector<tuple<char,int>> queries;

	for(int qq=0;qq<q;qq++) {
		char ops; cin >> ops;
		int num; cin >> num;
		if(ops == '+') {
			int x = num;
			xvals.push_back(x);
		} else if(ops == '?') {
			int k = num;
			kvals.push_back(k);
		} else if(ops == '-') {
			void();
		}
		queries.emplace_back(ops, num);
	}

	sort(all(kvals)); kvals.resize(unique(all(kvals)) - kvals.begin());
	sort(all(xvals)); xvals.resize(unique(all(xvals)) - xvals.begin());

	vector<int> cnt(kvals.size());
	for(auto &[ops, num]: queries) {
		if(ops == '?') 
			cnt[kget_id(num)]++;
	}


	for(int i=0;i<kvals.size();i++) {
		intervals[i].kid = i;
	}

	for(auto &[ops, num]: queries) {
		if(ops == '?') {
			int k = num, kid = kget_id(k);
			cnt[kid]--;
			intervals[kid].update();
			cout << intervals[kid].query() * k << '\n';
			if(cnt[kid] == 0) intervals[kid].inner.clear();
		} else if(ops == '+') {
			int x = num;
			xs.insert(x);
		} else if(ops == '-') {
			int x = num, xid = xget_id(x);
			for(int kid: active[xid]) {
				intervals[kid].erase(xid);
			}
			active[xid].clear();
			xs.erase(x);
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
