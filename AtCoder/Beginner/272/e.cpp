#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr size_t MAX = 200'010;
constexpr int INF = 1e18;

int n, m;
int a[MAX];

int get(int i, int j) {
	if(a[i] <= a[j]) return 0;
	return (a[i] - a[j] + j - i - 1) / (j - i);
}

void solve() {
	cin >> n >> m;
	a[0] = INF;
	for(int i=1;i<=n;i++) cin >> a[i];

	set<pair<int,int>> act;
	set<int> v;
	v.insert(0);

	for(int i=1;i<=n;i++) {
		if(a[i] >= 0) {
			v.insert(i);
		} else {
			int t = ( abs(a[i]) + i - 1 ) / i;
			act.emplace(t, i);
		}
	}

	{
		vector<int> rm_v;
		int mn = numeric_limits<int>::max();
		for(auto i: v) {
			if(a[i] >= mn) rm_v.push_back(i);
			mn = a[i];
		}
		for(auto i: rm_v)
			v.erase(i);
		rm_v.clear();
	}

	set<tuple<int,int,int>> d;
	if(!v.empty()) {
		for(auto it = v.begin(); next(it) != v.end(); it++) {
			int i = *it, j = *next(it);
			d.emplace(get(i,j), i, j);
		}
	}

	auto pop = [&](auto it) {
		if(it != v.begin()) {
			int i = *prev(it), j = *it;
			d.erase({get(i, j), i, j});
		}
		if(next(it) != v.end()) {
			int i = *it, j = *prev(it);
			d.erase({get(i, j), i, j});
		}
		if(it != v.begin() && next(it) != v.end()) {
			int i = *prev(it), j = *next(it);
			d.insert({get(i, j), i, j});
		}
		v.erase(it);
	};

	auto push = [&](int x, int t) {
		if(v.empty()) {
			v.insert(x);
			return;
		}

		{
			auto it = v.lower_bound(x);
			if(it != v.begin()) {
				int i = *prev(it);
				if(a[i] + t*i <= a[x] + t*x) return;
			}
			vector<int> rm_v;
			while(it != v.end() && (a[x] + x*t <= a[*it] + *it*t)) {
				rm_v.push_back(*it);
				it++;
			}
			for(auto i: rm_v) pop(v.find(i));
		}

		auto [it, _] = v.insert(x);
		if(it != v.begin() && next(it) != v.end()) {
			int i = *prev(it), j = *next(it);
			d.erase({get(i, j), i, j});
		}
		if(it != v.begin()) {
			int i = *prev(it), j = *it;
			d.insert({get(i, j), i, j});
		}
		if(next(it) != v.end()) {
			int i = *it, j = *prev(it);
			d.insert({get(i, j), i, j});
		}
	};

	for(int t=1;t<=m;t++) {
		while(!d.empty()) {
			auto [out, i, j] = *d.begin();
			if(out > t) break;
			pop(v.find(j));
		}
		while(!act.empty() && act.begin()->first == t) {
			push(act.begin()->second, t);
			act.erase(act.begin());
		}
		int last = *v.rbegin();
		cout << a[last] + t * last << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
