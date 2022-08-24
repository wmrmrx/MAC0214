#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

map<string, int> cnt;

void solve() {
	int n; cin >> n;
	while(n--) {
		string s; cin >> s;
		auto it = cnt.find(s);
		if(it == cnt.end()) {
			cout << s << '\n';
			cnt[s] = 1;
		} else {
			cout << s << '(' << it->second << ')' << '\n';
			it->second++;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
