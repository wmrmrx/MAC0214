#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

bool zero(int x){ return x == 0; }

struct point {
	int x, y;
	
	point(int x=0, int y=0): x(x), y(y) {}

	point operator+(point rhs){ return point(x+rhs.x, y+rhs.y); }
	point operator-(point rhs){ return point(x-rhs.x, y-rhs.y); }
	int operator*(point rhs) { return x* rhs.x + y*rhs.y; }
	int operator^(point rhs) { return x*rhs.y - y*rhs.x; }

	using tup = tuple<int,int>;

	bool operator<(const point& rhs) const {
		return tup{x,y} < tup{rhs.x, rhs.y};
	}
	
	bool operator==(const point& rhs) const {
		return tup{x, y} == tup{rhs.x, rhs.y};
	}
	bool operator!=(const point& rhs) const {
		return tup{x, y} != tup{rhs.x, rhs.y};
	}
};

int dist2(point a, point b) {
	return (a-b)*(a-b);
}

int area2(point a, point b, point c) {
	return (b-a) ^ (c-a);
}
bool left(point a, point b, point c) {
	return	area2(a,b,c) > 0;
}
bool right(point a, point b, point c) {
	return	area2(a,b,c) < 0;
}

template<bool UPPER>
vector<point> hull(vector<point> v) {
	vector<point> res;
	if(UPPER) for(auto& p: v) p = point(0,0) - p;
	sort(all(v));
	for(auto &p: v) {
		if(res.empty()) {res.push_back(p); continue; }
		if(res.back().x == p.x) continue;
		while(res.size() >= 2) {
			point a = res[res.size()-2], b = res.back();
			if(!left(a,b,p)) res.pop_back();
			else break;
		}
		res.push_back(p);
	}
	if(UPPER) for(auto& p: res) p = point(0,0) - p;
	return res;
}

struct polygon {
	vector<point> p;
	int n;
	polygon(vector<point> _p) {
		p = hull<false>(_p); 
		for(point pt: hull<true>(_p)) {
			if(pt != p.back() && pt != p[0]) {
				p.push_back(pt);
			}
		}
//		dbg("LOWER");
//		for(auto &pt: p) {
//			cout << pt.x << ' ' << pt.y << '|';
//		} cout << endl;
		n = p.size();
	}

	bool has(point q) {
		if(right(p[0], p[1], q) || left(p[0], p[n-1], q)) return 0;
		int lo = 1, hi = n;
		while(lo + 1 < hi) {
			int mid = (lo + hi)/2;
			if(!right(p[0], p[mid], q)) lo = mid;
			else hi = mid;
		}
		return hi != n ? !right(p[lo],p[hi], q) : dist2(p[0], q) <= dist2(p[0], p[n-1]);
	}
};

void solve() {
	int l; cin >> l;
	vector<point> large(l);
	for(auto& p: large) {
		cin >> p.x >> p.y;
	}
	polygon poly(large);

	int ans = 0;
	int s; cin >> s;
	for(int i=0;i<s;i++) {
		int x, y; cin >> x >> y;
		if(poly.has(point(x,y))) ans++;
	}
	cout << ans << '\n';

}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
