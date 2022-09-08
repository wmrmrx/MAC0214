#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr<<' '<<h; dbg_out(t...); }
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

constexpr size_t MAX = 300'000;

int f[MAX];

void solve() {
	int n; cin >> n;	
	int base = 0;

	vector<int> dx, dy;
	for(int i=0;i<n;i++) {
		int a, b; cin >> a >> b;
		base += min(a,b);
		if(a > b) {
			dx.push_back(a - b);
		} else if(a < b) {
			dy.push_back(b - a);
		}
	}

	sort(dx.rbegin(), dx.rend());
	sort(dy.rbegin(), dy.rend());

	vector<int> f1(n+1), f2(n+1);

	for(int i=0;i<dx.size();i++) {
		f1[i+1] = dx[i];
	}
	partial_sum(all(f1), f1.begin());
	for(int i=0;i<dy.size();i++) {
		f2[i+1] = dy[i];
	}
	partial_sum(all(f2), f2.begin()); reverse(all(f2));
	for(int i=0;i<=n;i++) {
		f[i] = f1[i] + f2[i];
	}

	int idx = max_element(f, f+n+1) - f;
	
//	for(int i=0;i<=n;i++) {
//		cout << f[i] << " \n"[i==n-1];
//	}

	int m; cin >> m;
	while(m--) {
		int a, b; cin >> a >> b;
		int d = __gcd(a, b);
		if(n%d != 0) {
			cout << -1 << '\n';
			continue;
		}
		int ans = -1;
		for(int x=idx/a;x>=0;x--) {
			if((n-a*x)%b != 0) continue;
			ans = max(ans, f[a*x]);
			break;
		}
		for(int x=idx/a+1;a*x<=n;x++) {
			if((n-a*x)%b != 0) continue;
			ans = max(ans, f[a*x]);
			break;
		}
		if(ans == -1) {
			cout << -1 << '\n';
			continue;
		}
		cout << ans + base << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	for(int i=0;i<t;i++) {
		solve();
	}
}
