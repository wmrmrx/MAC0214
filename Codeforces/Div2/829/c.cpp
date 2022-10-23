#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &i: a) cin >> i;

	int tot = accumulate(all(a), 0);
	if(tot%2) {
		cout << -1 << endl;
		return;
	}
	int sig = 1;
	if(tot < 0) tot = - tot, sig = -sig;

	vector<bool> ans(n, false);

	for(int i=1;i<n && tot;i++) {
		if(a[i] == sig && ans[i-1] == false) {
			ans[i] = 1;
			tot -= 2;
		}
	}

	if(tot) {
		cout << - 1 << endl;
		return;
	} else {
		vector<pair<int,int>> tv;
		int l = 0;
		while(l < n) {
			if(l == n-1) {
				tv.emplace_back(l+1, l+1);
				break;
			}
			if(ans[l+1]) {
				tv.emplace_back(l+1, l+2);
				l+=2;
			}
			else {
				tv.emplace_back(l+1, l+1);
				l++;
			}
		}
		cout << tv.size() << '\n';
		for(auto [x, y]: tv) 
			cout << x << ' ' << y << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
