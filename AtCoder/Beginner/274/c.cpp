#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

void solve() {
	int n; cin >> n;

	vector<int> amoeba;
	amoeba.push_back(0);
	cout << 0 << endl;

	for(int i=0;i<n;i++) {
		int a; cin >> a;
		a--;
		amoeba.push_back(amoeba[a]+1);
		cout << amoeba.back() << '\n';
		amoeba.push_back(amoeba[a]+1);
		cout << amoeba.back() << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
