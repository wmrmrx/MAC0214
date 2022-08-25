#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int n, m;

void brute(vector<int> &v) {
	if(v.size() == n) {
		for(int i: v) cout << i << ' ';
		cout << '\n';
	}
	int l = 0;
	if(!v.empty()) l = v.back();
	for(int i=l+1;i<=m;i++) {
		v.push_back(i);
		brute(v);
		v.pop_back();
	}
}

void solve() {
	cin >> n >> m;
	vector<int> v;
	brute(v);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
