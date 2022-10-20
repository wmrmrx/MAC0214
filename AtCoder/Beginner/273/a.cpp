#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int n; cin >> n;
	int fat = 1;
	for(int i=2;i<=n;i++) fat*=i;
	cout << fat << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
