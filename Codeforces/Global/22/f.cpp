#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr size_t MAX = 1001;

int n;
int d[MAX];

namespace dsu {
	int dad[MAX], sz[MAX], sd[MAX];

	int find(int v) {
		return dad[v] == v ? v : dad[v] = find(dad[v]);
	}

	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if(u != v) {
			if(sz[u] > sz[v]) swap(u,v);
			dad[u] = v;
			sz[v] += sz[u];
			sd[v] += sd[u];
		}
		
	}

	bool ok(int v) {
		v = find(v);
		return sd[v] * sd[v] >= sz[v];
	}	

	void init() {
		for(int i=1;i<=n;i++) {
			dad[i] = i;
			sz[i] = 1;
			sd[i] = d[i];
		}
	}
}

int query(int v) {
	cout << "? " << v << endl;
	int res; cin >> res;
	return res;
}

void answer() {
	cout << "! ";
	for(int i=1;i<=n;i++) cout << dsu::dad[i] << ' ';
	cout << endl;
}

void solve() {
	cin >> n;

	const int MN = numeric_limits<int>::min();
	auto prio = [&](int v) {
		int x = d[v];
		if(x == 1) return MN+1;
		else return -x;
	};

	set<pair<int,int>> ord; 
	for(int i=1;i<=n;i++) {
		cin >> d[i];
		ord.insert({prio(i), i});
	}

	dsu::init();

	int cnt = 0;

	vector<bool> vis(n+1);

	while(cnt < n && !ord.empty()) {
		auto [dd, v] = *ord.rbegin();
		vis[v] = 1;
		ord.erase(*ord.rbegin());
		for(int i=0;i<d[v];i++) {
			if(cnt == n) break;
			int p = query(v);
			dsu::join(v, p);
			ord.erase({prio(p), p});
			if(d[v] == 1 && !vis[p]) {
				ord.insert({MN, p});
			}
			cnt++;
		}
	}

	answer();
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
