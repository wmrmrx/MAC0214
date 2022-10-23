#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

template <int64_t MOD>
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

constexpr size_t MAX = 500'001;

using Z1 = Z<1000000007>;
using Z2 = Z<998244353>;
using Z3 = Z<1000000009>;

Z1 f1[MAX];
Z2 f2[MAX];
Z3 f3[MAX];

void precomp(int n) {
	f1[0] = Z1(1);
	f2[0] = Z2(1);
	f3[0] = Z3(1);
	for(int i=1;i<=n;i++) {
		f1[i] = f1[i-1]*Z1(i);
		f2[i] = f2[i-1]*Z2(i);
		f3[i] = f3[i-1]*Z3(i);
	}
}

void solve() {
	int n, x; cin >> n >> x;
	precomp(max(n, x));
	vector<int> a(n);
	sort(all(a));
	for(int &i: a) cin >> i;

	Z1 x1 = f1[x].inv();
	Z2 x2 = f2[x].inv();
	Z3 x3 = f3[x].inv();

	Z1 v1;
	Z2 v2; 
	Z3 v3;

	for(int v: a) {
		v1 += f1[v] * x1;
		v2 += f2[v] * x2;
		v3 += f3[v] * x3;
	}

	if(v1.x == v2.x && v2.x == v3.x) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
