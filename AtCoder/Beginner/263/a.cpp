#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int cnt[14];

void solve() {
	int x[5];
	for(int i=0;i<5;i++) {
		cin >> x[i];
		cnt[x[i]]++;
	}
	set<int> s;
	for(int i=0;i<5;i++) s.insert(cnt[x[i]]);
	if(s.size() != 2) {
		cout << "No\n";
		return;
	}
	auto it = s.begin();
	int a = *it;
	int b = *(++it);

	if(a == 2 && b == 3) {
		cout << "Yes\n";
		return;
	} else {
		cout << "No\n";
		return;
	}

}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
