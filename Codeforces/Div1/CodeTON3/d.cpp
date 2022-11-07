#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr int MOD = 998244353;

struct Z {
	int64_t x;
	Z(const int64_t _x=0): x(_x%MOD<0?_x%MOD+MOD:_x%MOD) {}
	Z fexp(uint64_t e) const {
		Z ret{1};
		for(Z copy=*this;e>0;e/=2,copy*=copy)if(e&1)ret*=copy;
		return ret;
	}
	Z inv()const{return this->fexp(MOD-2);}
	void operator+=(const Z rhs){x+=rhs.x;if(x>=MOD)x-=MOD;}
	void operator-=(const Z rhs){x-=rhs.x;if(x<0)x+=MOD;}
	void operator*=(const Z rhs){x*=rhs.x;x%=MOD;}
	void operator/=(const Z rhs){x*=rhs.inv().x;x%=MOD;}
	bool operator==(const Z rhs)const{return x==rhs.x;}
	Z operator+(const Z rhs)const{Z ret=*this;ret+=rhs;return ret;}
	Z operator-(const Z rhs)const{Z ret=*this;ret-=rhs;return ret;}
	Z operator*(const Z rhs)const{Z ret=*this;ret*=rhs;return ret;}
	Z operator/(const Z rhs)const{Z ret=*this;ret/=rhs;return ret;}
};

// functions assume that x < MAX*MAX
namespace ntt {
	constexpr int MAX = 300'000;
	// div[i]: prime that divides i
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
			if(x%p == 0) {
				return false;
			}
		}
		return true;
	}

	map<int,int> factorize(int n) {
		map<int,int> f;
		if(n >= MAX) {
			for(int p: primes) {
				if(p*p > n) break;
				while(n%p == 0) {
					n /= p;
					f[p]++;
				}
			}
			if(n > 1) f[n] = 1;
		} else {
			while(int p = div[n]) {
				f[p]++;
				n /= p;
			}
		}
		return f;
	}
}

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(int &i: a) cin >> i;

	for(int i=1;i<n;i++) if(a[i-1]%a[i] != 0) {
		cout << 0 << '\n';
		return;
	}

	Z ans(1);

	for(int i=1;i<n;i++) {
		auto d = ntt::factorize(a[i-1] / a[i]);
		vector<int> p; p.reserve(d.size());

		int r = 1;

		for(auto [prime, q]: d) {
			p.push_back(prime);
			for(int x=0;x<q;x++) r*=prime;
		}

		assert(r == a[i-1] / a[i]);

		int cnt = 0;
		int y = m / a[i];

		for(int msk=0;msk<(1<<d.size());msk++) {
			int num = 1;
			for(int b=0;b<d.size();b++) if(msk&(1<<b)) num *= p[b];
			int sig = __builtin_popcount(msk)%2 == 1 ? -1 : 1;
			cnt += (y / num)*sig;
		}

		ans *= Z(cnt);

	}

	cout << ans.x << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ntt::init();
	int t; cin >> t;
	while(t--)
		solve();
}

