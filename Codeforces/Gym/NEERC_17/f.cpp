#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() {cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

// returns rot, shapes
vector<pair<int,vector<array<int,4>>> solve() {
	int a,b,n; cin >> a >> b >> b;
	n--;

	int rot = 0;
	while(a < 0 || b < 0) {
		int x = -b, y = a;
		a = x; b = y;
		rot++;
	}

	vector<pair<pair<int,int>, pair<int,int>>> res;

	if(a <= n && b <= n) {
		res.emplace_back({n, b},{0, b-n});
		return {res, rot};
	}

	int bonus = -1;
	while(a >= n && b >= n) {
		a -= n;
		b -= n;
		bonus++;
	}


}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m; cin >> m;
	while(m--) 
		solve();
}
