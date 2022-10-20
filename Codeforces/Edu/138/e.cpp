#include <bits/stdc++.h>
using namespace std;

#define int long long

#define all(v) v.begin(), v.end()

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

const int INF = 1<<30;

int n, m;

vector<vector<bool>> cactus;
vector<vector<pair<int, int>>> dp;

void print() {
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cout << (cactus[i][j] ? '#' : '.');
		}
		if(i == n-1) {
			cout << endl;
		} else {
			cout << '\n';
		}
	}
}

bool can_put(int i, int j) {
	if(cactus[i][j]) return true;
	for(int k=0;k<4;k++) {
		int pi = i + dx[k], pj = j + dy[k];
		if(0 <= pi && pi < n && 0 <= pj && pj < m
				&& cactus[pi][pj]) 
			return false;
	}
	return true;
}

void solve() {
	cin >> n >> m;
	cactus.assign(n, vector<bool>(m));
	dp.assign(n, vector<pair<int,int>>(m, pair<int,int>{INF, 0}));
	for(int i=0;i<n;i++) {
		string s; cin >> s;
		for(int j=0;j<m;j++) cactus[i][j] = s[j] == '#';
	}

	for(int i=0;i<n;i++)
		if(can_put(i, 0))
			dp[i][0] = {cactus[i][0] ? 0 : 1, INF};

	for(int j=1;j<m;j++) {
		for(int i=0;i<n;i++) {
			if(!can_put(i, j)) continue;
			if(i > 0) { 
				pair<int,int> prev = dp[i-1][j-1];
				prev.first += cactus[i][j] ? 0 : 1;
				prev.second = -1;
				dp[i][j] = min(dp[i][j], prev);
			}
			if(i+1 < n) {
				pair<int,int> prev = dp[i+1][j-1];
				prev.first += cactus[i][j] ? 0 : 1;
				prev.second = 1;
				dp[i][j] = min(dp[i][j], prev);
			}
		}
	}

	pair<int,int> opt = {INF, INF};
	for(int i=0;i<n;i++) opt = min(opt, dp[i][m-1]);

//	for(int i=0;i<n;i++) {
//		for(int j=0;j<m;j++) {
//			auto &[a, b] = dp[i][j];
//			cout << '(' << a << ", " << b << ')' << ' ';
//		}
//		cout << endl;
//	}

	if(opt.first > n*m) {
		cout << "NO" << endl;
		return;
	}

	for(int i=0;i<n;i++) if(dp[i][m-1] == opt) {
		for(int j=m-1;j>=0;j--) {
			cactus[i][j] = true;
			i += dp[i][j].second;
		}
		cout << "YES" << endl;
		print();
		return;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
