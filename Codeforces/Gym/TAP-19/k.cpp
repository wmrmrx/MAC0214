#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h,T... t) { cerr << ' ' << h; dbg_out(t...); }
//#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
#define dbg(...)

void filter(vector<array<int, 2>> &v) {
	auto cmp = [](array<int,2> &a,array<int,2> &b) {
		if(a[1] != b[1]) {
			return a[1] < b[1];
		}
		return a[0] > b[0];
	};

	sort(all(v), cmp);
	vector<array<int, 2>> res; 
	for(auto t: v) {
		while(!res.empty() && res.back()[0] >= t[0]) 
			res.pop_back();
		res.push_back(t);
	}
	v.swap(res);
}

void solve() {
	int n; cin >> n;
	vector<array<int, 2>> a, b;
	for(int i=0;i<n;i++) {
		char c; cin >> c;
		array<int, 2> t;
		cin >> t[0] >> t[1]; t[1]--;
		if(c == 'D') {
			a.push_back(t);
		} else {
			b.push_back(t);
		}
	}

	filter(a);
	filter(b);

	for(auto &[l, r]: a) { dbg("A", l, r); }
	for(auto &[l, r]: b) { dbg("B", l, r); }

	int ans = 0;

	auto routine = [&]() {

		multiset<int> mx;

		// INVARIANT: a[i] contains b[l..r]
		int l = 0, r = 0;
		for(auto &[x, y]: a) {

			while(r < b.size() && b[r][1] <= y) {
				int d = b[r][1] - b[r][0] + 1;
				mx.insert(d);
				r++;
			}

			while(l < r && b[l][0] < x) {
				int d = b[l][1] - b[l][0] + 1;
				mx.erase(mx.find(d));
				l++;
			}


			if(!mx.empty()) {
				ans = max(ans, *mx.rbegin());
				dbg(*mx.rbegin());
			}

			if(r < b.size() && x <= b[r][0] && y <= b[r][1]) {
				ans = max(ans, y - b[r][0] + 1);
				dbg(y - b[r][0] + 1);
			}
		}

	};

	routine();
	a.swap(b);
	routine();

	cout << ans << endl;

}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
