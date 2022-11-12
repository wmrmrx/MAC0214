#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) //{cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}


//	Z fexp(uint64_t e) const {
//		Z ret{1};
//		for(Z copy=*this;e>0;e/=2,copy*=copy)if(e&1)ret*=copy;
//		return ret;
//	}

int fexp(int a, int e, int m) {
	a %= m;
	int res = 1;
	for(int copy=a;e>0;e/=2,copy=(copy*copy)%m) {
		if(e&1) res = (res*copy)%m;
	}
	return res;
}

namespace nt {
	constexpr int MAX = 300'000;
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

	map<int,int> factorize(int x) {
		map<int,int> f;
		if(x < MAX) {
			while(int p = div[x]) {
				f[p]++;
				x /= p;
			}
		} else {
			for(int p: primes) {
				if(p*p > x) break;
				while(x%p == 0) {
					x /= p;
					f[p]++;
				}
			}
			if(x > 1) f[x] = 1;
		}
		return f;
	}

	int phi(int d) {
		const auto f = factorize(d);
		int res = 1;
		for(const auto [p, qtd]: f) {
			res *= (p-1);
			for(int i=0;i<qtd-1;i++) res *= p;
		}
		return res;
	}
}


void solve() {
	int a,b,d; cin >> a >> b >> d;
	if(d == 1) {
		cout << 0 << '\n';
		return;
	}

	int x = a|b;
	int p = __builtin_ctz(d);
	if(p > __builtin_ctz(x)) {
		cout << -1 << endl;
		return;
	}

	d >>= p;
	x >>= p;

	int m = (-x)%d;
	if(m < 0) m += d;

	if(d == 1) {
		cout << (a|b) << endl;
		return;
	}
	
	int inv = fexp((1<<(30-p))%d, nt::phi(d)-1, d);

	assert(((1<<(30-p))*inv)%d == 1);

	x <<= p;

	x += ( (m*inv)%d ) * (1LL<<30);

	cout << x << endl;

	assert((a|x)%d == 0);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	nt::init();
	int t; cin >> t;
	while(t--)
		solve();
}
