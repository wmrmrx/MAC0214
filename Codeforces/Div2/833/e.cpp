#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) //{cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

template <typename T> struct RMQ {
	vector<vector<T>> dp;
	inline T ops(const T a, const T b) const { 
		if(a.first != b.first) {
			if(a.first > b.first) {
				return a;
			} else {
				return b;
			}
		}
		else {
			if(a.second < b.second) {
				return a;
			} else {
				return b;
			}
		}
	}
	RMQ() {}
	RMQ(int sz, T v[]) {
		int log = 64-__builtin_clzll(sz);
		dp.assign(log, vector<T>(sz));
		for(int i=0;i<sz;i++) dp[0][i] = v[i];
		for(int l=1;l<log;l++) for(int i=0;i<sz;i++) 
			dp[l][i] = ops(dp[l-1][i],dp[l-1][min(i+(1<<(l-1)), sz-1)]);
	}
	T query(int a, int b)  {
		if(a == b) return dp[0][a];
		int pot = 63-__builtin_clzll(b-a);
		return ops(dp[pot][a], dp[pot][b-(1<<pot)+1]);
	}
};


constexpr int64_t MOD = 1'000'000'007;
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

constexpr size_t MAX = 200'000;

pair<int,int> g[MAX];

void solve() {
	int n, m; cin >> n >> m;

	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	RMQ<pair<int,int>> rmq(n, a.data());

	function<int(int, int)> build = [&](int l, int r) -> int {
		if(l > r) {
			return -1;
		}
		auto [_ignore, id] = rmq.query(l, r);
		g[id] = {build(l,id-1), build(id+1, r)};
		return id;
	};

	int root = build(0, n-1);
	vector<vector<Z>> dp(n, vector<Z>(m+1));

	function<void(int)> calc = [&](int v) {
		if(v == -1) return;
		auto [l, r] = g[v];
		calc(l); calc(r);
		if(l == -1) {
			dp[v][1] = Z(1);
		} else {
			dp[v][1] = Z(0);
		}
		for(int i=2;i<=m;i++) {
			dp[v][i] = Z(1);
			if(l != -1) {
				dp[v][i] *= dp[l][i-1];
			} 
			if(r != -1) {
				dp[v][i] *= dp[r][i];
			}
			dp[v][i] += dp[v][i-1];
		}
		return;
	};

	calc(root);

	cout << dp[root][m].x << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
