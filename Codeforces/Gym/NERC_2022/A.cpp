#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

int a[6];

void solve() {
    for (int i = 1; i <= 5; i++)
        cin >> a[i];
    
    sort (a + 1, a + 4 + 1);
    if (a[1] == a[4]) {
        cout << "1\n";
        return;
    }
    if (a[2] == a[4] && a[1] + a[5] == a[4]) {
        cout << "1\n";
        return;
    }
    cout << "0\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
