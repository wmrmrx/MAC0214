#pragma GCC target("sse2")
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define all(v) v.begin(), v.end()

constexpr size_t MAX = 2'000'000;
vector<int> g[MAX];

void solve() {
	int h, w; cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));

	for(auto &v: a) for(auto &x: v) cin >> x;

	vector<pair<int,int>> row(h);

	for(int i=0;i<h;i++) {
		auto &v = a[i];
		int mx = *max_element(all(v));
		int mn = numeric_limits<int>::max();
		for(int x: v) if(x != 0) {
			mn = min(x, mn);
		}
		if(mx == 0) {
			row.emplace_back(0, 0);
		} else {
			row.emplace_back(mn, mx);
		}
	}

	sort(all(row));
	int mx = 0;
	for(auto &[l, r]: row) {
		if( !(mx <= l) ) {
			cout << "No" << endl;
			return;
		} 
		mx = r;
	}

	if(h == 1) {
		cout << "Yes" << endl;
		return;
	}
	

	int n = w;
	int ext = 0;
	{
		vector<pair<int,int>> p(n);
		for(int i=0;i<h;i++) {
			for(int j=0;j<n;j++) 
				p[j] = {a[i][j], j};
			sort(all(p));
			for(int j=0;j<n;j++) if(p[j].first != 0) {
				int k = j;
				while(k < n && p[k].first == p[j].first) k++;
				if(k == n) break;
				int m = k;
				while(k < n && p[k].first == p[m].first) k++;
				for(int x=j;x<m;x++) {
					g[p[x].second].push_back(n+ext);
				}
				for(int x=m;x<k;x++) {
					g[n+ext].push_back(p[x].second);
				}
				j = m-1;
				ext++;
			}
		}
	}

	n += ext;
	vector<int> in(n);
	set<pair<int,int>> s;

	for(int i=0;i<n;i++) for(int p: g[i]) {
		in[p]++;
	}
	for(int i=0;i<n;i++) {
		s.emplace(in[i], i);
	}
	while(!s.empty()) {
		auto [d, v] = *s.begin();
		s.erase(s.begin());
		if(d > 0) {
			cout << "No" << endl;
			return;
		}
		for(int p: g[v]) {
			s.erase({in[p], p});
			in[p]--;
			s.emplace(in[p], p);
		}
	}
	cout << "Yes" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
