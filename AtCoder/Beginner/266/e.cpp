#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(), v.end()

void dbg_out() {cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << h << ' '; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':'; dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	vector<double> e(n+1);
	e[1] = 3.5;
	for(int i=2;i<=n;i++) {
		for(int k=1;k<=6;k++) {
			if(k >= ceil(e[i-1])) {
				e[i] += k / 6.0;
			} else {
				e[i] += e[i-1] / 6.0;
			}
		}
	}
	cout << fixed << setprecision(10);
	cout << e[n] << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
