#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int a[1000][1000];

void solve() {
	int n; cin >> n;
	for(int i=0;i<n;i++) {
		string s; cin >> s;
		for(int j=0;j<n;j++) {
			char c = s[j];
			if(c == 'W') {
				a[i][j] = 2;
			} else if(c == 'L') {
				a[i][j] = 0;
			} else {
				a[i][j] = 1;
			}
		}
	}

	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
		if(a[i][j] + a[j][i] != 2) {
			cout << "incorrect" << endl;
			return;
		}
	}
	cout << "correct" << endl;

}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
