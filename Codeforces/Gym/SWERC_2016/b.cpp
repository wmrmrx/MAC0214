#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(),x.end()

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

void dbg_out() {cerr<<endl;}
template <typename H, typename ...T>
void dbg_out(H h, T... t) { 
	cerr << ' ' << h; dbg_out(t...);
}
#define dbg(...) { cerr<<#__VA_ARGS__<<':'; dbg_out(__VA_ARGS__);}

struct point {
	int x, y;
	bool operator<(point other) {
		return (x * other.y < y * other.x);
	}
	bool operator==(point other) {
		return (x == other.x && y == other.y);

	}
	bool operator!=(point other) {
		return (x != other.x || y != other.y);
	}
	point(int a, int b) {
		x = a;
		y = b;
	}
};

int n, ox, oy;
vector<point> vp, vq;
const int INF = 1e9+9;
point badp = point(-1, -1);

int calc(bool wishbest) {
	int p = 0;
	int q = vq.size()-1;

	int ans = wishbest ? INF : 0;
	int tmp;

	while (p < vp.size() || q < vq.size()) {
		// dbg(p, q, vp.size(), vq.size());
		point a = p >= vp.size() ? badp : vp[p];
		point b = q >= vq.size() ? badp : vq[q];
		
		tmp = p + (vq.size()-q);
		ans = wishbest ? min(ans, tmp) : max(ans, tmp);

		// dbg(wishbest, ans, tmp, a.x, a.y, b.x, b.y);

		if (b == badp || (a != badp && a < b)) {
			// dbg("case 1");
			p++;
		}
		else if (a == badp || (b != badp && b < a)) {
			// dbg("case 2");
			q++;
		}
		else {
			// dbg("case 3");
			assert(a == badp || b == badp);
			if (wishbest) q++;
			else p++;
		}

		tmp = p + (vq.size()-q);
		ans = wishbest ? min(ans, tmp) : max(ans, tmp);
		// dbg(wishbest, ans, tmp);
	}

	if (ans >= INF) return 0;

	return ans;
} 

void solve () {
	cin >> n;
	cin >> ox >> oy;
	n--;
	
	int surebetter = 0;
	int depends = 0;

	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		x -= ox;
		y -= oy;	
		if (x > 0 && y > 0) surebetter++;
		if (x == 0 && y == 0) depends++;
		if ((x < 0 && y > 0)) vp.push_back({x, y});
		else if ((x > 0 && y < 0)) vq.push_back({x, y});
		else if (!(x==0 && y == 0) && (x==0 || y == 0)) vq.push_back({x, y});
	}


	sort(all(vp));
	sort(all(vq));

	// for (auto p : vp) dbg(p.x, p.y);
	// for (auto p : vq) dbg(p.x, p.y);

	cout << 1+calc(1)+surebetter+depends << ' ';
	cout << 1+calc(0)+surebetter << '\n';
}

signed main () {
	IOS;
	solve ();
}