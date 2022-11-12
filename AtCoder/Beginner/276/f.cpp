#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){ cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

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

template <typename T>
struct Bit {
	vector<T> bit;
	Bit() {}
	Bit(int sz): bit(sz) {}
	void update(int id, T val) {
		for(id++;id<(int)bit.size();id+=id&-id) bit[id-1]+=val;
	}
	T query(int id) {
		T sum = 0;
		for(id++;id>0;id-=id&-id) sum+=bit[id-1];
		return sum;
	}
};

constexpr size_t MAX = 200'001;

void solve() {
	int n; cin >> n;
	vector<int> a(n), s(n);
	for(int &i: a) cin >> i;
	partial_sum(all(a), s.begin());
	Bit<int> qtd(MAX), sum(MAX);

	for(int i=0;i<n;i++) {
		int k = i + 1;
		sum.update(a[i], a[i]);
		qtd.update(a[i], 1);

		int tot = sum.query(MAX-1);
		int lo = 1, hi = MAX;
		while(lo < hi) {
			int m = (lo + hi)/2;
			// m >= tot / k
			if(m*k < tot) lo = m+1;
			else hi = m;
		}
		int mn = lo;
		dbg(mn);

		int q = k - qtd.query(mn-1);

		Z ans = Z(tot) / Z(k) * Z(k-q) / Z(k) + Z(tot - sum.query(mn-1)) / Z(k) ;
		cout << ans.x << endl;
	}

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
