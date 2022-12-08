#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

vector<pair<int,int>> possible(int n, int a, int b) {
	if(a+b < n) return vector<pair<int,int>>();

	if(n == 1) {
		if(a == b) return vector<pair<int,int>>();
		else return vector<pair<int,int>>{ pair<int,int>(a, b) };
	}

	vector<pair<int,int>> res;
	for(int i=0;i<n;i++) {
		if(i == n-1) {
			if(a != b) {
				res.emplace_back(a, b);
			} else {
				res.emplace_back(a, 0);
				res[0].second += b;
			}
		} else {
			if(b > 0) {
				res.emplace_back(0, 1);
				b--;
			} else {
				res.emplace_back(1, 0);
				a--;
			}
		}
	}
	return res;
}

void solve() {
	int n, a, b; cin >> n >> a >> b;
	for(int d=0;d<n;d++) {
		bool swapped = a < b;
		auto res = possible(n-d, max(a,b), min(a,b));
		if(res.empty()) continue;
		cout << d << '\n';
		for(int i=0;i<d;i++) cout << "0:0\n";
		for(auto [x, y]: res) {
			if(swapped) {
				swap(x, y);
			}
			cout << x << ':' << y << '\n';
		}
		return;
	}
	cout << n << '\n';
	cout << a << ':' << b << '\n';
	for(int i=0;i<n-1;i++) cout << "0:0\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
