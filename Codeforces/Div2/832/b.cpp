#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(),v.end()

void solve() {
	int n; cin >> n;
	//if(n == 1) {
	//	cout << "1\n1 2\n";
	//	return;
	//}
	//if(n == 2) {
	//	cout << "1\n1 6\n";
	//	return;
	//}

	string s = " ";
	for(int i=0;i<n;i++) s += "ban";


	vector<pair<int,int>> ans;

	int j = 3*n;

	for(int i=1;i < j;i+=3) {
		while(j > i && s[j] == 'b' || s[j] == 'n') j--;
		if(j == i) break;
		ans.emplace_back(i, j);
		swap(s[i], s[j]);
	}

	cout << ans.size() << '\n';
	for(auto [l, r]: ans) cout << l << ' ' << r << '\n';
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
