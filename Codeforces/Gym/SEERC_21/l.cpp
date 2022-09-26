#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
// #define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
#define dbg(...)

constexpr int MAX = 3*300'000 + 1;

int n;
int v[MAX];
int s[3][MAX];
int tot[3];

int cnt(int l, int r, int c) {
	if(r > n) r = n;
	return s[c][r] - s[c][l-1];
}

bool check_zero() {
	for(int c: {0,1,2}) if(s[c][n] != n/3) return false;
	return true;
}

// returns {-1, -1} if cant
array<int, 2> check_one(int c) {
	array<int,2> ot{ (c+1)%3, (c+2)%3 };

	// desired to overwrite
	array<int, 3> des{0,0,0};
	for(int o: ot) {
		des[o] = tot[o] - n/3;
		if(des[o] < 0) {
			return {-1, -1};
		}
	}
	dbg("1", c, des[0], des[1], des[2]);
	int r = 1;
	// OVEWRITE EXACTLY des[o[i]]
	for(int l=1;l<=n;l++) {
		r = max(l, r);
		for(int o: ot) {
			dbg("BEGIN", o);
			while((r+1 <= n) && cnt(l, r, o) < des[o]) { r++; }
			dbg(l, r+1, n, cnt(l,r,o), des[o]);
		}
		bool ok = true;
		for(int o: ot) {
			if(cnt(l, r, o) != des[o]) {
				ok = false;
			}
		}
		if(ok) {
			return {l, r};
		}
	}
	return {-1, -1};
}

// returns {-1, -1, -1, -1} if cant
array<int, 2> check_two(int c) {
	dbg(c);
	array<int,2> ot{ (c+1)%3, (c+2)%3 };
	
	// desired to overwrite
	array<int, 3> des{0,0,0};
	des[c] = tot[c] - n/3;
	if(des[c] < 0) {
		return {-1, -1};
	}
	for(int o: ot) if(tot[o] > n/3) {
		des[o] = tot[o] - n/3;
	}
	dbg(des[0], des[1], des[2]);

	// OVERWRITE EXACTLY des[c], WHILE OVERWRITING AT LEAST des[o[i]] 
	int r = 1;
	for(int l=1;l<n;l++) {
		r = max(l+1, r);
		for(int o: ot) {
			while(r+1 <= n && cnt(l, r, o) < des[o]) r++;
		}
		while(r+1 <= n && cnt(l, r, c) < des[c]) r++;
		bool ok = true;
		if(cnt(l, r, c) != des[c]) {
			ok = false;
		}
		for(int o: ot) {
			if(cnt(l, r, o) < des[o]) {
				ok = false;
			}
		}
		if(ok) {
			return {l, r};
		}
	}
	return {-1, -1};
}

void solve() {
	cin >> n;
	n *= 3;
	string _s; cin >> _s;
	for(int i=0;i<n;i++) {
		v[i+1] = _s[i] - 'A';
	}
	for(int c: {0,1,2}) for(int i=1;i<=n;i++) {
		s[c][i] += s[c][i-1] + (v[i] == c);
	}
	for(int c: {0,1,2}) tot[c] = s[c][n];
	if(check_zero()) {
		cout << 0 << '\n';
		return;
	}
	for(int c: {0, 1, 2}) {
		array<int, 2> res = check_one(c);
		if(res[0] == -1) continue;
		cout << 1 << '\n' << res[0] << ' ' << res[1] << 
			' ' << (char(c+'A')) << '\n';
		return;
	}
	for(int c: {0,1,2}) {
		auto [l, r] = check_two(c);
		if(l == -1) continue;
		array<int,2> ot{ (c+1)%3, (c+2)%3 };
		int o = ot[0];
		int need = n/3 - (tot[o] - cnt(l, r, o));
		cout << 2 << endl;
		cout << l << ' ' << l + need - 1 << ' '<< (char(o+'A')) << endl;
		cout << l+need << ' ' << r << ' ' << (char(ot[1]+'A')) << endl;
		return;
	}

	cout << 3 << endl;
	n /= 3;
	cout << 1 << ' ' << n << " A" << endl;
	cout << n+1 << ' ' << 2*n << " B" << endl;
	cout << 2*n+1 << ' ' << 3*n << " C" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
