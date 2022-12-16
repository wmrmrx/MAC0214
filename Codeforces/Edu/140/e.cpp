#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int int64_t
#define all(v) v.begin(), v.end()

constexpr int INF = 1e18;
constexpr size_t N = 300'000;
constexpr size_t M = 40;
constexpr size_t H = 40;

vector<int> brute(int n, const int *w, const vector<pair<int,int>>& ed) {
	vector<int> res((1<<n), INF);
	for(int msk=0;msk<(1<<n);msk++) {
		bool ok = true;
		for(const auto &[x, y]: ed) {
			if( ! ( ((1<<x)&msk) || ((1<<y)&msk) ) ) {
				ok = false;
				break;
			}
		}
		if(!ok) continue;
		int &ans = res[msk];
		ans = 0;
		for(int b=0;b<n;b++) if((1<<b)&msk) {
			ans += w[b];
		}
	}
	return res;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<int> c(n), x(m);
	for(int i=0;i<n;i++) cin >> c[i], --c[i];
	for(int i=0;i<m;i++) cin >> x[i];
	int l = m/2, r = m - l;
	vector<pair<int,int>> edl, edr, edb;
	for(int i=0;i<n;i++) {
		int a = c[i], b = c[i+1];
		if(a > b) swap(a,b);
		if(a >= l) {
			edr.emplace_back(a-l, b-l);
		} else if(b < l) {
			edl.emplace_back(a, b);
		} else {
			edb.emplace_back(a, b);
		}
	}
	sort(all(edl));
	sort(all(edr));
	sort(all(edb));
	edl.resize(unique(all(edl))-edl.begin());
	edr.resize(unique(all(edr))-edr.begin());
	edb.resize(unique(all(edb))-edb.begin());

	auto cl = brute(l, x.data(), edl);
	auto cr = brute(r, x.data()+l, edr);

	for(int i=0;i<(1<<l);i++) {
		if(c[0] < l) {
			if( ((1<<c[0])&i) == 0 ) {
				cl[i] = INF;
			}
		}
		if(c[n-1] < l) {
			if( ((1<<c[n-1])&i) == 0 ) {
				cl[i] = INF;
			}
		}
	}
	for(int i=0;i<(1<<r);i++) {
		if(c[0] >= l) {
			if( ((1<<(c[0]-l))&i) == 0 ) {
				cr[i] = INF;
			}
		}
		if(c[n-1] >= l) {
			if( ((1<<(c[n-1]-l))&i) == 0 ) {
				cr[i] = INF;
			}
		}
	}

	for(int d=0;d<r;d++) for(int msk=(1<<r)-1;msk>=0;msk--) if(((1<<d)&msk) == 0) {
		cr[msk] = min(cr[msk], cr[msk+(1<<d)]);
	}

	int ans = INF;
	for(int ma=0;ma<(1<<l);ma++) {
		if(cl[ma] > int(1e10)) continue;
		int mb = 0;
		for(const auto& [a, b]: edb) {
			if( ((1<<a)&ma) == 0 )
				mb |= (1<<(b-l));
		}
		ans = min(ans, cl[ma] + cr[mb]);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
		solve();
}
