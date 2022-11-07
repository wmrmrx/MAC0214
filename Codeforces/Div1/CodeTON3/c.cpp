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
	string a; cin >> a;
	string b; cin >> b;
	vector<int> va(n), vb(n);
	for(int i=0;i<n;i++) {
		va[i] = a[i] == '1';
		vb[i] = b[i] == '1';
	}

	vector<pair<int,int>> ans;

	for(int i=0;i<n;i++) {
		if(va[i] == 1) {
			ans.emplace_back(i, i);
			va[i] = !va[i];
			vb[i] = !vb[i];
		}
	}

	if(ans.size()%2 == 1) {
		for(int i=0;i<n;i++) vb[i] = !vb[i];
	}
	
	auto ok = [&]() -> bool {
		int sb = accumulate(all(vb), 0);
		if(sb == 0) return true;
		if(sb == n) {
			ans.emplace_back(0, n-1);
			ans.emplace_back(0, 0);
			ans.emplace_back(1, n-1);
			return true;
		}
		return false;
	};

	if(ok()) {
		cout << "YES" << '\n';
		cout << ans.size() << '\n';
		for(auto &[l, r]: ans) cout << l+1 << ' ' << r+1 << '\n';
		return;
	}

	cout << "NO" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}

