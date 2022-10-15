#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr size_t MAX = 300'005;

using point = array<int, 2>;
using segment = array<point, 2>;
using triangle = array<point, 3>;

int val[MAX];
vector<int> g[MAX];

int get_area2(triangle& t) {
	int res = 0;
	for(int i=0;i<3;i++) {
		int j = i == 2 ? 0 : i+1;
		res += t[i][1]*t[j][0] - t[i][0]*t[j][1];
	}
	return abs(res);
}

map<segment, int> seg_id;

vector<int> seg_adj[MAX];

bool marc[MAX];
int dp[MAX][2];

void dfs(int v, int dad = -1) {
	marc[v] = 1;
	for(int p: g[v]) if(p != dad) {
		dfs(p, v);
		dp[v][0] += max(dp[p][0], dp[p][1]);
		dp[v][1] += dp[p][0];
	}
	dp[v][1] += val[v];
}

void solve() {
	int n; cin >> n;
	vector<triangle> v(n);
	for(int i=0;i<n;i++) {
		triangle& t = v[i];
		for(auto& p: t) {
			cin >> p[0] >> p[1];
		}
		val[i] = get_area2(t);

		for(int k=0;k<3;k++) {
			segment s = {t[k], t[(k+1)%3]};
			if(s[0] > s[1]) swap(s[0], s[1]);
			auto it = seg_id.find(s);
			if(it == seg_id.end()) {
				int id = seg_id.size();
				seg_id[s] = id;
				seg_adj[id].push_back(i);
			} else {
				int id = it->second;
				seg_adj[id].push_back(i);
			}
		}
	}

	vector<bool> ok(n);

	for(int i=0;i<n;i++) {
		triangle& t = v[i];
		ok[i] = true;
		for(int k=0;k<3;k++) {
			segment s = {t[k], t[(k+1)%3]};
			if(s[0] > s[1]) swap(s[0], s[1]);
			int id = seg_id[s];
			if(seg_adj[id].size() == 1) {
				ok[i] = false;
				break;
			}
		}
	}

	for(int i=0;i<n;i++) if(ok[i]) {
		triangle& t = v[i];
		for(int k=0;k<3;k++) {
			segment s = {t[k], t[(k+1)%3]};
			if(s[0] > s[1]) swap(s[0], s[1]);
			int id = seg_id[s];
			int j = seg_adj[id][0] == i ? seg_adj[id][1] : seg_adj[id][0];
			if(ok[j]) {
				g[i].push_back(j);
			}
		}
	}

	int ret = 0;
	for(int i=0;i<n;i++) if(!marc[i] && ok[i]) {
		dfs(i);
		ret += max(dp[i][0], dp[i][1]);
	}

	int tot = 0;
	for(int i=0;i<n;i++) tot += val[i];
	tot -= ret;

	if(tot%2) {
		cout << tot / 2 << ".5" << endl;
	} else {
		cout << tot / 2 << ".0" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
