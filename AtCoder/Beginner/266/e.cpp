#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr int MAX = 101;

double esp[MAX];

void solve() {
	int n; cin >> n;
	esp[1] = 3.500;
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=6;j++) {
			esp[i] += max<double>(j, esp[i-1]);
		}
		esp[i] /= 6.0;
	}
	cout << fixed << setprecision(10);
	cout << esp[n] << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
