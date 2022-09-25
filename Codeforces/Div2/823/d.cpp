#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

int cnt[26][26];

void solve() {
	memset(cnt, 0, sizeof(cnt));
	int n; cin >> n;
	string a, b;
	cin >> a >> b;
	for(int i=0;i<n;i++) {
		int x = a[i] - 'a';
		int y = b[n-1-i] - 'a';
		if(x > y) swap(x,y);
		cnt[x][y]++;
	}

	bool ok = false;

	int unp = 0;
	int unpeq = 0;

	for(int x=0;x<26;x++) for(int y=x;y<26;y++) {
		if(cnt[x][y]%2) {
			if(x == y) unpeq++;
			else unp++;
		}
	}

	if(n%2 == 0 && unp == 0 && unpeq == 0) {
		ok = true;
	}
	if(n%2 == 1 && unp == 0 && unpeq == 1) {
		ok = true;
	}

	cout << (ok ? "YES" : "NO") << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
