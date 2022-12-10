#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

using pii = pair<int,int>;

pair<int,int> ini, fim;
pair<int,int> mult = {1, 1};

const int N = 100'010;

int bit[N];

int query(int id) {
	int res = 0;
	while(id > 0) {
		res = max(res, bit[id]);
		id -= id & -id;
	}
	return res;
}

void update(int id, int val) {
	while(id < N) {
		bit[id] = max(bit[id], val);
		id += id & -id;
	}
}

void solve() {
	int n; cin >> n;
	cin >> ini.first >> ini.second;
	cin >> fim.first >> fim.second;
	if(ini.first > fim.first) {
		mult.first = -1;
		ini.first = -ini.first;
		fim.first = -fim.first;
	}
	if(ini.second > fim.second) {
		mult.second = -1;
		ini.second = -ini.second;
		fim.second = -fim.second;
	}
	vector<pii> pts;
	for(int i=0;i<n;i++) {
		int x, y; cin >> x >> y;
		x *= mult.first;
		y *= mult.second;
		if(ini.first <= x && x <= fim.first &&
				ini.second <= y && y <= fim.second) {
			pts.pb({x, y});
		}
	}
	// compressao de coordenadas
	{
		map<int,int> mx, my;
		set<int> sx, sy;
		for(auto &[x, y]: pts) {
			sx.insert(x);
			sy.insert(y);
		}
		sx.insert(ini.first);
		sy.insert(ini.second);
		sx.insert(fim.first);
		sy.insert(fim.second);
		int cnt = 0;
		for(auto x: sx) {
			mx[x] = ++cnt;
		}
		cnt = 0;
		for(auto y: sy) {
			my[y] = ++cnt;
		}
		for(auto &[x, y]: pts) {
			x = mx[x];
			y = my[y];
		}
		ini.first = mx[ini.first];
		ini.second = my[ini.second];
		fim.first = mx[fim.first];
		fim.second = my[fim.second];
	}
	pts.pb(fim);
	sort(all(pts));
	int ans = 0;
	for(auto [x, y]: pts) {
		ans = query(y) + 1;
		update(y, ans);
	}
	cout << ans - 1 << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
