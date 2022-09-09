#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() {cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

#define YES cout<<"Yes\n"; return;

void solve() {
	int d[3]; cin >> d[0] >> d[1] >> d[2];
	int dim[2]; cin >> dim[0] >> dim[1];
	int p1[3] = {0, 1, 2};
	int p2[2] = {0, 1};
	do {
		do {
			int a = d[p1[0]], b = d[p1[1]], c = d[p1[2]];
			int w = dim[p2[0]], h = dim[p2[1]];
			if(a+2*c <= w && 2*b+2*c <= h) {
				YES
			}
			if(a+c <= w && 2*b+c+a+b <= h) {
				YES
			}
			if(a+2*c <= w&& a+2*b+c <= h) {
				YES
			}
		} while(next_permutation(p2, p2+2));
	} while(next_permutation(p1, p1+3));
	cout << "No\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
