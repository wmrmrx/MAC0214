#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int int64_t
#define all(v) v.begin(), v.end()
#define rmin(a,b) a = min(a,b);

constexpr size_t MAX = 3002;
constexpr int INF  = 1e17;

int x;
int origin;
int dp[MAX][MAX][2];
int need[MAX];

vector<array<int, 3>> v;


int solve(int a, int b, int c) {
	auto &cur = dp[a][b][c];

	int pos = c == 0 ? v[a][0] : v[b][0];

	if(cur != INF) return cur;

	if(a <= x && x <= b) {
		return cur = 0;
	}

	if(b+1 < v.size()) {
		auto &[p, t, wall] = v[b+1];
		if(wall) {
			int n = need[t];
			if(a <= n && n <= b) {
				cur = min(cur, solve(a,b+1,1) + abs(p-pos));
			}
		} else {
			cur = min(cur, solve(a,b+1,1) + abs(p-pos));
		}
	}
	if(a > 0) {
		auto &[p, t, wall] = v[a-1];
		if(wall) {
			int n = need[t];
			if(a <= n && n <= b) {
				cur = min(cur, solve(a-1,b,0) + abs(p-pos));
			}
		} else {
			cur = min(cur, solve(a-1,b,0) + abs(p-pos));
		}
	}

	return cur;
}

void solve() {
	int n; cin >> n >> x;

	vector<int> y(n), z(n);
	for(int &i: y) cin >> i;
	for(int &i: z) cin >> i;

	// need[type] == hammer position

	// pos, type, 1 if wall
	for(int i=0;i<n;i++) {
		v.push_back({y[i], i, int(1)});
	}

	for(int i=0;i<n;i++) {
		v.push_back({z[i], i, int(0)});
	}

	v.push_back({0, 0, 0});
	v.push_back({x, 0, 0});
	sort(all(v));

	auto get = [&](int coord) {
		return lower_bound(all(v), array<int,3>{coord, -1, -1}) - v.begin();
	};

	for(auto &[_p, t, wall]: v) if(wall) {
		need[t] = get(z[t]);
	}

	origin = get(0);
	x = get(x);

	int ans = solve(origin, origin, 0);

	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) for(int k=0;k<2;k++) {
		dp[i][j][k] = INF;
	}
	solve();
}
