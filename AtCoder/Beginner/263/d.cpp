#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
//#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
#define dbg(...)

int n, l, r; 

void solve() {
	cin >> n >> l >> r;
	vector<int> a(n), b;
	for(int &x: a) cin >> x;
	b = a; reverse(all(b));
	
	int tot = accumulate(all(a), 0LL);

	partial_sum(all(a), a.begin());
	partial_sum(all(b), b.begin());

	for(int i=0;i<n;i++) {
		a[i] = max(0LL, a[i] - l*(i+1));
		b[i] = max(0LL, b[i] - r*(i+1));
		if(i) {
			a[i] = max(a[i], a[i-1]);
			b[i] = max(b[i], b[i-1]);
		}
	}

//	for(int i=0;i<n;i++) cout << a[i] << " \n"[i==n-1];
//	for(int i=0;i<n;i++) cout << b[i] << " \n"[i==n-1];

	int ans = max(b[n-1], a[n-1]);
	for(int i=0;i<=n-2;i++) {
		ans = max(ans, a[i] + b[n-2-i]);
	}

	dbg(tot, ans);
	cout << tot-ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
