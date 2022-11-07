#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

int64_t MOD;

struct Z {
	int64_t x;
	Z(const int64_t _x=0): x(_x%MOD<0?_x%MOD+MOD:_x%MOD) {}
	Z fexp(uint64_t e) const {
		Z ret{1};
		for(Z copy=*this;e>0;e/=2,copy*=copy)if(e&1)ret*=copy;
		return ret;
	}
	Z inv()const{assert(x != 0); return this->fexp(MOD-2);}
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
	int p, _a, _b, s, _g; cin >> p >> _a >> _b >> s >> _g;
	MOD = p;
	Z a(_a), b(_b), g(_g);
	if(Z(s) == g) {
		cout << 0 << endl;
		return;
	}
	if(p <= 1000) {
		Z x(s);
		for(int i=1;i<=2*p;i++) {
			x = a*x + b;
			if(x == g) {
				cout << i << '\n';
				return;
			}
		}
		cout << -1 << endl;
		return;
	}

	if(a == Z(0)) {
		if(b == g) {
			cout << 1 << endl;
		} else {
			cout << -1 << endl;
		}
		return;
	}

	if(a == Z(1)) {
		if(b == Z(0)) {
			cout << -1 << endl;
		} else {
			cout << ( (g - s) / b ).x << '\n';
		}
		return;
	}

	int m = 1;
	while(m*m <= p) m++;

	if((a*s - s + b) == Z(0)) {
		if((g*(a-Z(1)) + b) == Z(0)) {
			cout << 1 << endl;
			return;
		}
		cout << -1 << endl;
		return;
	}

	Z res = ( g*(a-Z(1)) + b ) / (a*s - s + b);

	map<int,int> lhs;

	for(int j=0;j<m;j++) {
		int x = a.fexp(j).x;
		if(lhs.find(x) != lhs.end()) {
			lhs[x] = min(lhs[x], j);
		} else {
			lhs[x] = j;
		}
	}

	Z am = a.fexp(m).inv();

	for(int i=0;i<m;i++) {
		Z colhs = res * am.fexp(i);
		int x = colhs.x;
		if(lhs.find(x) != lhs.end()) {
			cout << i*m + lhs[x] << endl;
			return;
		}
	}

	cout << -1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
