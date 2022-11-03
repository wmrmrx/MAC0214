#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	string a, b;
	cin >> a >> b;
	int h1 = stoi(a.substr(0, 2));
	int h2 = stoi(b.substr(0, 2));
	int m1 = stoi(a.substr(3, 2));
	int m2 = stoi(b.substr(3, 2));
	int ans = 0;
	while(m1 != m2) {
		m1 += 1;
		if(m1 == 60) {
			h1 = (h1 + 1)%24;
			m1 = 0;
		}
		ans++;
	}
	while(h1 != h2) {
		h1 = (h1+1)%24;
		ans++;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
