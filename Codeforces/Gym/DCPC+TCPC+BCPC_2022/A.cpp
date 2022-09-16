#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<":";dbg_out(__VA_ARGS__);}

void compress(vector<int> &v) {
	set<int> s;
	map<int,int> mp;
	for(int x: v) s.insert(x);
	int cnt = 0;
	for(auto x: s) {
		mp[x] = cnt++;
	}
	for(int &x: v) {
		x = mp[x];
	}
}

constexpr int MAX = 100'000;
void solve() {
	int n; cin >> n;
	vector<int> a(n), g(n), p(n), ant(n), prox(n);
	for(int &x: a) cin >> x;
	for(int &x: g) cin >> x;


	compress(g);
	int mx = *max_element(all(g));

	vector<vector<int>> comp(mx+1, vector<int>());
	vector<int> mn(comp.size(), numeric_limits<int>::max());
	for(int i=0;i<g.size();i++) {
		comp[g[i]].push_back(i);
	}

	
	for(int i=0;i<comp.size();i++) {
		auto &id = comp[i];
		vector<pair<int,int>> occ;
		for(int i: id)
			occ.push_back({a[i], i});
		sort(all(occ));
		for(int i=0;i<occ.size()-1;i++) {
			if(occ[i].first == occ[i+1].first) {
				cout << -1 << endl;
				return;
			}
		}
		ant[occ[0].second] = -1;
		for(int i=0;i<occ.size()-1;i++) {
			int a = occ[i].second, b = occ[i+1].second;
			prox[a] = b;
			ant[b] = a;
		}
		prox[occ.back().second] = -1;
	}

	int cnt = 0;
	vector<bool> ok(n, false);
	for(int i=0;i<n;i++) if(!ok[i]) {
		int cur = i;
		vector<int> nxt;
		while(ant[cur] != -1 && !ok[ant[cur]]) {
			nxt.push_back(cur);
			cur = ant[cur];
		}
		//dbg(i);
		nxt.push_back(cur);
		reverse(all(nxt));
		for(int x: nxt) {
			ok[x] = 1;
			p[x] = ++cnt;
		}
	}

	for(int x: p) cout <<  x << ' '; cout << '\n';

}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) 
		solve();
}

