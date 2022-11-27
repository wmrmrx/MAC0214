#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr int INF = 1e9;

void solve() {
	string x;
	vector<char> ans;
	vector<vector<int>> occ(10, vector<int>());

	cin >> x;
	int k; cin >> k;
	// k: tamanho da resposta
	k = x.size() - k;
	ans.push_back(x[0]);
	occ[x[0] - '0'].push_back(0);

	for(int i=1;i<x.size();i++) {
		const int c = x[i] - '0';
		int pop = INF;
		for(int j=c+1;j<10;j++) {
			// caso conseguimos preencher
			// occ[j] >= k + i - x.size()
			auto it = lower_bound(all(occ[j]), k + i - (int) x.size());
			if(c == 0) {
				if(it == occ[j].end()) {
					continue;
				} else if(*it == 0) {
					it++;
				}
			}
			if( it != occ[j].end() ) {
				pop = min(pop, *it);
			}
		}
		if(pop != INF) {
			while(ans.size() > pop) {
				occ[ans.back() - '0'].pop_back();
				ans.pop_back();
			}
		}
		if(ans.size() < k) {
			occ[c].push_back(ans.size());
			ans.push_back(x[i]);
		}
	}

	for(char c: ans) cout << c;
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
}
