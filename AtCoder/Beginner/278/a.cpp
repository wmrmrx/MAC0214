#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int &i: a) cin >> i;
	for(int i=k;i<n;i++) cout << a[i] << ' ';
	for(int i=0;i<min(n,k);i++) cout << 0 << ' ';
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
