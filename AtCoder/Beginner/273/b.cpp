#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void round(int &x, int pot) {
	int p = 1;
	for(int i=1;i<=pot;i++) p *= 10;
	if(x%p >= p/2) {
		x -= x%p;
		x += p;
	} else {
		x -= x%p;
	}
}

void solve() {
	int x, k; cin >> x >> k;
	for(int i=1;i<=k;i++)
		round(x, i);
	cout << x << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
