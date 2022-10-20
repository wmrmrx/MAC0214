#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

constexpr int64_t MOD = 998244353;
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

vector<int> primes;

void crivo() {
	const size_t MAX = 300'000;
	vector<bool> marc(MAX);
	for(int i=2;i<MAX;i++) if(!marc[i]) {
		primes.push_back(i);
		for(int j=i*i;j<MAX;j+=i) {
			marc[j] = 1;
		}
	}
	reverse(all(primes));
}

int prod = 1;

void solve() {
	int n, m; cin >> n >> m;
	Z non(m);

	Z ans(0);

	prod = 1;

	for(int i=2;i<=n;i++) {
		if(prod <= m && primes.back() == i) {
			primes.pop_back();
			prod *= i;
		}
		if(prod > m) {
			non = Z(0);
		} else {
			non *= Z(m / prod);
		}
		ans += Z(m).fexp(i) - non;
	}

	cout << ans.x << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	crivo();
	solve();
}
