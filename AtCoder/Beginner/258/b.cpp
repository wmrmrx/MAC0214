#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {-1, 0, 1, 0, -1, 1, -1, 1};

void solve() {
	int n; cin >> n;
	vector<string> a(n);
	vector<string> ans;
	for(string &s: a) cin >> s;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		for(int k=0;k<8;k++) {
			int x = i, y = j;
			string s;
			for(int l=0;l<n;l++) {
				s += a[x][y];
				x = (x+dx[k])%n;
				y = (y+dy[k])%n;
				if(x < 0) x += n;
				if(y < 0) y += n;
			}
			ans.push_back(s);
		}
	}
	sort(all(ans));
	cout << ans.back() << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
