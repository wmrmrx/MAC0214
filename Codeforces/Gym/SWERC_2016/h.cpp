#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(),x.end()

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

using arr = array<uint8_t, 32>;

map<arr, int> mp;
set<int> ans;

int n;

int get(arr& x) {
		auto it = mp.find(x);
		if(it != mp.end()) {
			return it->second;
		}
		int res = 0;
		for(int i=0;i<n;i++) if(x[i]) {
			arr a = x;
			a[i]--;
			sort(&a[0], &a[n]);
			res += get(a);
		}
		return mp[x] = res;
}

void brute(arr& x, int rem, int mn, int pos) {
	if(pos < n) {
		int rem_pos = (n-1-pos);
		for(int i=mn;i*rem_pos <= rem-i;i++) {
			x[pos] = i;
			brute(x, rem-i, i, pos+1);
		}
	}
	if(pos == n && rem == 0) {
		ans.insert(get(x));
	}
}

void solve () {
	int d, h; cin >> d >> h;
	n = d;
	arr x; x.fill(0); mp[x] = 1;
	brute(x, h-1, 0, 0);
	for(int i: ans) cout << i << '\n'; 
}

signed main () {
	IOS;
	solve ();
}
