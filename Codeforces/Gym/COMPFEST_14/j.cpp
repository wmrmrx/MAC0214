#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define IOS ios::sync_with_stdio(0);cin.tie(0)

using ll = long long;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ 
  cerr << ' ' << H; 
  dbg_out(T...); 
}
//#define dbg(...) { cerr<<"(" << #__VA_ARGS__<<"):" ; dbg_out(__VA_ARGS__); }
#define dbg(...)

constexpr int MAX = 100'000;
vector<array<int,3>> g[MAX];
vector<array<int, 3>> ops[MAX];

void predfs(int v, int dad = -1) {
	for(auto &[p, w, e]: g[v]) {
		if(p == dad) continue;
		predfs(p, v);
		if(ops[p].empty()) ops[v].push_back({w, w, e});
		else ops[v].push_back({ops[p][0][0] + w, w, e});
	}
	sort(ops[v].rbegin(), ops[v].rend());
}

void posdfs(int v, int dad = -1, int dadw = -1, int id = -1) {
	if(dad != -1) {
		int sz = ops[dad].size();
		int val = ops[dad][0][0];
		int cur = ops[v].empty() ? 0 : ops[v][0][0];
		if(val == cur + dadw) {
			val = sz > 1 ? ops[dad][1][0] : 0;
		}
		ops[v].push_back({val + dadw, dadw, id});
	}
	sort(ops[v].rbegin(), ops[v].rend());
	for(auto &[p, w, e]: g[v]) {
		if(p == dad) continue;
		posdfs(p, v, w, e);
	}
}

int three(int v) {
	auto& eco = ops[v];
	int sz = eco.size();
	int res = 0;
	if(sz >= 1) {
		int cur = eco[0][0] + eco[0][1];
		for(int i=1;i<min<int>(3,sz);i++) {
			cur += eco[i][0];
		}
		res = max(res, cur);
	} 
	if(sz >= 2) {
		int cur = eco[1][0] + eco[1][1] + eco[0][0];
		if(sz >= 3) cur += eco[2][0];
		res = max(res, cur);
	}
	for(int i=3;i<sz;i++) {
		int cur = eco[0][0] + eco[1][0] + eco[i][0] + eco[i][1];
		res = max(res, cur);
	}
	{
		int cur = 0;
		for(int i=0;i<min<int>(sz, 4);i++) {
			cur += eco[i][0];
		}
		res = max(cur, res);
	}
	return res;
}

int get_two(int v, int no, int cnt) {
	int res= 0 ;
	dbg(v);
	for(auto& [foo, _, bar]: ops[v]) {
		if(cnt == 0) break;
		if(bar == no) continue;
		res += foo;
		dbg(foo, _, bar)
		cnt--;
	}
	return res;
}

int lol(int u, int v, int w, int i) {
	dbg(u, v, w, i);
	int res = 2*w + get_two(u, i, 2) + get_two(v, i, 2);
	dbg(res);
	return res;
}

void solve(){
	int n; cin >> n;
	int sum = 0;

	vector<array<int,3>> edges(n-1);


	for(int i=0;i<n-1;i++) {
		auto& [u, v, w] = edges[i];
		cin >> u >> v >> w;
		u--; v--;
		sum += 2*w;
		g[u].push_back({v, w, i});
		g[v].push_back({u, w, i});
	}
	if(n <= 2) {
		cout << 0 << endl;
		return;
	}
	for(int i=0;i<n;i++) ops[i].reserve(g[i].size());
	predfs(0);
	posdfs(0);
	
	for(int i=0;i<n;i++) {
		for(auto &[x, y, z]: ops[i]) {
			dbg(i, x,y,z);
		}
	}

	int eco = 0;
	for(int i=0;i<n;i++) {
		eco = max(eco, three(i));
	}
	for(int i=0;i<n-1;i++) {
		auto [u,v,w] = edges[i];
		eco = max(eco, lol(u, v, w, i));
	}
	cout << sum - eco << endl;
}

signed main(){
    IOS;
    solve();
}
