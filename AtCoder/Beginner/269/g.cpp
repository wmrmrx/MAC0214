#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define all(v) v.begin(), v.end()

constexpr size_t MAX = 200'001;

int m;
int ans[MAX];

void pass(int c, int d) {
	if(d == 0) {
		return;
	} else if(d > 0) {
		for(int i=m;i-d>=0;i--) {
			ans[i] = min(ans[i], ans[i-d]+c);
		}
	} else if(d < 0) {
		d = -d;
		for(int i=0;i+d<=m;i++) {
			ans[i] = min(ans[i], ans[i+d]+c);
		}
	}
}

void solve() {
	int n; cin >> n >> m;
	int sa = 0;
	vector<int> d;
	for(int i=0;i<n;i++) {
		int a, b; cin >> a >> b;
		sa += a;
		d.push_back(b-a);
	}
	fill_n(ans, m+1, n+1);
	ans[sa] = 0;

	sort(all(d));
	for(int i=0;i<d.size();i++) {
		int j = i;
		while(j+1 < d.size() && d[i] == d[j+1]) j++;

		int qtd = j-i+1;
		while(qtd) {
			int p = 1;
			while((1<<(p+1))-1 <= qtd) p++;
			for(int k=0;k<p;k++) {
				pass(1<<k, d[i]*(1<<k));
			}
			qtd -= (1<<p)-1;
		}
		i = j;
	}
	for(int i=0;i<=m;i++) {
		if(ans[i] > n) {
			cout << "-1\n";
		} else {
			cout << ans[i] << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
