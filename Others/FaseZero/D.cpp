#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<":";dbg_out(__VA_ARGS__);}

void print(int x) {
	printf("-C");
	printf("%04lld", x);
}

void solve() {
	string s; cin >> s;
	int n, k; cin >> n >> k; k--;
	vector<int> cur;
	pair<int,int> st{0, n};
	while(st.first < k) {
		int gen = (1LL)<<(min(60LL, st.second));
		if(st.first + gen <= k) {
			st = {st.first + gen, st.second-1};
		cur.back() += 1;
		} else {
			st = {st.first + 1, st.second-1};
			cur.push_back(0);
		}
	}
	cout << s;
	for(int x: cur) print(x);
	cout << '\n';
}

signed main() {
	int t;
	cin >> t;
	while(t--)
		solve();
}
