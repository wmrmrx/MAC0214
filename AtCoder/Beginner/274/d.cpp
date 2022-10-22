#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()


bool can(vector<int> &x, int s) {
	bitset<60'000> marc;
	marc.reset();

	vector<int> reach;

	int origin = 30'000;
	marc[origin] = 1;

	for(int val: x) {
		reach.clear();
		for(int k=0;k+val<marc.size();k++) if(marc[k+val]) {
			reach.push_back(k);
		}
		for(int k=val;k<marc.size();k++) if(marc[k-val]) {
			reach.push_back(k);
		}
		marc.reset();
		for(auto pos: reach) marc[pos] = 1;
	}
	return marc[origin+s];
}

void solve() {
	int n,x,y; cin >> n >> x >> y;
	vector<int> a(n);
	for(int &i: a) cin >> i;

	vector<int> xs, ys;

	x -= a[0];

	for(int i=1;i<n;i++) {
		if(i%2 == 0) xs.push_back(a[i]);
		else ys.push_back(a[i]);
	}

	if(can(xs, x)  && can(ys, y)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
