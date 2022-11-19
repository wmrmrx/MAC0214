#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

int n, l, r;
int nim[2001];


constexpr size_t MAX = 3000;

vector<int> id[MAX];
bool used[MAX];

void answer(int x, int y) {
	cout << x << ' ' << y << endl;
	for(int i=x;i<x+y;i++) used[i] = true;
}

void play() {

	int state = 0;

	vector<pair<int,int>> v;
	for(int pos=1;pos<=n;) {
		if(used[pos]) {
			pos++;
			continue;
		}
		int lim = pos+1;
		while(lim <= n && !used[lim]) lim++;
		state ^= nim[lim-pos];
		if(lim-pos >= l) {
			v.emplace_back(pos, lim);
		}
		pos = lim;
	}

	assert(state);

	for(auto &[a, b]: v) {
		int sz = b - a;

		for(int x=sz-l;x>=0;x--) {
			auto& match = id[nim[sz] xor state xor nim[x]];
			auto it = lower_bound(all(match), sz-r-x);
			if(it != match.end() && x + *it <= sz - l) {
				int y = *it;
				answer(a+x, sz-x-y);
				return;
			}
		}
		
		// need x, y such that sz - r <= x + y <= sz - l and nim[x] xor nim[y] = need
	}
	answer(0, 0);
	exit(0);
}

// returns true if not over
bool judge() {
	int a, b; cin >> a >> b;
	if(a == 0 && b == 0) return false;
	for(int i=a;i<a+b;i++) used[i] = true;
	return true;
}

void solve() {
	cin >> n >> l >> r;
	bool marc[MAX];
	for(int k=l;k<=n;k++) {
		memset(marc, false, sizeof(marc));
		int mex = 0;
		for(int x=0;x<=k-l;x++) for(int y=max(x, k-r-x);y<=k-l-x;y++) {
			marc[nim[x] xor nim[y]] = 1;
		}
		while(marc[mex]) {
			mex++;
		}
		nim[k] = mex;
	}
	for(int k=0;k<=n;k++) {
		id[nim[k]].push_back(k);
	}

	if(nim[n] == 0) {
		cout << "Second" << endl;
	} else {
		cout << "First\n";
		play();
	}
	while(judge()) {
		play();
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
