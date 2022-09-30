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

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;

	vector<int> pre(n), suf(n);
	
	partial_sum(all(a), pre.begin());
	partial_sum(a.rbegin(), a.rend(), suf.begin());

	auto get = [&](vector<int>& s, int l, int r) {
		return s[r] - (l ? s[l-1] : 0);
	};

	vector<pair<int,int>> part; part.push_back({1, n});
	while(true) {
		int beg = part.empty() ? 1 : part.back().first + 1;
		int end = part.empty() ? n : part.back().second - 1;
		if(beg >= end) break;
		int l = beg, r = end;
		while(l < r) {
			int sl = get(pre,beg,l), sr = get(suf,r,end);
			if(sl == sr) {
				part.push_back({l, r});
				break;
			} else if(sl < sr) {
				l++;
			} else {
				r--;
			}
		}
		break;
	}


	Z ans = Z(2).fexp(part.size()-1);
	dbg(part.size());
	for(auto [l, r]: part) dbg(l, r);

	cout << ans.x << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	for(int i=0;i<t;i++) {
		solve();
	}
}
