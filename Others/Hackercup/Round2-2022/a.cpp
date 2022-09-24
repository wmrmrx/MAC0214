#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr size_t MAX = 1'000'000;
constexpr size_t A = 26;
int n;

int cnt[A][MAX];

vector<int> read() {
	string s;
	cin >> s;
	n = s.size();
	vector<int> res(n);
	for(int i=0;i<n;i++) res[i] = s[i] - 'a';
	return res;
}

void solve() {
	vector<int> v = read();

	for(int a=0;a<A;a++) fill_n(cnt[a], n, 0);
	
	for(int i=0;i<n;i++) {
		cnt[v[i]][i]++;
	}

	for(int a=0;a<A;a++)
		partial_sum(cnt[a], cnt[a]+n, cnt[a]);

	//for(int a=0;a<A;a++) {
	//	for(int i=0;i<n;i++) cout << cnt[a][i] << " \n"[i == n-1];
	//}

	auto get = [&](int a, int l, int r) {
		int res = cnt[a][r];
		if(l > 0) res -= cnt[a][l-1];
		return res;
	};

	int ans = 0;

	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		l--; r--;
		if((r-l+1)%2 == 0) continue;
		int m = (l+r)/2;
		int d = 0;
		for(int a=0;a<26;a++) {
			int diff = get(a, l, m) - get(a, m+1, r);
			if(diff == 0) continue;
			if(abs(diff) == 1) d++;
			else d = 100;
		}
		if(d == 1) {
			ans++;
			continue;
		}
		d = 0;
		for(int a=0;a<26;a++) {
			int diff = get(a, l, m-1) - get(a, m, r);
			if(diff == 0) continue;
			if(abs(diff) == 1) d++;
			else d = 100;
		}
		if(d == 1) ans++;
	}

	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	for(int i=1;i<=t;i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
