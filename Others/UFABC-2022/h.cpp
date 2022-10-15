#include <bits/stdc++.h>
using namespace std;

#define int size_t
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
//#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
#define dbg(...)

bool eq(char a, char b) {
	if(a == '?' || b == '?') return true;
	return a == b;
}

bitset<100000> lcp[3];

int solve(array<string, 3> s) {
	int ans = s[0].size() + s[1].size() + s[2].size();

	for(int i=0;i<3;i++) lcp[i].reset();

	for(int i=0;i<int(s[0].size());i++) {
		lcp[0][i] = true;
		for(int l=0;i+l<int(s[0].size()) && l < s[1].size(); l++) {
			if( ! eq(s[0][i+l], s[1][l]) ) {
				lcp[0][i] = false;
			}
		}

		lcp[1][i] = true;
		for(int l=0;i+l<int(s[0].size()) && l < s[2].size(); l++) {
			if( ! eq(s[0][i+l], s[2][l]) ) {
				lcp[1][i] = false;
			}
		}
	}

	for(int i=0;i<s[1].size();i++) {
		lcp[2][i] = true;
		for(int l=0;i+l<s[1].size() && l < s[2].size(); l++) {
			if( ! eq(s[1][i+l], s[2][l]) ) {
				lcp[2][i] = false;
			}
		}
	}



	for(int i=0;i<=s[0].size();i++) {
		if(i < s[0].size() && !lcp[0][i])
			continue;
		for(int j=i;j-i<=s[1].size() || j<=s[0].size();j++) {
			if(j < s[0].size() && !lcp[1][j])
				continue;
			if(j-i < s[1].size() && !lcp[2][j-i])
				continue;
			int x = s[0].size();
			int y = i + s[1].size();
			int z = j + s[2].size();
			int tot = max(z, max(x, y));
			ans = min(ans, tot);
		}
	}
	return ans;
}

void solve() {
	string s[3];
	for(int i=0;i<3;i++) {
		cin >> s[i];
	}
	int ans = s[0].size() + s[1].size() + s[2].size();
	array<int, 3> p{0,1,2};
	do {
		array<string, 3> v;
		for(int i=0;i<3;i++) {
			v[i] = s[p[i]];
		}
		ans = min(ans, solve(v));
	} while(next_permutation(all(p)));
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}

