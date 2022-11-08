#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

string s[10];

void solve() {
	for(int i=0;i<10;i++) cin >> s[i];
	int a = 10, b = -1, c = 10, d = -1;
	for(int i=0;i<10;i++) for(int j=0;j<10;j++) {
		if(s[i][j] == '#') {
			a = min(i, a);
			b = max(i, b);
			c = min(j, c);
			d = max(j, d);
		}
	}
	a++; b++; c++; d++;
	cout << a << ' ' << b << '\n' << c << ' ' << d << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
