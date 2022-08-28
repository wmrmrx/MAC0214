#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(),x.end()
#define double long double

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
double fat[N], memo[20][20][20];

double comb (int a, int b) {
	return fat[a] / fat[b] / fat[a - b];
}

double dp (int igual, int dif1, int dif2) {
	if (memo[igual][dif1][dif2] > -1e-8) return memo[igual][dif1][dif2];
	if (!igual and (!dif1 or !dif2)) return 0;
	int tot = igual + dif1 + dif2; double ans = 0;
	for (int i = 0; i <= igual; i++) {
		for (int j = 0; j <= dif1; j++) {
			for (int k = 0; k <= dif2; k++) {
				if (!i and !j and !k) continue;
				if (i + j + k > d) break;
				if (n - tot < d - i - j - k) continue;
				double vez = dp(igual - i, dif1 - j, dif2 - k) * comb (igual, i) * comb (dif1, j) * comb (dif2, k) * comb (n - tot, d - i - j - k);
				ans += vez;
			}
		}
	}
	if (d <= n - tot) {
		ans += comb(n, d);
		ans /= (comb(n, d) - comb(n - tot, d));
		return memo[igual][dif1][dif2] = ans;
	}
	return memo[igual][dif1][dif2] = 1 + ans / comb (n, d);
}

void solve () {
	for (int i = 0; i < 20; i++) 
		for (int j = 0; j < 20; j++)
			for (int k =0 ; k < 20; k++)
				memo[i][j][k] = -1;
	cin >> n >> d >> c;

	map<int, vector<int>> M;
	for (int i = 1; i <= c; i++) {
		int x; cin >> x;
		M[x].pb(1);
	}
	for (int i = 1; i <= c; i++) {
		int x; cin >> x;
		M[x].pb(2);
	}

	int igual = 0, dif1 = 0, dif2 = 0;
	for (auto it : M) {
		if (it.second.size() == 1) {
			if(it.second[0] == 1) dif1++;
			else dif2++;
		}
		else igual++;
	}
	dbg (igual, dif1, dif2);
	cout << dp (igual, dif1, dif2) << "\n";
}

signed main () {
	IOS;
	cout << setprecision(6) << fixed;
	fat[0] = 1;
	for (int i = 1; i <= 50; i++)
		fat[i] = fat[i - 1] * i;
	// dbg (comb(50, 25));
	solve ();
}