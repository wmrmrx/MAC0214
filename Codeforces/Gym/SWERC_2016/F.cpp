#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(),x.end()

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

void dbg_out() {cerr<<endl;}
template <typename H, typename ...T>
void dbg_out(H h, T... t) { 
	cerr << ' ' << h; dbg_out(t...);
}
#define dbg(...) { cerr<<#__VA_ARGS__<<':'; dbg_out(__VA_ARGS__);}

typedef long long ll;

#define pb push_back

const int N = 1e6 + 10;

int n, d, c;
double fat[N];

double comb (int a, int b) {
	return fat[a] / fat[b] / fat[a - b];
}

double dp (int igual, int dif1, int dif2) {
	if (!igual and (!dif1 or !dif2)) return 0;
	int tot = igual + dif1 + dif2; double ans = 0;
	for (int i = 0; i <= igual; i++) {
		for (int j = 0; j <= dif1; j++) {
			for (int k = 0; k <= dif2; k++) {
				if (!i and !j and !k) continue;
				if (i + k + k > d) break;

				ans += dp(igual - i, dif1 - j, dif2 - k) * comb
			}
		}
	}
}

void solve () {
	cin >> n >> d >> c;

}

signed main () {
	IOS;
	fat[0] = 1;
	for (int i = 1; i <= 50; i++)
		fat[i] = fat[i - 1] * i;
	dbg 
	solve ();
}