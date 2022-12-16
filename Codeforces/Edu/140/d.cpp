#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int w = 0;
	for(int i=0;i<n;i++) w += s[i] == '1';
	int l = n - w;
	//dbg((1<<w) - 1, (1<<l) - 1);
	for(int i=(1<<w)-1;i<(1<<n)-((1<<l)-1);i++) {
		cout << i +1<< ' ';
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
		solve();
}
