#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr int MOD = 998244353;
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


constexpr int MAX = 200'001;

int n;

void update(Z bit[], int id, Z val) {
	while(id <= n) {
		bit[id] += val;
		id += id&-id;
	}
}

Z query(Z bit[], int id) {
	Z ret = 0;
	while(id > 0) {
		ret += bit[id];
		id -= id&-id;
	}
	return ret;
}

int a[MAX];
Z dp[MAX];
Z cnt[MAX];

void solve() {
	cin >> n;
	for(int i=1;i<n;i++) cin >> a[i];
	
	update(cnt, 1, Z(1));
	update(cnt, 2, Z(-1));


	auto get = [&](int i, Z v[]) {
		return query(v, i);
	};

	for(int i=1;i<n;i++) {
		Z w = get(i, cnt);
		Z e = get(i, dp) / w;
		Z p = Z(1) / Z(a[i]+1);
		e += Z(1)/p;

		dbg(i, w.x, e.x);

		w /= Z(a[i]);

		dbg(i, w.x, e.x);

		int j = i+a[i];
		update(dp, i+1, e*w); update(dp, j+1, Z(0)-e*w);
		update(cnt, i+1, w); update(cnt, j+1, Z(0)-w);
	}

	cout << get(n, dp).x << '\n';
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
