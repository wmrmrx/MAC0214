#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){ cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int n;
int p[101];

bool increasing(int x) {
	for(int i=x;i<n;i++) {
		if(p[i+1] < p[i]) return false;
	}
	return true;
}

void solve(int x) {
	if(increasing(x+1)) {
		pair<int,int> mx = {numeric_limits<int>::min(), 0};
		for(int i=x+1;i<=n;i++) if(p[i] < p[x]) {
			mx = max(mx, {p[i], i});
		}
		swap(p[x], p[mx.second]);
		sort(p+x+1, p+n+1);
		reverse(p+x+1, p+n+1);
		for(int i=x;i<=n;i++) cout << p[i] << ' ';
		cout << '\n';
		return;
	}

	cout << p[x] << ' ';
	solve(x+1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> p[i];
	solve(1);
}
