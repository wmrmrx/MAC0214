#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h,T... t) { cerr << ' ' << h; dbg_out(t...); }
//#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
#define dbg(...)

struct point {
	int x, y;
	point(int x=0, int y=0): x(x), y(y) {}

	point operator+(point rhs) { return point(x+rhs.x, y+rhs.y); }
	point operator-(point rhs) { return point(x-rhs.x, y-rhs.y); }
	int operator*(point rhs) { return x*rhs.x + y*rhs.y; };
	int operator^(point rhs) { return x*rhs.y - y*rhs.x; };

	bool operator==(const point &rhs) const {
		return x == rhs.x && y == rhs.y;
	}
};

bool ang_cmp(point a, point b) {
	auto quad = [](point p) -> bool {
		return p.y < 0 || (p.y == 0 && p.x < 0);
	};
	using tup = tuple<bool, int>;
	return tup{quad(a), 0} < tup{quad(b), a^b};
}

int area2(point a, point b, point c) {
	return (b-a)^(c-a);
}

int contains(point p, vector<point> o) {
	int N = o.size();
	for(auto &x: o) x = x - p;
	for(int i=0;i<N;i++) {
		if(o[i] == point(0, 0)) {
			swap(o[i], o.back());
			o.pop_back();
			break;
		}
	}

	sort(all(o), ang_cmp);
	int n = o.size();

	auto nxt = [&](int r) -> int {
		if(r+1 < n) return r+1;
		else return 0;
	};

	int res = 0;
	int r = 0;
	int cnt = 1;
	bool increment_r = false;
	for(int l=0;l<n;l++) {
		if(increment_r) {
			r = nxt(r);
			cnt = 0;
			increment_r = false;
		} else {
			cnt--;
		}
		while(nxt(r) != l && (o[l]^o[nxt(r)]) > 0) r = nxt(r), cnt++;
		dbg(l, r, cnt);
		if(cnt == 0) increment_r = true;
		res += cnt*(cnt-1)/2;
	}	

	dbg(p.x, p.y, cnt, res);
	for(auto lol: o) dbg(lol.x, lol.y);

	return (N-1)*(N-2)*(N-3)/6 - res;
}

void solve() {
	int n; cin >> n;
	vector<point> pts(n);
	for(auto& [x,y]: pts) cin >> x >> y;
	int ans = 0;
	//contains(pts[3], pts);
	for(auto p: pts) {int res= contains(p, pts); dbg(p.x, p.y, res); ans += res; }

	ans = n*(n-1)*(n-2)*(n-3)/24 - ans;

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
