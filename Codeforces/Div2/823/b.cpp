#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
//#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}
#define dbg(...) 

void solve() {
	int n; cin >> n;
	vector<pair<int,int>> ord(n);
	for(int i=0;i<n;i++)
		cin >> ord[i].first;
	for(int i=0;i<n;i++)
		cin >> ord[i].second;
	sort(all(ord));

	vector<int> pre(n), pos(n);
	pre[0] = ord[0].second;
	for(int i=1;i<n;i++) {
		pre[i] = max(pre[i-1] + ord[i].first - ord[i-1].first, ord[i].second);
	}
	pos[n-1] = ord[n-1].second;
	for(int i=n-2;i>=0;i--) {
		pos[i] = max(pos[i+1] + ord[i+1].first - ord[i].first, ord[i].second);
	}

	double ans = 0;
	double val = numeric_limits<double>::max();

	for(int i=0;i<n;i++) {
		if(i != n-1) {
			double d = ord[i+1].first - ord[i].first;
			double a = pre[i], b = pos[i+1];
			double x = (b-a+d)/2;
			double cur = numeric_limits<double>::max();
			if(0 <= x && x <= d) {
				cur = a + x;
			}
			dbg(d, a, b, x);
			if(cur < val) {
				ans = x + ord[i].first;
				val = cur;
			}
		}
		double cur = max<double>(pre[i], pos[i]);
		if(cur < val) {
			ans = ord[i].first;
			val = cur;
		}
	}
	dbg(ans, val);
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << fixed << setprecision(7);

	int t; cin >> t;
	while(t--)
		solve();
}
