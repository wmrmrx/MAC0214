#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

constexpr size_t MAXP = 110;
constexpr size_t MAXN = 1010;

int P, K;

int NIM[MAXP][MAXN];
vector<int> PILE[MAXP];

void calc_nim(int i) {
	auto& nim = NIM[i];
	auto& pile = PILE[i];
	int sz = pile.size();

	for(int i=0;i<pile.size();i++) {
		set<int> s;
		for(int j=0;j<i;j++) {
			if(j > K) break;
			int disc = pile[i-j];
			int rem = i - j - disc + 1;
			if(rem >= 0) {
				s.insert(nim[rem]);
			}
		}
		int mex = 0;
		while(s.find(mex) != s.end()) mex++;
		nim[i+1] = mex;
	}
}

void solve() {
	cin >> P >> K;
	for(int i=0;i<P;i++) {
		int sz; cin >> sz;
		PILE[i].resize(sz);
		for(int &c: PILE[i]) cin >> c;
	}
	for(int i=0;i<P;i++) {
		calc_nim(i);
	}
	int grundy = 0;
	for(int i=0;i<P;i++) {
		grundy ^= NIM[i][PILE[i].size()];
	}
	if(grundy) {
		cout << "Alice can win." << endl;
	} else {
		cout << "Bob will win." << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
