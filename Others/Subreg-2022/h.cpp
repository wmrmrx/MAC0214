#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
//#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
#define dbg(...)

constexpr size_t MAX = 10'000;

vector<int> g[MAX];
vector<int> grev[MAX];

bool inc[MAX], outc[MAX];

int v_in_out = 0;
int cnt_in, cnt_out;

namespace kosaraju {
	int ncomp = 0;
	int comp[MAX];
	int sz[MAX];
	bool marc[MAX];
	vector<int> out;

	void dfs(int v) {
		marc[v] = 1;
		for(int p: g[v]) if(!marc[p]) {
			dfs(p);
		}
		out.push_back(v);
	}

	void paint(int v, int c) {
		marc[v] = 1;
		comp[v] = c;
		sz[c]++;
		for(int p: grev[v]) if(!marc[p]) {
			paint(p, c);
		}
	}

	void init(int n) {
		for(int i=0;i<n;i++) if(!marc[i]) dfs(i);
		reverse(all(out));
		fill_n(marc, n, false);
		for(int v: out) if(!marc[v])
			paint(v, ncomp++);

		for(int v=0;v<n;v++) {
			for(int p: g[v]) {
				if(comp[v] == comp[p]) continue;
				outc[comp[v]] = true;
				inc[comp[p]] = true;
			}
		}

		dbg(ncomp);
		for(int i=0;i<ncomp;i++) {
			if(!outc[i] && !inc[i]) {
				v_in_out += sz[i];
			}
			if(!outc[i]) cnt_out++;
			if(!inc[i]) cnt_in++;
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int r, s; cin >> r >> s;
		r--; s--;
		g[r].push_back(s);
		grev[s].push_back(r);
	}
	kosaraju::init(n);
	if(kosaraju::ncomp == 1) {
		cout << 0 << endl;
		return;
	}
	dbg(cnt_in, cnt_out);
	cout << max(cnt_in, cnt_out) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
