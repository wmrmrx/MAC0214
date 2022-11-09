#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(), v.end()

void dbg_out() {cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << h << ' '; dbg_out(t...); }
#define dbg(...){cerr<<#__VA_ARGS__<<':'; dbg_out(__VA_ARGS__);}

constexpr int64_t MOD = 998244353;
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

constexpr size_t MAX = 3'000'001;
Z fat[MAX];

void solve() {
	int r,g,b,k;
	cin >> r >> g >> b >> k;
	r -= k; g -= k;


	// g + b + k + 1 posições, apenas b+k+1 validas
	Z ans = fat[g+b+k] / fat[g] / fat[b] / fat[k];

	int p = b+k;

	ans *= fat[r + p] / fat[p] / fat[r];

	cout << ans.x << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	fat[0] = Z(1);
	for(int i=1;i<MAX;i++) {
		fat[i] = fat[i-1] * Z(i);
	}	
	solve();
}
