#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	vector<vector<int>> vals(k);
	for(int i=0;i<n;i++) {
		vals[i%k].push_back(a[i]);
	}
	for(int i=0;i<k;i++) {
		sort(vals[i].rbegin(), vals[i].rend());
	}
	int ans = -1;
	for(int i=0;i+k-1<n;i++) {
		vector<int> cnt(k);
		for(int j=i;j<i+k;j++) {
			cnt[j%k]++;
		}
		int sum = 0;
		for(int i=0;i<k;i++) {
			sum += accumulate(vals[i].begin(), vals[i].begin()+cnt[i], 0);
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
