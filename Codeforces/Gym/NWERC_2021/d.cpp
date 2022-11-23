#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() {cerr <<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){ cerr << ' ' << h; dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

struct point {
	int x, y;
	point(int _x=0, int _y=0): x(_x), y(_y) {}

	point operator+(point rhs) { return point(x+rhs.x, y+rhs.y); }
	point operator-(point rhs) { return point(x-rhs.x, y-rhs.y); }
	int operator^(point rhs) { return x*rhs.y - y*rhs.x; }

	using tup = tuple<int,int>;
	bool operator<(const point& rhs) const {
		return tup{x,y} < tup{rhs.x, rhs.y};
	}
	bool operator==(const point& rhs) const {
		return tup{x,y} == tup{rhs.x, rhs.y};
	}
};

int area2(point a, point b, point c) {
	return (b-a)^(c-a);
}

bool left(point a, point b, point c) {
	return area2(a,b,c) > 0;
}

template <bool UPPER>
vector<point> hull(vector<point> v) {
	vector<point> res;
	if(UPPER) for(auto &p: v) p.x = -p.x, p.y = -p.y;
	sort(all(v));
	for(auto &p: v) {
		if(res.empty()) { res.push_back(p); continue; }
		if(res.back().x == p.x) continue;
		while(res.size() >= 2) {
			point a = res[res.size()-2], b = res.back();
			if(!left(a,b,p)) res.pop_back();
			else break;
		}
		res.push_back(p);
	}
	if(UPPER) for(auto &p: res) p.x = -p.x, p.y = -p.y;
	return res;
}

point d[4] = { point(0, 1), point(0, -1), point(1, 0), point(-1, 0) };

int dist(int k, point a, point b) {
	a = a - d[k]; b = b - d[k];
	return max<int>(abs(a.x - b.x), abs(a.y - b.y));
}

void solve() {
	int n; cin >> n;
	vector<point> v(n);
	for(auto &p: v) cin >> p.x >> p.y;
	vector<point> up = hull<true>(v), low = hull<false>(v);
	int ans = 4;
	for(int i=1;i<low.size();i++) {
		ans += dist(3, low[i-1], low[i]);
	}
	for(int i=1;i<up.size();i++) {
		ans += dist(2, up[i-1], up[i]);
	}
	ans += dist(0, up[0], low.back());
	ans += dist(1, low[0], up.back());

	vector<point> tot = up;
	tot.insert(tot.end(), all(low));
	sort(all(tot));
	tot.resize(unique(all(tot))-tot.begin());
	if(tot.size() == 2) {
		point a = tot[0], b = tot[1];
		if(abs(a.x-b.x) == abs(a.y-b.y)) {
			ans++;
		}
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}

