#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(),x.end()

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

void dbg_out() {cerr<<endl;}
template <typename H, typename ...T>
void dbg_out(H h, T... t) { 
    cerr << ' ' << h; dbg_out(t...);
}
#define dbg(...) { cerr<<#__VA_ARGS__<<':'; dbg_out(__VA_ARGS__);}

const int N = 3e5 + 10;
const int mod = 998244353;

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


Z fat[N], inv[N];

void init() {
   fat[0] = fat[1] = Z(1);
   inv[0] = inv[1] = Z(1);
   for(int i = 2; i < N; i++) {
      fat[i] = Z(i)*fat[i-1];
      inv[i] = Z(1)/fat[i];
   }
}

Z comb(int a, int b) {
   return fat[a] * inv[b] * inv[a-b];
}

int n, m, a[N];

void solve () {
    cin >> n >> m;

    for(int i=0;i<n;i++)
	    cin >> a[i];
    partial_sum(a, a+n, a);
    int len = a[n-1];
    a[n-1] = 0;

    set<int> M;

    for(int i=0;i<n;i++) M.insert(a[i]);

    int duplas = 0;
    if (len % 2 == 0) {
        for (int i = 0; i < n; i++) if(M.find((a[i]+len/2)%len) != M.end()) {
		duplas++;
        }
    }
    duplas /= 2;

    dbg(duplas);

    Z ans = Z(0);
    for (int ig = 0; ig <= duplas; ig++) {
        int M = m - ig;

        if(duplas - ig > 0 && M <= 1) continue;
	if(M <= 0 && n - 2*duplas > 0) continue;

	// duplas iguais
	Z res = comb(duplas, ig) * comb(m, ig) * fat[ig];
	
	// duplas nao iguais
	res *= ( Z(M) * Z(M-1) ).fexp(duplas-ig);

	// outros
	res *= ( Z(M) ).fexp(n - 2*duplas);

	ans += res;
    }
    cout << ans.x << "\n";
}

signed main () {
    IOS;
    init();
    solve ();
}
