#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

bool valid(int a, int b, int c, int d) {
	return (10*a + b < 24) && (10*c + d < 60);
}

bool confusing(int h, int m) {
	int a = h/10, b = h%10, c = m/10, d = m%10;
	return valid(a,c,b,d);
}

void solve() {
	int h, m;
	cin >> h >> m;
	while(!confusing(h,m)) {
		m = (m+1)%60;
		if(m == 0) {
			h = (h+1)%24;
		}
	}
	cout << h << ' ' << m << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
