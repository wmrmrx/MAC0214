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

constexpr size_t MAX = 100'000;

bool col[MAX];
bool v[MAX];
int cnt[2];

void solve(){
	int n; cin >> n;
	for(int i=0;i<n;i++) {
		int x; cin >> x;
		x %= 3;
		if(x) v[i] = 1;
		cnt[v[i]]++;
	}
	//for(int i=0;i<n;i++) cout << v[i]; cout << endl;
	if(cnt[0] <= cnt[1]) {
		int rem = n/2;
		cout << 0 << endl;
		for(int i=0;i<n;i++) {
			if(v[i] == 0) {
				col[i] = 0;
			} else {
				if(rem) {
					rem--;
					col[i] = 1;
				} else {
					col[i] = 0;
				}
			}
		}
	} else {
		int rem = n/2;
		cout << 2 << endl;
		for(int i=0;i<n;i++) {
			if(v[i] == 1) {
				col[i] = 0;
			} else {
				if(rem) {
					rem--;
					col[i] = 1;
				} else {
					col[i] = 0;
				}
			}
		}
	}
	for(int i=0;i<n;i++) cout << col[i]; cout << endl;
}

signed main(){
    IOS;
    solve();
}
