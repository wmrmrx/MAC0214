#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

constexpr size_t MAX = 2000;

constexpr double INF = 1e100;

void solve() {
	int n, a; cin >> n >> a;
	vector<array<int, 3>> fish(n);
	for(auto &[w, x, v]: fish) {
		cin >> w >> x >> v;
	}
	int ans = 0;
	for(int i=0;i<n;i++)  {
		vector<tuple<double, double, int>> cur;
		auto [val, xi, vi] = fish[i];
		for(int j=0;j<n;j++) if(i != j) {
			auto& [w, xj, vj] = fish[j];
			// velocidade de j em relacao a i
			int dv = vj - vi;
			// posicao de j em relacao a i
			int dx = xj - xi;

			if(dv == 0) {
				if(0 <= dx && dx <= a)
					cur.push_back({-INF, INF, w});
				continue;
			}

			if( (dx < 0 && dv < 0) || (dx > a && dv > 0) ) {
				continue;
			}

			double beg;
			if(0 <= dx && dx <= a) {
				beg = -INF;
			} else if(dx < 0) {
				beg = double(-dx) / double(dv);
			} else if(dx >= a) {
				beg = double(dx - a) / double(-dv);
			}

			double end;
			if(dv > 0) {
				end = double(a - dx) / double(dv);
			} else {
				end = double(-dx) / double(dv);
			}

			cur.emplace_back(beg, end, w);
		}

		vector<tuple<double, bool, int>> ev;
		for(auto [beg, end, w]: cur) {
			ev.emplace_back(beg, 0, w);
			ev.emplace_back(end, 1, w);
		}
		sort(all(ev));

		ans = max(val, ans);

		for(auto &[__time, rm, w]: ev) {
			if(!rm) val += w;
			else val -= w;
			ans = max(val, ans);
		}

	}

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
