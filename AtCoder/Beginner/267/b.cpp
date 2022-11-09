#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

int col[] = {3, 2, 4, 1, 3, 5, 0, 2, 4, 6};
int cnt[7];

void solve() {
	string s; cin >> s;
	if(s[0] == '1') {
		cout << "No" << endl;
		return;
	}
	for(int i=0;i<10;i++) {
		if(s[i] == '1') 
			cnt[col[i]]++;
	}
	for(int i=0;i<10;i++) for(int j=i+2;j<10;j++) if(cnt[i] && cnt[j]) {
		for(int k=i+1;k<j;k++) {
			if(!cnt[k]) {
				cout << "Yes" << endl;
				return;
			}
		}
	}
	cout << "No" << endl;
	return;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
