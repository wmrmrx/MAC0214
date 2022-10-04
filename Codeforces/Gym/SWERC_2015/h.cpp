#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
//#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
#define dbg(...)

using u64 = uint64_t;

u64 parse_e(u64 b, u64 n, u64 m) {
	u64 unit = ((1ULL<<n)-1)<<m;
	u64 t = b/(n+m);
	u64 res = 0ULL;
	for(int i=0ULL;i<t;i++) {
		if(i) res <<= (n+m);
		res += unit;
	}
	return res;
}

u64 parse_o(u64 b, u64 n, u64 m) {
	u64 unit = (1ULL<<n)-1;
	u64 t = (b-n)/(n+m);
	u64 res = (1ULL<<n)-1;
	for(int i=0ULL;i<t;i++) {
		res <<= (n+m);
		res += unit;
	}
	return res;
}

vector<u64> get(u64 b)  {
	vector<u64> res;
	for(u64 n=1;n<=b;n++) for(u64 m=1;m<=b;m++) {
		if(n > b) break;
		if(n+m <= b && b%(n+m) == 0ULL) {
			res.push_back(parse_e(b, n, m));
		}
		if(b>=n && (b-n)%(m+n) == 0ULL) {
			res.push_back(parse_o(b, n, m));
		}
	}
	return res;
}

void solve() {
	u64 x, y;
	cin >> x >> y;
	vector<u64> ans;
	for(int i=0;i<64;i++) {
		vector<u64> res = get(i);
		ans.insert(ans.end(), all(res));		
	}

	sort(all(ans));
	ans.resize(unique(all(ans))-ans.begin());

	int res = 0;
	for(auto num: ans) if(x <= num && num <= y) {
		res++;
		dbg(num);
	}
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}

