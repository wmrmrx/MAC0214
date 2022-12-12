#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

namespace rmq {
	template <typename T> struct RMQ {
		vector<vector<T>> dp;
		T ops(T a, T b) { return max(a,b); }
		RMQ() {}
		RMQ(int sz, T v[]) {
			int log = 64-__builtin_clzll(sz);
			dp.assign(log, vector<T>(sz));
			for(int i=0;i<sz;i++) dp[0][i] = v[i];
			for(int l=1;l<log;l++) for(int i=0;i<sz;i++) 
				dp[l][i] = ops(dp[l-1][i],dp[l-1][min(i+(1<<(l-1)), sz-1)]);
		}
		T query(int a, int b)  {
			if(a == b) return dp[0][a];
			int pot = 63-__builtin_clzll(b-a);
			return ops(dp[pot][a], dp[pot][b-(1<<pot)+1]);
		}
	};
}

using RMQ = rmq::RMQ<int>;

constexpr size_t MAX = 400;
int t[MAX][MAX];
int h_p[MAX][MAX];
int m_h_p[MAX][MAX];
int v_p[MAX][MAX];
int m_v_p[MAX][MAX];

RMQ m_h[MAX], h[MAX];

void solve() {
	int n, m; cin >> n >> m;
	for(int i=0;i<n;i++) {
		string s; cin >> s;
		for(int j=0;j<m;j++) {
			if(s[j] == '#') {
				t[i][j] = 2;
			} else if(s[j] == 'm') {
				t[i][j] = 1;
			}
		}
	}
	if(n < 3 || m < 3) {
		cout << 0 << endl;
		return;
	}

	for(int r=0;r<n;r++) {
		if(t[r][m-1] == 0) {
			h_p[r][m-1] = m;
			m_h_p[r][m-1] = m;
		} else if(t[r][m-1] == 1) {
			h_p[r][m-1] = m-1;
			m_h_p[r][m-1] = m;
		} else {
			h_p[r][m-1] = m-1;
			m_h_p[r][m-1] = m-1;
		}
		for(int c=m-2;c>=0;c--) {
			if(t[r][c] == 0) {
				h_p[r][c] = h_p[r][c+1];
				m_h_p[r][c] = m_h_p[r][c+1];
			} else if(t[r][c] == 1) {
				h_p[r][c] = c;
				m_h_p[r][c] = h_p[r][c+1];
			} else {
				h_p[r][c] = c;
				m_h_p[r][c] = c;
			}
		}
	}
	for(int c=0;c<m;c++) {
		if(t[n-1][c] == 0) {
			v_p[c][n-1] = n;
			m_v_p[c][n-1] = n;
		} else if(t[n-1][c] == 1) {
			v_p[c][n-1] = n-1;
			m_v_p[c][n-1] = n;
		} else {
			v_p[c][n-1] = n-1;
			m_v_p[c][n-1] = n-1;
		}
		for(int r=n-2;r>=0;r--) {
			if(t[r][c] == 0) {
				v_p[c][r] = v_p[c][r+1];
				m_v_p[c][r] = m_v_p[c][r+1];
			} else if(t[r][c] == 1) {
				v_p[c][r] = r;
				m_v_p[c][r] = v_p[c][r+1];
			} else {
				v_p[c][r] = r;
				m_v_p[c][r] = r;
			}
		}
	}

	for(int c=0;c<m;c++) {
		vector<int> u(n), m_u(n);
		for(int r=0;r<n;r++) {
			u[r] = h_p[r][c];
			m_u[r] = m_h_p[r][c];
		}
		h[c] = RMQ(n, u.data());
		m_h[c] = RMQ(n, m_u.data());
	}

	int ans = 0;

	for(int r=0;r<n-2;r++) {
		for(int x=0;x<m;x++) for(int y=x+2;y<m;y++) {
			int mx_r = min(v_p[x][r], v_p[y][r]);
//			dbg("CLEAR COLUMNS", r, x, y, mx_r);
			if(mx_r - r >= 3) {
				int mx_c = m_h[x+1].query(r+1, mx_r - 2);
				if(mx_c >= y) {
					ans = max(ans, 2 * (mx_r - r) + y - x - 1);
				}
			}
			mx_r = max( min(v_p[x][r], m_v_p[y][r]), min(m_v_p[x][r], v_p[y][r]) );
//			dbg("DIRTY COLUMNS", r, x, y, mx_r);
			if(mx_r - r >= 3) {
				int mx_c = h[x+1].query(r+1, mx_r - 2);
				if(mx_c >= y) {
					ans = max(ans, 2 * (mx_r - r) + y - x - 1);
				}
			}
		}
	}

//	dbg("h_p");
//	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
//		cout << h_p[i][j] << " \n"[j == m-1];
//	}
//	dbg("m_h_p");
//	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
//		cout << m_h_p[i][j] << " \n"[j == m-1];
//	}
//	dbg("v_p");
//	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
//		cout << v_p[j][i] << " \n"[j == m-1];
//	}
//	dbg("m_h_p");
//	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
//		cout << m_v_p[j][i] << " \n"[j == m-1];
//	}

	cout << ans << endl;

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
