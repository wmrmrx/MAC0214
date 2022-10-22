#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()
#define rmin(a,b) a = min(a,b);

// iterator through all masks with n bits and m set bits
// use: for(auto it: BitIterator(n,m) { int mask = *it; ... }
// e7a130
struct BitIterator {
	struct Mask {
		uint32_t mask;
		Mask(uint32_t mask): mask(mask) {}
		bool operator!=(const Mask& rhs) const { return mask < rhs.mask; };
		void operator++(){const uint32_t t=mask|(mask-1);mask=(t+1)|(((~t&-~t)-1)>>__builtin_ffs(mask));}
		uint32_t operator*() const { return mask; }
	};
	const uint32_t n, m;
	BitIterator(const uint32_t n, const uint32_t m): n(n), m(m) {}
	Mask begin() const { return Mask((1<<m)-1); }
	Mask end() const { return Mask((1<<n)); }
};

int n, m;
int t;

vector<array<double, 2>> pos;

double dist(int i, int j) {
	return sqrt( (pos[i][0] - pos[j][0])*(pos[i][0] - pos[j][0]) +
		(pos[i][1] - pos[j][1])*(pos[i][1] - pos[j][1]));

}

double absp(array<double, 2> p) {
	return sqrt(p[0]*p[0] + p[1]*p[1]);
}

constexpr size_t MAX = (1<<17);

double dp[MAX][17];

void solve() {
	cin >> n >> m;
	t = n + m;
	pos.resize(t);
	for(int i=0;i<(1<<t);i++) {
		for(int j=0;j<t;j++)
			dp[i][j] = 1e100;
	}
	for(int j=0;j<t;j++) dp[0][j] = 0;
	for(int i=0;i<n;i++) cin >> pos[i+m][0] >> pos[i+m][1];
	for(int i=0;i<m;i++) cin >> pos[i][0] >> pos[i][1];

	for(int i=0;i<t;i++) {
		dp[1<<i][i] = absp(pos[i]);
	}

	for(int x=1;x<=t;x++) for(auto msk: BitIterator(t, x)) {
		double mult = 1;
		for(int j=0;j<m;j++) {
			if(msk & (1<<j) ) mult *= 2;
		}
		for(int y=0;y<t;y++) if(!( msk & (1<<y) )) {
			for(int b=0;b<t;b++) if(msk & (1<<b)) {
				dp[msk|(1<<y)][y] = min(dp[msk|(1<<y)][y], dp[msk][b] + dist(y,b) / mult);
			}
		}
	}

	double ans = 1e100;

	int msk = ((1<<n)-1) << m;

	for(int sub=0;sub<(1<<m);sub++) {
		double mult = 1;
		for(int i=0;i<m;i++) if((1<<i) & sub) mult *= 2;
		for(int b=0;b<t;b++) {
			ans = min(ans, dp[sub | msk][b] + absp(pos[b]) / mult);
		}
	}


	cout << fixed << setprecision(8) << ans << endl;

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
