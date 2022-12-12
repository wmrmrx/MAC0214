#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

namespace nt {
	constexpr int MAX = 100'000;
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

	bool factorize(int x, set<int> &used) {
		if(x < MAX) {
			while(int p = div[x]) {
				auto [_, b] = used.insert(p);
				if(!b) return true;
				while(x%p == 0) x /= p;
			}
		} else {
			for(int p: primes) {
				if(p*p > x) break;
				if(x%p == 0) {
					auto [_, b] = used.insert(p);
					if(!b) return true;
					while(x%p == 0) x /= p;
				}
			}
			if(x > 1) {
				auto [_, b] = used.insert(x);
				if(!b) return true;
			}
		}
		return false;
	}
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	set<int> s;
	for(int x: a) {
		if(nt::factorize(x, s)) {
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	nt::init();
	int t; cin >> t;
	while(t--)
		solve();
}
