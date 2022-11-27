#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

using ld = long double;

struct point {
	int x, y;
	point(): x(), y() {}
	point(int _x, int _y): x(_x), y(_y) {}
	point operator+(point rhs) { return point(x+rhs.x, y+rhs.y); }
	point operator-(point rhs) { return point(x-rhs.x, y-rhs.y); }
	int operator^(point rhs) { return x*rhs.y - y*rhs.x; }

	using tup = tuple<int,int>;

	bool operator<(const point &rhs) const {
		return tup{x,y} < tup{rhs.x, rhs.y};
	}
};

int area2(point a,point b,point c) {
	return (b-a) ^ (c-a);
}

bool left(point a, point b, point c) {
	return area2(a,b,c);
}

map<point, int> w;

void solve() {
	int n, k; cin >> n >> k;
	vector<point> pts(n);
	for(int i=0;i<n;i++) {
		int pw;
		cin >> pts[i].x >> pw >> pts[i].y;
		if(w.find(pts[i]) == w.end()) {
			w[pts[i]] = pw;
		} else {
			w[pts[i]] = min(w[pts[i]], pw);
		}
	}
	sort(all(pts));
	vector<array<ld, 2>> dp(n);
	for(int i=0;i<n;i++) {
		auto [x2, c2] = pts[i];
		ld w2 = w[pts[i]];
		dp[i][1] = -w2;
		if(i) dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
		for(int j=0;j<i;j++) {
			auto [x1, c1] = pts[j];
			dp[i][1] = max(dp[i][1],
				dp[j][1] + ld(k) * ld(x2 - x1) / 100.0 * ld(c1 + c2) / 2.0 - w2);
		}
	}
	cout << fixed << setprecision(15);
	cout << max(dp.back()[0], dp.back()[1]) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
