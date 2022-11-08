#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

int query(int a, int b, int c, int d) {
	cout << "? " << a+1 << ' ' << b+1 << ' ' << c+1 << ' ' << d+1 << endl;
	int res; cin >> res;
	return res;
}

void answer(int x, int y) {
	cout << "! " << x+1 << ' ' << y+1 << endl;
}

void solve() {
	int n; cin >> n;
	int lo = 0, hi = n-1;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
		int num = query(lo, mid, 0, n-1);
		if(num == mid - lo + 1) {
			lo = mid+1;
		} else {
			hi = mid;
		}
	}
	int x = lo;

	lo = 0, hi = n-1;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
		int num = query(0, n-1, lo, mid);
		if(num == mid - lo + 1) {
			lo = mid+1;
		} else {
			hi = mid;
		}
	}
	int y = lo;

	answer(x, y);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
