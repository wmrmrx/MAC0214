#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 2e5 + 10;

mt19937 rng(1230);

int n, a[N], b[N], p[N], q[N];

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[a[i]] = i;

    if (n == 1) {
        cout << "Impossible\n";
        return;
    }
    if (n == 2) {
        if (a[1] == 1) {
            cout << "Possible\n";
            cout << "2 1\n2 1\n";
        }
        else cout << "Impossible\n";
        return;
    }

    iota(q+1, q+n+1, 1);

    if(n == 3) {
	    bool ok = false;
	    do {
		ok = true;
		for(int i=n-2;i<=n;i++) {
		    if(q[i] == i || q[i] == b[i]) {
			ok = false;
			break;
		    }
		}
	    } while(not ok && next_permutation(q+n+1-3, q+n+1));
	    if(not ok) {
		    cout << "Impossible\n";
		    return;
	    }
	    for(int i=1;i<=n;i++) p[q[i]] = b[i];
	    cout << "Possible\n";
	    for(int i=1;i<=n;i++) cout << p[i] << ' ';
	    cout << '\n';
	    for(int i=1;i<=n;i++) cout << q[i] << ' ';
	    cout << '\n';
	    return;
    }

    
    for(int i=1;i<=n-4;i++) {
	    for(int j=i;j<=i+3;j++) {
		    if(q[j] != i && q[j] != b[i]) {
			    swap(q[j], q[i]);
			    break;
		    }
	    }
    }
    sort(q+n+1-4, q+n+1);
    bool ok = false;
    do {
	ok = true;
	for(int i=n-3;i<=n;i++) {
	    if(q[i] == i || q[i] == b[i]) {
		ok = false;
		break;
	    }
	}
    } while(not ok && next_permutation(q+n+1-4, q+n+1));

    for(int i=1;i<=n;i++) p[q[i]] = b[i];
    cout << "Possible\n";
    for(int i=1;i<=n;i++) cout << p[i] << ' ';
    cout << '\n';
    for(int i=1;i<=n;i++) cout << q[i] << ' ';
    cout << '\n';
    return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int t; cin >> t;
    while (t--)
	    solve();
}
