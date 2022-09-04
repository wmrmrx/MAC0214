#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define IOS ios::sync_with_stdio(0);cin.tie(0)

using ll = long long;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ 
  cerr << ' ' << H; 
  dbg_out(T...); 
}
#define dbg(...) cerr<<"(" << #__VA_ARGS__<<"):" , dbg_out(__VA_ARGS__) , cerr << endl

int num(int x) {
	int r = x%4;
	x = x - x/4;
	if(r >= 2) {
		x--;
	}
	return x;
}

void solve(){
	int n; cin >> n;
	if(n == 1) {
		cout << 3 << endl;
		return;
	}
	n += 2;
	int l = 0, r = 2e9;
	while(l < r) {
		int mid = (l+r)/2;
		if(num(mid) < n) l = mid+1;
		else r = mid;
	}
	cout << l << endl;
}

signed main(){
    IOS;
    solve();
}
