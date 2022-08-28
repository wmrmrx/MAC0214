#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(),x.end()

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
int rita[1005], theo[1005];

void solve () {
	int d, a, b;
	cin >> d >> a >> b;
	for (int i = 4; i <= 1000; i++) rita[i] = rita[i-1] + i;
	for (int i = 3; i <= 1000; i++) theo[i] = theo[i-1] + i;
	for (int i = d; i <= 1000; i++) {
		if (rita[i] + theo[i-d] == a + b) {
			cout << a - rita[i];
			return;
		}
	}
	assert(0);
}




signed main () {
	IOS;
	solve ();
}