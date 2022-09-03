#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr double EPS = 1e-6;
constexpr double INF = 1e100;

bool zero( double x ) {
	return abs(x) < EPS;
}

struct point {
	double x, y;
	point(double x=0, double y=0): x(x), y(y) {}
	point operator+(const point& rhs) const {
		return point(x+rhs.x, y+rhs.y);
	}
	point operator-(const point& rhs) const {
		return point(x-rhs.x, y-rhs.y);
	}
	double operator*(const point& rhs) const {
		return x*rhs.x + y*rhs.y;
	}
	point operator*(const double& f) {
		return point(x*f, y*f);
	}
	double abs() const {
		return sqrt(x*x + y*y);
	}
};

struct line {
	double m, l;
	line(double m, double l): m(m), l(l) {}
	line(point a, point b) {
		m = (a.y-b.y) / (a.x-b.x);
		l = a.y - m*a.x;
	}
	point inter(const line& rhs) const {
		double x = (l-rhs.l)/(rhs.m-m);
		double y = m*x + l;
		return point(x, y);
	}
	point proj(point p) {
		double mm = -1/m;
		line pl(mm, p.y-mm*p.x);
		return this->inter(pl);
	}
};

void solve() {
	int n; cin >> n;
	vector<point> poly; poly.reserve(n);
	for(int i=0;i<n;i++) {
		double a, b; cin >> a >> b;
		poly.push_back(point(a,b));
	}
	int q; cin >> q;
	point opt;
	while(q--) {
		double ans = numeric_limits<double>::max();
		point a, b;
		cin >> a.x >> a.y >> b.x >> b.y;
		for(int i=0;i<n;i++) {
			point l = poly[i], r = poly[(i+1)%n];
			double hl, hr, k;
			point des;
			if(!zero(l.x - r.x)) {
				line lin(l, r);
				hl = (l-lin.proj(l)).abs(), hr = (r-lin.proj(r)).abs();
				if(zero(hl+hr)) {
					des = a;
				} else {
					k = hl/(hl+hr);
					des = l + (r-l)*k;
				}
			} else {
				double x = l.x;
				hl = abs(x - a.x), hr = abs(x - b.x);
				l.y = a.y; r.y = b.y;
				if(zero(hl+hr)) {
					des = a;
				}
				k = hl/(hl+hr);
				des = l + (r-l)*k;
			}
			if(zero((l-des).abs() + (des-r).abs() - (r-l).abs())) {
				double val = (a-des).abs() + (b-des).abs();
				if(val < ans) {
					opt = des;
					ans = val;
				}
			} else {
				for(point des: {l, r}) {
					double val = (a-des).abs() + (b-des).abs();
					if(val < ans) {
						opt = des;
						ans = val;
					}
				}
			}
		}
		cout << ans << ' ' << opt.x << ' ' << opt.y << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("flags.in", "r", stdin);
	cout << fixed << setprecision(10);
	int t; cin >> t;
	for(int i=1;i<=t;i++) {
		cout << "Case " << i << ":";
		cout << '\n';
		solve();
	}
}
