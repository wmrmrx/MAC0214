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

constexpr int MAX = 100'001;

Z fat[MAX], inv[MAX];

void init() {
	fat[0] = inv[0] = Z(1);
	for(int i=1;i<MAX;i++) {
		fat[i] = fat[i-1] * Z(i);
		inv[i] = Z(1) / fat[i];
	}
}

Z comb(int a, int b) {
	return fat[a] * inv[b] * inv[a-b];
}

void solve() {
	Z pot(2);
	int n, k; cin >> n >> k;
	if(k >= n) {
		cout << pot.fexp(n).x << '\n';
		return;
	}
	Z ans(0);
	for(int i=0;i<=k;i++) {
		ans += comb(n, i);
	}
	cout << ans.x << '\n';
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	//int t; cin >> t;
	int t = 1;
	for(int i=0;i<t;i++) {
		solve();
	}
}
