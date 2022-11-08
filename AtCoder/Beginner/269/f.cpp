#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

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

int n, m;

Z query(int x, int y) {
	if(x == 0 || y == 0) return Z(0);

	int a = (x+1)/2, b = (y+1)/2;

	Z odd = Z(b*b)*Z(a) + Z(2*m*b) * Z(a*(a-1)/2);

	a = x/2, b = y/2;

	Z even = Z(b*b)*Z(a) + Z(2*m*b) * Z(a*(a-1)/2) +
		Z(a*b) * Z(m + 1);

	return odd + even;
}


void solve() {
	cin >> n >> m;
	int q; cin >> q;

	for(int i=0;i<q;i++) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		Z res = query(b, d) + query(a-1, c-1) - query(b, c-1) - query(a-1, d);
		cout << res.x << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
