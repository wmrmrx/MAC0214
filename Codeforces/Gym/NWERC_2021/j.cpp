#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() {cerr <<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){ cerr << ' ' << h; dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

bool vis[720];

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for(auto &lon: v) {
		int _lat = 0;
		cin >> _lat;
		cin >> lon;
		if(lon < 0) lon += 360;
		lon *= 2;
	}
	for(int i=0;i<n;i++) {
		int a = v[i], b = v[(i+1)%n];
		if(b < a) swap(a,b);
		int d1 = b - a, d2 = a-b+720;
		if(d1 == d2) {
			cout << "yes" << endl;
			return;
		} else if(d1 < d2) {
			for(int i=a;i<=b;i++) vis[i] = true;
		} else if(d2 < d1) {
			for(int i=0;i<=a;i++) vis[i] = true;
			for(int i=b;i<720;i++) vis[i] = true;
		}
	}
	for(int i=0;i<720;i++) {
		if(!vis[i]) {
			cout << "no ";
			double x = double(i) / 2.0;
			if (x >= 180.0) {
				x -= 360.0;
			}
			cout << fixed <<setprecision(1) << x;
			cout << endl;
			return;
		}
	}
	cout << "yes" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
