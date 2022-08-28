#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

void dbg_out() {cerr<<endl;}
template <typename H, typename ...T>
void dbg_out(H h, T... t) { 
	cerr << ' ' << h; dbg_out(t...);
}
#define dbg(...) { cerr<<#__VA_ARGS__<<':'; dbg_out(__VA_ARGS__);}

const int N = 1e4 + 10;
const int mod = 1e6 + 3;

bool ruim[30];
bool number[30];

struct Trie {
	int memo[N][2][2][2], memo1[N][2][2][2];

	vector<int> cnt;
	vector<vector<int>> l;
	map<string, int> M;
	int p;

	Trie () {
		p = 1;
		cnt = vector<int> (N);
		l = vector<vector<int>> (N, vector<int> (26, -1));
		M[""] = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					for (int l = 0; l < 2; l++)
						memo[i][j][k][l] = 0;
		memo[0][0][0][0] = 1;
	}

	int newNode () {
		return p++;
	}

	void add (int no, int j, string &s) {
		M[s.substr (0, j)] = no;
		if (j == s.size()) {
			cnt[no]++;
			// dbg (s, j);
			return;
		}
		if (l[no][s[j] - 'a'] == -1) l[no][s[j] - 'a'] = newNode();
		add (l[no][s[j] - 'a'], j + 1, s);
	}

	void build_automato (int no, string &cur, int &X) {
		if (cnt[no]) return;
		int aux = cnt[no];
		X += aux;
		cnt[no] = X;
		for (int i = 0; i < 26; i++) {
			cur.pb(char(i + 'a'));
			if (l[no][i] != -1) {
				build_automato (l[no][i], cur, X);
			}
			else {
				for (int j = 0; j <= cur.size(); j++) {
					if (M.find (cur.substr (j, cur.size() - j)) != M.end()) {
						l[no][i] = M[cur.substr (j, cur.size() - j)];
						break;
					}
					// assert (j != cur.size() - 1);
				}
			}
			cur.pop_back();
		}
		X -= aux;
	}

	void dp () {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					for (int l = 0; l < 2; l++)
						memo1[i][j][k][l] = 0;
		dfs_dp (0);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					for (int l = 0; l < 2; l++)
						memo[i][j][k][l] = memo1[i][j][k][l];
	}

	void dfs_dp (int no) {
		if (cnt[no]) return;
		for (int i = 0; i < 26; i++) {
			if (cnt[l[no][i]]) continue;

			// fazemos para minuscula
			for (int x = 0; x < 2; x++)
				for (int y = 0; y < 2; y++) 
					for (int z = 0; z < 2; z++) {
						memo1[l[no][i]][1][y][z] += memo[no][x][y][z];
						memo1[l[no][i]][1][y][z] %= mod;
					}
			// fazemos para maiuscula
			for (int x = 0; x < 2; x++)
				for (int y = 0; y < 2; y++) 
					for (int z = 0; z < 2; z++) {
						memo1[l[no][i]][x][1][z] += memo[no][x][y][z];
						memo1[l[no][i]][x][1][z] %= mod;
					}

			if(number[i]) {
				for (int x = 0; x < 2; x++)
					for (int y = 0; y < 2; y++) 
						for (int z = 0; z < 2; z++) {
							memo1[l[no][i]][x][y][1] += memo[no][x][y][z];
							memo1[l[no][i]][x][y][1] %= mod;
						}
			}
		}
		for (int i = 0; i < 10; i++) {
			if (ruim[i]) continue;
			for (int x = 0; x < 2; x++)
				for (int y = 0; y < 2; y++) 
					for (int z = 0; z < 2; z++) {
						memo1[0][x][y][1] += memo[no][x][y][z];
						memo1[0][x][y][1] %= mod;
					}
		}
	}
};

int A, B, n;

void solve () {
	cin >> A >> B >> n;
	Trie trie;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		trie.add(0, 0, s);
	}
	string cur;
	int X = 0;
	trie.build_automato (0, cur, X);
	dbg (trie.l[0]['x' - 'a']);
	for (int i = 1; i < A; i++) {
		trie.dp();
	}
	int ans = 0;
	for (int i = A; i <= B; i++) {
		trie.dp ();
		for (int j = 0; j < N; j++)
			ans += trie.memo[j][1][1][1];
	}
	cout << ans % mod << "\n";
}

signed main () {
	IOS;
	ruim[0] = 1;
	ruim[1] = 1;
	ruim[3] = 1;
	ruim[5] = 1;
	ruim[7] = 1;
	number['i' - 'a'] = 1;
	number['o' - 'a'] = 1;
	number['e' - 'a'] = 1;
	number['s' - 'a'] = 1;
	number['t' - 'a'] = 1;
	solve ();
}