#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int max_x = 1'000'000;

constexpr size_t MAX = 1000;

struct kuhn {
	int l, r;
	vector<vector<int>> g;
	vector<int> ml, mr;
	vector<bool> visl, visr;

	kuhn(int _l, int _r): l(_l), r(_r), g(l), ml(l), mr(r), visl(l), visr(r) {}

	bool dfs(int v) {
		if(visl[v]) return false;
		visl[v] = 1;
		for(auto p: g[v]) if(!visr[p]) {
			visr[p] = true;
			if(mr[p] == -1 || dfs(mr[p])) {
				ml[v] = p;
				mr[p] = v;
			}
		}
		return false;
	}

	int matching(const vector<int>& f) {
		bool t = true;
		for(auto xf: f) if(xf != -1) {
			if(xf < l) {
				if(ml[xf] != -1) {
					mr[ml[xf]] = -1;
					ml[xf] = -1;
				}
			} else {
				if(mr[xf-l] != -1) {
					ml[mr[xf-l]] = -1;
					mr[xf-l] = -1;
				}
			}
		}

		while(t) {
			t = false;
			fill(all(visl), false);
			fill(all(visr), false);
			for(auto xf: f) if(xf != -1) {
				if(xf < l) {
					visl[xf] = 1;
				} else {
					visr[xf-l] = 1;
				}
			}
			for(int i=0;i<l;i++) if(mr[i] == -1 && dfs(i)) {
				t = true;
			}
		}

		int res = 0;
		for(int i=0;i<l;i++) if(ml[i] != -1) res++;
		return res;
	}
};

int n, m;

int b0[MAX], b1[MAX], b2[MAX];
int id[MAX][MAX];
int ncomp;
int comp[MAX][MAX];

vector<kuhn> mt;
bool marked[MAX][MAX];
bool vis[MAX][MAX];

bool ok(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
void dfs(int x, int y, int& even, int &odd, const int c) {

	comp[x][y] = c;
	if((x+y)%2 == 0) id[x][y] = even++;
	else id[x][y] = odd++;

	for(int k=0;k<4;k++) {
		int px = x + dx[k], py = y + dy[k];
		if(ok(px,py) && not vis[px][py]) {
			dfs(px, py, even, odd, c);
		}
	}
}

void add(int x, int y) {
	int c = comp[x][y];
	for(int k=0;k<4;k++) {
		int cx = x, cy = y;
		int px = x + dx[k], py = y + dy[k];
		if(ok(px, py) && comp[x][y] == c) {
			if( (x+y)%2 == 1 ) {
				swap(cx, px);
				swap(cy, py);
			}
			mt[c].g[id[cx][cy]].push_back(id[px][py]);
		}
	}
}

void solve() {
	cin >> n >> m;
	int x = 0;
	for(int i=0;i<n;i++) {
		string s; cin >> s;
		for(int j=0;j<m;j++) if(s[j] == '#') {
			marked[i][j] = 1;
		}
	}

	int tot_black = 0, tot_white = 0;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		if(not marked[i][j]) {
			if( (i+j)%2 == 0 ) tot_black++;
			else tot_white++;
		}
	}

	int ANS = tot_black * (tot_black - 1) / 2 + tot_white * (tot_white - 1) / 2;
	if (abs (tot_black - tot_white) > 2 || abs (tot_black - tot_white) == 1) {
		ANS = tot_black * tot_white;
		cout << min(ANS, 1e6) << '\n';
		return;
	}
	else if (abs (tot_black - tot_white) == 2) {
		ANS = tot_black * tot_white;
		if (ANS > 1e6) {
			ANS = 1e6;
			cout << ANS << "\n";
			return;
		}
	}
	else {
		if (ANS > 1e6) {
			ANS = 1e6;
			cout << ANS << "\n";
			return;
		}
	}


	for(int i=0;i<n;i++) for(int j=0;j<m;j++) comp[i][j] = -1;

	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(not marked[i][j] and not vis[i][j]) {
		vis[i][j] = 1;
		int even = 0, odd = 0;
		dfs(i, j, even, odd, ncomp);
		ncomp++;
		mt.emplace_back(even, odd);
	}

	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(comp[i][j] != -1) add(i, j);

	int x = 0;

	vector<int> bad;
	for(int c=0;c<ncomp;c++) {
		auto &k = mt[c];
		int black = k.l, white = k.r;
		if (!(k.matching () == black && white == black)) {
			bad.push_back (c);
		}
	}
	
	if (bad.size () > 2) {
		int ANS = min (tot_black * tot_white, (int) 1e6);
		cout << ANS << "\n";
		return;
	}

	if (bad.size () == 2) {

		int total = tot_white + tot_black;
		int total_choices = total * (total - 1) / 2;

		int c1 = bad[0], c2 = bad[1];
		if(mt[c1].l < mt[c1].r) {
			swap(c1, c2);
		}
		auto &k1 = mt[c1], &k2 = mt[c2];

		// qtd de bons
		int n1 = 0, n2 = 0;

		for(int i=0;i<k1.l;i++) {
			vector<int> f{i};
			int num = k1.matching(f);
			if(num == k1.r) {
				n1++;
			}
		}

		for(int i=0;i<k2.r;i++) {
			vector<int> f{k1.l+i};
			int num = k2.matching(f);
			if(num == k2.l) {
				n2++;
			}
		}

		int ans = total_choices - n1 * n2;
		cout << min(ans, (int)1e6) << '\n';

		return;

	}

	if(bad.size() == 1) {

	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
