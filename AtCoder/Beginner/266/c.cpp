#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(), v.end()

void dbg_out() {cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << h << ' '; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':'; dbg_out(__VA_ARGS__);}

using pii = pair<int,int>;

pii operator-(pii a, pii b) {
	return pii(a.first-b.first, a.second-b.second);
}

int operator^(pii a, pii b) {
	return a.first*b.second - a.second*b.first;
}

bool left(pii a, pii b, pii c) {
	return ((b-a)^(c-a)) > 0;
}

void solve() {
	array<pair<int,int>, 4> pt;
	for(auto &[x,y]: pt) cin >> x >> y;
	for(int i=0;i<4;i++) {
		int j = (i+1)%4;
		int k = (i+2)%4;
		if(!left(pt[i], pt[j], pt[k])) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
