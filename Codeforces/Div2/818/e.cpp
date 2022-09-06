#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr int64_t MOD = 1000000007;
struct Z {
	int64_t x;
	Z(const int64_t x=0): x(x%MOD<0?x%MOD+MOD:x%MOD) {}
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

namespace nt {
	constexpr int MAX = 100'001;
	int f[MAX];
	int phi[MAX];
	void crivo() {
		iota(f+1, f+MAX, 1);
		for(int i=2;i<MAX;i++) {
			if(f[i] != i) continue;
			for(int j=i*i;j<MAX;j+=i) {
				f[j] = i;
			}
		}
	}

	void compute_phi() {
		for(int i=2;i<MAX;i++) {
			phi[i] = i;
			int n = i;
			while(n != 1) {
				int p = f[n];
				while(n % p == 0) n /= p;
				phi[i] /= p;
				phi[i] *= p-1;
			}
		}
	}
}


void solve() {
	nt::crivo();
	nt::compute_phi();
	int n; cin >> n;
	Z ans(0);
	for(int d=1;d<=n;d++) {
		int x = __gcd(n, d);
		for(int k=2;n-d*k > 0;k++) {
			ans += Z((n-d*k)*d/x) * Z(nt::phi[k]);
		}
	}
	cout << ans.x << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//int t; cin >> t;
	int t = 1;
	for(int i=0;i<t;i++) {
		solve();
	}
}
