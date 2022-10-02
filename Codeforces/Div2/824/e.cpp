#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

bool solve(const array<vector<int>, 2> d, vector<int>& ans, int &p) {
	int n = ans.size();
	ans.back() = d[0].back();

	for(auto diff: d[1]) {
		array<multiset<int>, 2> rem;
		for(int b: {0, 1}) rem[b] = multiset<int>(all(d[b]));
		rem[0].erase(rem[0].find(*rem[0].rbegin()));

		p = ans.back() - diff;
		rem[1].erase(rem[1].find(diff));

		bool ok = true;

		for(int i=n-2;i>=0;i--) {
			int a = *rem[0].rbegin(), b = *rem[1].rbegin();
			if(a >= b) {
				ans[i] = a;
				auto it = rem[1].find(abs(ans[i] - p));
				if(it == rem[1].end()) {
					ok = false;
					break;
				} else {
					rem[1].erase(it);
					rem[0].erase(rem[0].find(a));
				}
			} else {
				ans[i] = p - b;
				auto it = rem[0].find(abs(ans[i]));
				if(it == rem[0].end()) {
					ok = false;
					break;
				} else {
					rem[0].erase(it);
					rem[1].erase(rem[1].find(b));
				}
			}
		}

		if(ok) return true;
	}

	for(auto diff: d[1]) {
		array<multiset<int>, 2> rem;
		for(int b: {0, 1}) rem[b] = multiset<int>(all(d[b]));
		rem[0].erase(rem[0].find(*rem[0].rbegin()));

		p = ans.back() + diff;
		rem[1].erase(rem[1].find(diff));

		bool ok = true;

		for(int i=n-2;i>=0;i--) {
			int a = *rem[0].rbegin(), b = *rem[1].rbegin();
			if(a >= b) {
				ans[i] = a;
				auto it = rem[1].find(abs(ans[i] - p));
				if(it == rem[1].end()) {
					ok = false;
					break;
				} else {
					rem[1].erase(it);
					rem[0].erase(rem[0].find(a));
				}
			} else {
				ans[i] = p - b;
				auto it = rem[0].find(abs(ans[i]));
				if(it == rem[0].end()) {
					ok = false;
					break;
				} else {
					rem[0].erase(it);
					rem[1].erase(rem[1].find(b));
				}
			}
		}

		if(ok) return true;
	}
	return false;
}

void solve() {
	int n; cin >> n;
	array<vector<int>, 2> d;
	d[0].resize(n); d[1].resize(n);
	for(int i: {0, 1}) for(auto& x: d[i]) cin >> x;
	for(int i: {0, 1}) sort(all(d[i]));

	int p = 0;
	vector<int> ans(n);

	bool swapped = false;
	if(d[0].back() < d[1].back()) d[0].swap(d[1]), swapped = true;

	if(solve(d, ans, p)) {
		cout << "YES" << '\n';
		int mn = min(*min_element(all(ans)), p);
		if(mn >= 0) mn = 0;
		else mn = -mn;
		for(int x: ans) cout << x + mn << ' ';
		cout << '\n';
		pair<int,int> foo{mn, p+mn};
		if(swapped) swap(foo.first, foo.second);
		cout << foo.first << ' ' << foo.second << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
