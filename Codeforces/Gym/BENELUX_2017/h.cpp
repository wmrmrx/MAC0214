#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define pb push_back

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr double EPS = 1e-15;

bool zero(double x) {
	return abs(x) <= EPS;
}

struct point {
	double x, y;
	point(): x(), y() {}
	point(double _x, double _y): x(_x), y(_y) {}

	point operator+(point rhs) { return point(x+rhs.x, y+rhs.y); }
	point operator-(point rhs) { return point(x-rhs.x, y-rhs.y); }
	double operator*(point rhs) { return x*rhs.x + y*rhs.y; }
	double operator^(point rhs) { return x*rhs.y - y*rhs.x; }

	bool operator<(const point& rhs) const {
		return x < rhs.x - EPS || (zero(x-rhs.x) && y < rhs.y - EPS);
	}
	bool operator==(const point &rhs) const {
		return zero(x-rhs.x) && zero(y-rhs.y);
	}
};

double area2(point a, point b, point c) {
	return (b-a)^(c-a);
}

bool left(point a, point b, point c) {
	return area2(a,b,c) > EPS;
}

int parallel(point a, point b) {
	if(!zero(a^b)) return 0;
	return (a.x>0) == (b.x>0) && (a.y>0) == (b.y>0) ? 1 : -1;
}

struct segment {
	point a, b;
	segment() {}
	segment(point _a, point _b): a(_a), b(_b) {}
	point v() { return b - a; }
};

bool contains(segment r, point p) {
	return r.a == p || r.b == p || parallel(r.a-p, r.b-p) == -1;
}

bool intersects(segment r, segment s) {
	if(contains(r, s.a) || contains(r, s.b) || contains(s, r.a) || contains(s, r.b)) return 1;
	return left(r.a,r.b,s.a) != left(r.a,r.b,s.b) &&
		left(s.a,s.b,r.a) != left(s.a, s.b, r.b);
}

const double PI = acos(-1);
struct circle {
	point o;
	double r;
	circle() {}
	circle(point _o, double _r): o(_o), r(_r) {}
	bool has(point p) {
		return (o - p).norm2() < r*r + EPS;
	}
	vector<point> operator/(circle c)
}

int V, A, F;
constexpr size_t MAX = 1000;
bool vis[MAX];
vector<int> g[MAX];

void dfs(int v) {
	vis[v] = 1;
	for(int p: g[v]) if(not vis[p]) {
		vis[p] = 1;
		dfs(p);
	}
}

void solve() {
	int n; cin >> n;
	vector<segment> s(n);
	for(auto &[a, b]: s) {
		int x, y, xx, yy; cin >> x >> y >> xx >> yy;
		a = point(x, y);
		b = point(xx, yy);
	}
	for(int i=0;i<n;i++) {
		int cnt = 0;
		for(int j=0;j<n;j++) if(i != j) {
			if(intersects(s[i], s[j])) {
				cnt++;
				g[i].pb(j);
				g[j].pb(i);
			}
		}
		V += cnt;
		A += max<int>(0, cnt - 1);
	}
	int comps = 0;
	for(int i=0;i<n;i++) if(not vis[i] && not g[i].empty()) {
		comps++;
	       	dfs(i);
	}
	V /= 2;
	F = 1 + comps - V + A;
	cout << F - 1 << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
