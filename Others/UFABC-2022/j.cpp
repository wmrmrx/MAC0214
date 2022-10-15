#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr int64_t MOD = 1000000007;
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

ostream& operator<<(ostream& out, Z z) {
	return out << z.x;
}

//using Z = double;


constexpr size_t MAX = 200'010;

struct node {
	array<uint32_t, 26> next;
	uint32_t cnt;
	node(): cnt(0) { next.fill(0); }
};

node v[MAX];
size_t sz = 0;

template <typename I>
void add(I first, I last, node& cur = v[0]) {
	cur.cnt++;
	if(first == last)
		return;
	size_t c = *first - 'a';
	if(cur.next[c] == 0)
		cur.next[c] = ++sz;
	add(next(first), last, v[cur.next[c]]);
}

template <typename I>
Z prob(I first, I last, node& cur) {
	if(next(first) == last)
		return Z{0};
	int total = 0;
	for(auto p: cur.next) if(p) 
		total += v[p].cnt;
	Z pcont = Z(cur.cnt - 1) / Z(cur.cnt);
	Z nxt = prob(next(first), last, v[cur.next[*next(first)-'a']]);
	return Z(1) + pcont * nxt;
}

void solve() {
	int n;
	cin >> n;

	vector<string> s(n);

	for(auto &xs: s) {
		cin >> xs;
		add(all(xs));
	}

	for(auto &xs: s) {
		cout << prob(all(xs), v[v[0].next[xs[0]-'a']]) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}

