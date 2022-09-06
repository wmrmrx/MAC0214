#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;
	vector<int> des(n);
	for(int i=0;i<n;i++) {
		if(a[i] > b[i]) {
			cout << "No\n"; 
			return;
		}
		if(des[i] > b[i]) {
			cout << "No\n"; 
			return;
		}
		if(a[i] > b[i]) {
			cout << "No\n"; 
			return;
		}
		if(a[i] < b[i]) {
			des[(i+1)%n] = b[i]-1;
		}
	}
	if(des[0] > b[0]) {
		cout << "No\n"; 
		return;
	}
	cout << "Yes\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
