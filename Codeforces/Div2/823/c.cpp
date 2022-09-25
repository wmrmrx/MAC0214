#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

vector<int> read() {
	string s;
	cin >> s;
	vector<int> foo(s.size());
	for(int i=0;i<s.size();i++) foo[i] = s[i] - '0';
	return foo;
}

void solve() {
	vector<int> v = read();
	vector<int> ans;

	vector<int> st;
	st.push_back(v[0]);

	for(int i=1;i<v.size();i++) {
		while(!st.empty() && v[i] < st.back()) {
			ans.push_back(min<int>(9,st.back()+1));
			st.pop_back();
		}
		st.push_back(v[i]);
	}
	while(!st.empty()) {
		ans.push_back(st.back());
		st.pop_back();
	}
	sort(all(ans));
	for(auto c: ans) cout << c;
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
