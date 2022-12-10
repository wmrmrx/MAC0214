#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define double long double
const int N = 1e5+10;

int cnt;
double val[N];
map<string, int> mp;

void solve() {
	int n; cin >> n;
	auto get = [&](string s) {
		if(mp.find(s) == mp.end()) {
			mp[s] = cnt++;
		}
		return mp[s];
	};
	for(int i=0;i<n;i++) {
		string o, w; cin >> o >> w;
		double r; cin >> r;
		int u = get(w), v = get(o);
		val[v] = max(val[v], val[u] + log(r));
	}
	cout << fixed << setprecision(10);
	cout << min<double>(10.0, exp(min<double>(3.0, val[get("blue")]))) << endl;;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	for(int i=0;i<N;i++) val[i] = -1e18;
	mp["pink"] = 0;
	mp["blue"] = 1;
	cnt = 2;
	val[mp["pink"]] = 0;
	solve();
}
