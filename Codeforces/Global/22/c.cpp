#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

// if alice wins 
// neven nodd alice sum turn
bool wins[101][101][2][2];
bool vis[101][101][2][2];

bool brute(int e, int o, bool a, bool t) {
	auto &cur = wins[e][o][a][t];
	if(vis[e][o][a][t]) return cur;
	vis[e][o][a][t] = true;
	
	if(t == 0) {
		cur = false;
		if(e) {
			cur |= brute(e-1, o, a, !t);
		} 
		if(o) {
			cur |= brute(e, o-1, !a, !t);
		}
	} else {
		cur = true;
		if(e) {
			cur &= brute(e-1, o, a, !t);
		} 
		if(o) {
			cur &= brute(e, o-1, a, !t);
		}
	}
	return cur;
}

void solve() {
	int n; cin >> n;
	int c[2] = {0, 0};
	for(int i=0;i<n;i++) {
		int x; cin >> x;
		c[x&1]++;
	}

	if(wins[c[0]][c[1]][0][0]) {
		cout << "Alice";
	} else {
		cout << "Bob";
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);

	for(int a: {0,1}) for(int t: {0, 1}) {
		vis[0][0][a][t] = 1;
		wins[0][0][a][t] = (a%2 == 0);
	}

	for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) for(int a: {0,1}) for(int t: {0,1}) {
		brute(i,j,a,t);
	}

	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
