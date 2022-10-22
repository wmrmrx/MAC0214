#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int h, w; cin >> h >> w;
	vector<int> col(w);
	for(int i=1;i<=h;i++) {
		string s; cin >> s;
		for(int j=0;j<w;j++) {
			if(s[j] == '#') col[j]++;
		}
	}
	for(int x: col) cout << x << ' ';
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
