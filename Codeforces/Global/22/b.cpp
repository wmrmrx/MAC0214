#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

bool inc(vector<int> &a) {
	for(int i=1;i<a.size();i++) {
		if(a[i-1] > a[i]) return false;
	}
	return true;
}

void solve() {
	int n, k; cin >> n >> k;


	vector<int> s(k);
	for(int &x: s) cin >> x;

	if(k == 1) {
		if(n == 1) {
			cout << "YES" << endl;
			return;
		}

		int val = s[0];
		int mxsum = val*n;

		if(mxsum < s[0]) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
		return;
	}

	int mnval = s[1] - s[0];
	int mxsum = (n-k+1)*mnval;
	vector<int> a;
	for(int i=1;i<s.size();i++) {
		a.push_back(s[i]-s[i-1]);
	}

	if(inc(a) && mxsum >= s[0]) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
