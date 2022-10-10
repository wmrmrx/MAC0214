#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
//#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}
#define dbg(...) 

template <typename T> struct RMQ {
	vector<vector<T>> dp;
	T ops(T a, T b) { return min(a,b); }
	RMQ() {}
	RMQ(vector<T> v) {
		int n = v.size();
		int log = 32-__builtin_clz(n);
		dp.assign(log, vector<T>(n));
		copy(all(v), dp[0].begin());
		for(int l=1;l<log;l++) for(int i=0;i<n;i++) {
			auto &cur = dp[l], &ant = dp[l-1];
			cur[i] = ops(ant[i], ant[min(i+(1<<(l-1)), n-1)]);
		}
	}
	T query(int a, int b)  {
		if(a == b) return dp[0][a];
		int p = 31-__builtin_clz(b-a);
		auto &cur = dp[p];
		return ops(cur[a], cur[b-(1<<p)+1]);
	}
};

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	vector<int> sz(n+1);
	vector<int> till(n+1, n);
	vector<vector<pair<int,int>>> pot(n+1);
	for(int i=0;i<n;i++) {
		cin >> a[i];
		a[i] -= (i+1);
	}
	a[n] = -1e9;
	RMQ<int> rmq(a);
	int ans = 0;
	for(int i=0;i<n;i++) {

		auto bad = [&](int val) {
			return val < -i;
		};

		int lo = i, hi = n;
		while(lo < hi) {
			int mid = (lo+hi)/2;
			if(bad(rmq.query(i,mid))) hi = mid;
			else lo = mid+1;
		}
		// first that is bad
		int f = lo;

		sz[i] += f-i;
		till[i] = f;
		ans += sz[i];

		// gets last who is good
		lo = f, hi = n;
		while(lo < hi) {
			int mid = (lo+hi+1)/2;
			if(bad(rmq.query(f+1,mid))) hi = mid-1;
			else lo = mid;
		}
		pot[f].push_back({-i, lo-f+1});
		dbg(f, -i, lo-f+1);
	}

	partial_sum(all(sz), sz.begin());

	for(auto& v: pot) { 
		reverse(all(v));
		for(int i=0;i+1<v.size();i++) {
			v[i+1].second += v[i].second;
		}
	}

	int q; cin >> q;
	while(q--) {
		int pos, x; cin >> pos >> x; pos--;
		x -= (pos+1);
		dbg(pos, x);
		if(a[pos] == x) {
			dbg("EQ");
			cout << ans << endl;
			continue;
		}

		if(a[pos] < x) {
			if(pot[pos].empty()) {
				cout << ans << endl;
				continue;
			}
			auto it = upper_bound(all(pot[pos]), pair<int,int>{x, numeric_limits<int>::max()});
			if(it == pot[pos].end()) {
				cout << ans + pot[pos].rbegin()->second << endl;
			} else {
				if(pot[pos].size() > 1) {
					cout << ans + prev(it)->second << endl;
				} else {
					cout << ans << endl;
				}
			}
			continue;
		}

		auto psum = [](int l, int r) {
			return r*(r+1)/2 - l*(l-1)/2;
		};
		auto get_sz = [&](int l, int r) {
			return sz[r] - (l?sz[l-1]:0);
		};
		// blocks from l to r
		int l = upper_bound(all(till), pos) - till.begin();
		int r = min(pos,-x-1);

		dbg(l, r, "SMALL");
		if(l > r) {
			cout << ans << endl;
		} else {
			cout << ans - get_sz(l, r) + (pos)*(r-l+1) - psum(l, r) << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
		solve();
}
