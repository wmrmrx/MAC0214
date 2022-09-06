#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

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

constexpr int MAX = 300'001;
Z fat[MAX], inv[MAX], pot[MAX];

Z comb(int a, int b) {
	return fat[a] * inv[b] * inv[a-b];
}

void init() {
	fat[0] = Z(1); inv[0] = Z(1);
	pot[0] = 1;
	for(int i=1;i<MAX;i++) {
		fat[i] = fat[i-1] * Z(i);
		inv[i] = Z(1) / fat[i];
		pot[i] = pot[i-1] * Z(2);
	}
}

void solve() {
	int n; cin >> n;
	Z ans(0);
	vector<Z> cnt(n/2+1, Z(0));
	cnt[0] = Z(1);
	for(int i=0;i<cnt.size();i++) {
		cnt[i] = comb(n-i, i);
		dbg(i, cnt[i].x);
	}
	Z inv2 = Z(1) / Z(2);
	for(int i=0;i<cnt.size();i++) {
		Z sub(0);
		for(int j=0;2*j<=i;j++) {
			dbg(i , j);
			sub += comb(i, j) * comb(i-j, j) * fat[j] * pot[j];
			dbg(sub.x);
		}
		ans += cnt[i] * sub;
		dbg(ans. x);
	}
	cout << ans.x << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
