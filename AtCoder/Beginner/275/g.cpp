#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}
//#define dbg(...) 

using ld = long double;
using tup = tuple<ld, int, int, int>;

void solve() {
	int n; cin >> n;
	ld ans = 0;
	vector<tup> l, r;
	for(int i=0;i<n;i++) {
		int a,b,c; cin >> a >> b >> c;
		ans = max(ans, ld(c) / max<ld>(a,b));
		if(a > b) {
			l.emplace_back(ld(2*c) / ld(a+b), a, b, c);
		} else if(a < b) {
			r.emplace_back(ld(2*c) / ld(a+b), a, b, c);
		}
	}

	sort(all(l));
	sort(all(r));

	if(!l.empty()) for(int j=0;j<r.size();j++) {
		auto [lx, la, lb, lc] = l.back();
		auto [rx, ra, rb, rc] = r[j];
		ld p = (ld(rb - ra) / ld(la - lb + rb - ra));
		ld q = 1-p;
		ans = max(ans, 2 * (p*lc + q*rc) / (p*(la+lb) + q*(ra+rb)) );
	}

	if(!r.empty()) for(int i=0;i<l.size();i++) {
		auto [lx, la, lb, lc] = l[i];
		auto [rx, ra, rb, rc] = r.back();
		ld p = (ld(rb - ra) / ld(la - lb + rb - ra));
		ld q = 1-p;
		ans = max(ans, 2 * (p*lc + q*rc) / (p*(la+lb) + q*(ra+rb)) );
	}

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(8);
	solve();
}
