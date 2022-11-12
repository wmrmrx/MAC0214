#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int cnt[10]; fill_n(cnt, 10, 0);
	int num = 0;
	bool valid = true;

	auto add = [&](int i) {
		int x = s[i] - '0';
		cnt[x]++;
		if(cnt[x] == 1) num++;
		if(*max_element(cnt, cnt+10) > num) valid = false;
		else valid = true;
	};

	int ans = 0;

	for(int i=0,k;i<n;i++) {
		for(k=0;k<=100 && i+k < n;k++) {
			add(i+k);
			if(valid) {
				ans++;
			}
		}
		fill_n(cnt, 10, 0);
		num = 0;
		valid = true;
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
