#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(v) v.begin(), v.end()
#define rmax(a, b) a = max(a,b)

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
// #define dbg(...)

constexpr int INF = 1e18;

void solve(vector<int> &v) {
	vector<int> a;
	for (int i = 1; i + 1 < v.size(); i++) a.push_back (v[i]);
	sort (all (a));
	int x = (a.size() + 1) / 2;
	int ans = 0;
	while (x--) {
		ans += a.back();
		a.pop_back();
	}
	cout << ans << "\n";
}

void solve() {
	vector<int> v;
	int n;
	cin >> n;
	string s; cin >> s;
	vector<int> vals(n);
	for(int &x: vals) cin >> x;
	int last = 0;
	char cur = s[0];
	for(int i=0;i<=n;i++) {
		if(i == n || cur != s[i] ) {
			int l = last, r = i;
			v.push_back(*max_element(vals.begin()+l, vals.begin()+r));
			last = i;
			if(i != n) cur = s[i];
		}
	}

	n = v.size();

	if(n <= 2) {
		cout << 0 << endl;
		return;
	}

	solve(v);
}

signed main() {
	ios::sync_with_stdio(false);  cin.tie(0);
	solve();
}
