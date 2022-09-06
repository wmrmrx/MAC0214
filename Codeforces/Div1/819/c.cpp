#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr int MAX = 200'000;

void solve() {
	int n; cin >> n;
	vector<int> st; st.push_back(0);
	vector<int> env(2*n+1);
	string s; cin >> s;
	for(int i=1;i<=2*n;i++) {
		char c = s[i-1];
		if(c == '(') {
			st.push_back(i);
		} else {
			st.pop_back();
			env[st.back()]++;
		}
	}
	int ans = n;
	for(int x: env) {
		if(x) ans -= x-1;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
