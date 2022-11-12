#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){ cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int strip(int v) {
	while(v%2 == 0) v/=2;
	while(v%3 == 0) v/=3;
	return v;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	int val = strip(a[0]);
	for(int i=1;i<n;i++) {
		if(val != strip(a[i])) {
			cout << -1 << endl;
			return;
		}
	}
	vector<int> n2(n), n3(n);

	for(int i=0;i<n;i++) {
		while(a[i]%2 == 0) {
			a[i] /= 2;
			n2[i]++;
		}
		while(a[i]%3 == 0) {
			a[i] /= 3;
			n3[i]++;
		}
	}

	int m2 = *min_element(all(n2));
	int m3 = *min_element(all(n3));

	int ans = 0;

	for(int i=0;i<n;i++) {
		ans += n2[i] - m2;
		ans += n3[i] - m3;
	}

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
