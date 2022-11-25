#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) //{ cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

int b,k;

int dist(pair<int,int> a, pair<int,int> c) {
	return abs(a.first - c.first) + abs(c.second - a.second);
}

int rdo(int x) {
	return b*(x/b);
}
int rup(int x) {
	return b*((x+b-1)/b);
}

int dq(pair<int,int> x, pair<int,int> y) {
	if(x.first%b == 0 && y.first%b == 0) {
		if(x.first == y.first) {
			return abs(x.second - y.second);
		}
		int res = abs(x.first - y.first);
		if(x.second / b == y.second / b) {
			res += k*min( 
					abs(x.second - rdo(x.second)) + abs(y.second - rdo(y.second)),
					abs(rup(x.second) - x.second) + abs(rup(y.second) - y.second)
				  );
		} else {
			res += abs(x.second - y.second);
		}
		return res;
	} else if(x.second % b == 0 && y.second % b == 0) {
		swap(x.first, x.second);
		swap(y.first, y.second);
		if(x.first == y.first) {
			return abs(x.second - y.second);
		}
		int res = abs(x.first - y.first);
		if(x.second / b == y.second / b) {
			res += k*min( 
					abs(x.second - rdo(x.second)) + abs(y.second - rdo(y.second)),
					abs(rup(x.second) - x.second) + abs(rup(y.second) - y.second)
				  );
		} else {
			res += abs(x.second - y.second);
		}
		return res;
	} else {
		return dist(x, y);
	}
}

void get_proj(pair<int,int> p, vector<pair<int,int>> &v) {
	auto [x, y] = p;

	v.emplace_back(b*(x/b), y);
	v.emplace_back(b*((x+b-1)/b), y);
	v.emplace_back(x, b*(y/b));
	v.emplace_back(x, b*((y+b-1)/b));
}

void solve() {
	pair<int,int> s, g;
	cin >> b >> k >> s.first >> s.second >> g.first >> g.second;
	vector<pair<int,int>> ps, pg;

	get_proj(s, ps);
	get_proj(g, pg);

	dbg(ps.size());
	for(auto p: ps) dbg(p.first, p.second);
	dbg(pg.size());
	for(auto p: pg) dbg(p.first, p.second);

	int ans = k * dist(s, g);

	for(auto ss: ps) for(auto gg: pg) {
		int d = k * ( dist(ss, s) + dist(gg, g) ) +
				dq(ss, gg);
		if(d < ans ){
			dbg(ss.first, ss.second);
			dbg(gg.first, gg.second);
			dbg(d);
		}
		ans = min(d, ans);
	}

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
