#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

int64_t MOD = 0;
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

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	sort(all(a));

	{
		vector<int> corner = a;
		corner.resize(unique(all(corner)) - corner.begin());
		if(corner.size() == 1) {
			cout << n / 2 << '\n';
			return;
		} else if(corner.size() == 2) {
			int i = lower_bound(all(a), corner[1]) - a.begin();
			cout << i * (n-i) << '\n';
			return;
		}
	}

	vector<int> tr;

	int cur = a[0], cnt = 0;
	for(int i=0;i<n;i++) {
		if(cur != a[i]) {
			tr.push_back(cnt);
			//dbg(cnt);
			cnt = 0;
			cur = a[i];
		}
		cnt++;
	}

	partial_sum(all(tr), tr.begin());
	int ans = 0;
	for(int s: tr) {
		ans = max(ans, s * (n - s));
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
