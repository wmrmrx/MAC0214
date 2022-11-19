#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

int a[303][303];
int ans[303][303];
int freq[303];
int cnt;

void solve() {
	int H,W,N; cin >> H >> W >> N;
	int h,w; cin >> h >> w;
	set<int> s;
	for(int i=1;i<=H;i++) for(int j=1;j<=W;j++)
		cin >> a[i][j], freq[a[i][j]]++;
	for(int i=1;i<=N;i++) {
		if(freq[i] > 0) cnt++;
	}
	for(int k=0;k<=H-h;k++) for(int l=0;l<=W-w;l++) {
		if(l == 0) {
			for(int i=k+1;i<=k+h;i++) for(int j=l+1;j<=l+w;j++) {
				int x = a[i][j];
				freq[x]--;
				if(freq[x] == 0) {
					cnt--;
				}
			}
		}

		if(l > 0) {
			int j = l+w;
			for(int i=k+1;i<=k+h;i++) {
				int x = a[i][j];
				freq[x]--;
				if(freq[x] == 0) {
					cnt--;
				}
			}
		}

		ans[k][l] = cnt;

		if(l < W-w) {
			int j = l+1;
			for(int i=k+1;i<=k+h;i++) {
				int x = a[i][j];
				freq[x]++;
				if(freq[x] == 1) {
					cnt++;
				}
			}
		}

		if(l == W-w) {
			for(int i=k+1;i<=k+h;i++) for(int j=l+1;j<=l+w;j++) {
				int x = a[i][j];
				freq[x]++;
				if(freq[x] == 1) {
					cnt++;
				}
			}
		}
	}

	for(int k=0;k<=H-h;k++) for(int l=0;l<=W-w;l++) {
		cout << ans[k][l] << " \n"[l==W-w];
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
