#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) //{cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

int64_t MOD;
struct Z {
	int64_t x;
	Z() {}
	Z(const int64_t _x): x(_x%MOD<0?_x%MOD+MOD:_x%MOD) {}
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

const int MAX = 5000;
Z fat[MAX], inv[MAX];

void precomp() {
	fat[0] = inv[0] = Z{1};
	for(int i=1;i<MAX;i++) {
		fat[i] = fat[i-1] * Z{i};
		inv[i] = fat[i].inv();
	}
}

Z binom(int n, int k) {
	return fat[n] * inv[n-k] * inv[k];
}

void solve() {
	int n; cin >> n >> MOD;
	precomp();
	int h = (n)/2;

	Z ans(0);
	for(int x=h;n-x>0;x++) {
		int rem = max<int>(0, n-x-2);
		for(int q=0;q<=rem;q++) {
			Z v = binom(rem, q) * fat[x-1+q];
			Z mul = Z(h - (x - h));
			ans += v * mul;
		}
	}

	ans *= Z(n);

	cout << ans.x << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
