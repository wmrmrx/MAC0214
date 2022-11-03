#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()


void solve() {
	vector<int> cnt(26);
	string s, t, p;
	cin >> s >> t >> p;
	for(char c: p)
		cnt[c-'a']++;
	int i = 0;
	for(char c: t) {
		if(i < s.size() && s[i] == c) {
			i++;
		} else {
			if(cnt[c-'a'] == 0) {
				cout << "NO" << endl;
				return;
			}
			cnt[c-'a']--;
		}
	}
	if(i == s.size()) {
		cout << "YES" << endl;
	} else{
		cout << "NO" << endl;
	}
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
