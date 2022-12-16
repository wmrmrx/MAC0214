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

constexpr size_t N = 101;
Z dp[N][N];
int a[N][N];

void solve() {
	int n; cin >> n;
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) cin >> a[i][j];
	}
	for(int i=1;i<=n;i++) {
		if(a[i][i] == 2) {
			cout << 0 << endl;
			return;
		}
	}
	dp[1][1] = Z(2);
	for(int i=2;i<=n;i++) {
		auto &cur = dp[i];
		auto &ant = dp[i-1];
		int same = i;
		int diff = 0;
		for(int k=1;k<=i;k++) {
			if(a[k][i] == 1) {
				same = min(same, k);
			}
			if(a[k][i] == 2) {
				diff = max(diff, k);
			}
		}
		//dbg(i, same, diff);
		for(int k=same;k>diff;k--) {
			cur[k] += ant[k];
		} 
		if(same == i) {
			for(int k=i-1;k>0;k--) {
				cur[i] += ant[k];
			}
		}
//		for(int j=1;j<=i;j++) dbg(i, j, dp[i][j].x);
	}
	cout << accumulate(dp[n], dp[n]+n+1, Z(0)).x << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
