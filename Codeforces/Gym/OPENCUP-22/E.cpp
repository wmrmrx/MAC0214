#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(v) v.begin(), v.end()

void dbg_out(){ cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
//#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
#define dbg(...)
map<char,int> id;

bool beats(int a, int b) {
	return (a+1)%3 == b;
}

void solve() {
	int n, t; cin >> n >> t;
	string s;
	cin >> s;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		v[i] = id[s[i]];
	deque<int> q;
	vector<int> ans;
	for(int c: v) {
		if(q.empty()) {
			dbg(c);
			q.push_front(c);
			continue;
		}
		int f = q.front();
		dbg(f, c);
		int sz = q.size();
		if(f == c) {
			q.push_front(c);	
		} else if(beats(f, c)) {
			if(t >= sz) {
				ans.push_back(c);
			} else {
				int d = sz - t;
				for(int i=0;i<d;i++) {
					ans.push_back(f);
					q.pop_back();
				}
				ans.push_back(c);
			}
		} else {
			dbg("LOSER");
			for(int i=0;i<sz;i++)
				ans.push_back(f);
			q.clear();
			q.push_back(c);
		}
//		for(int x: ans) cout << x; cout << endl;
//		for(int x: q) cout << x; cout << endl;
	}

	while(!q.empty()) {
		ans.push_back(q.back());
		q.pop_back();
	}

	char c[3] = {'R', 'S', 'P'};

	for(int i=0;i<n;i++) {
		cout << c[ans[i]];
	} cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);  cin.tie(0);
	id['R'] = 0;
	id['S'] = 1;
id['P'] = 2;
	solve();
}
