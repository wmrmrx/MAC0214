#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	vector<int> b(n);
	for(int i=0;i<n;i++) {
		b[i] = (i+1)*a[i];
	}
	partial_sum(all(a), a.begin());
	partial_sum(all(b), b.begin());

	auto get = [&](vector<int>& v, int l, int r) {
		return v[r] - (l ? v[l-1] : 0);
	};

	int ans = numeric_limits<int>::min();

	for(int i=0;i+m<=n;i++) {
		int s = get(b, i, i+m-1) - i*get(a, i, i+m-1);
		ans = max(s, ans);
	}

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
