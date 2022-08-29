#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr int MAX = 100'001, INF = 1e17;

int dp[MAX][5];

bool ok(int i) {
	return 0 <= i && i < 5;
}

void solve() {
	int n; cin >> n;
	vector<array<int, 3>> ord(n);
	for(auto &[t, x, a]: ord) cin >> t >> x >> a;
	sort(all(ord)); reverse(all(ord));
	auto cur = dp[0];
	fill_n(cur, 5, -INF);
	cur[0] = 0;
	for(int t=1;!ord.empty();t++) {
		cur = dp[t];
		auto ant = dp[t-1];
		fill_n(cur, 5, -INF);
		for(int x=0;x<5;x++) {
			for(int k=-1;k<=1;k++) if(ok(x+k)) {
				cur[x] = max(cur[x], ant[x+k]);
			}
		}
		while(!ord.empty() && ord.back()[0] == t) {
			cur[ord.back()[1]] += ord.back()[2];
			ord.pop_back();
		}
		//dbg(t, cur[0], cur[1] , cur[2], cur[3], cur[4]);
	}
	cout << *max_element(cur, cur+5) << endl;
	
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
