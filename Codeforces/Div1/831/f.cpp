#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
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

constexpr size_t MAX = 2001;

Z fat[MAX], inv[MAX];

vector<int> cnt;

Z binom(int a, int b) {
	return fat[a] * inv[a-b] * inv[b];
}

void solve() {
	int n; cin >> n;
	cnt.assign(n, 0);
	for(int i=0;i<n;i++) {
		int x; cin >> x; x--;
		cnt[x]++;
	}

	vector<int> cfg;
	for(int i=0;i<n;i++) {
		int v = 0;
		for(int &c: cnt) if(c) {
			v++;
			c--;
		}
		if(!v) break;
		cfg.push_back(v);
	}

	if(cfg.size() == n) {
		cout << 1 << endl;
		return;
	}

	sort(cfg.rbegin(), cfg.rend());
	while(cfg.back() == 1) cfg.pop_back();

	Z ans(1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fat[0] = Z(1);
	inv[0] = Z(1);
	for(int i=1;i<MAX;i++) {
		fat[i] = fat[i-1]*Z(i);
		inv[i] = fat[i].inv();
	}
	solve();
}
