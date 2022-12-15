#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

namespace nt {
	constexpr int MAX = 10'000'001;
	// div[i]: smallest prime that divides i
	int div[MAX];

	// primes: list of primes between 2 and MAX
	vector<int> primes;

	void init() {
		for(int i=2;i<MAX;i++) if(!div[i]) {
			div[i] = i;
			primes.push_back(i);
			for(int j=i*i;j<MAX;j+=i) if(!div[j])
				div[j] = i;
		}
	}

	bool is_prime(int x) {
		if(x < MAX) return div[x] == x;
		for(int p: primes) {
			if(p*p > x) break;
			if(x%p == 0) return false;
		}
		return true;
	}
}

void solve() {
	int x, y; cin >> x >> y;
	if(x > y) {
		swap(x, y);
	}
	if(x == 1 && y == 1) {
		cout << 1 << '\n';
		return;
	}
	if(__gcd(x, y) > 1) {
		cout << 0 << '\n';
		return;
	}
	if(x+1 == y) {
		cout << -1 << '\n';
		return;
	}
	int d = y - x;
	int ans = numeric_limits<int>::max();
	while(int p = nt::div[d]) {
		d /= p;
		ans = min(ans, p - x%p);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	nt::init();
	int t; cin >> t;
	while(t--)
		solve();
}
