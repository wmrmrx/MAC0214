#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

template <typename T>
struct Bit {
	vector<T> bit;
	Bit(int sz): bit(sz) {}
	T query(int id) {
		T res = 0;
		for(id+=1;id>0;id-=id&-id)
			res += bit[id-1];
		return res;
	}
	void update(int id, T val) {
		for(id+=1;id<=bit.size();id+=id&-id)
			bit[id-1]+=val;
	}
};


void solve() {
	int64_t n, k; cin >> n >> k;
	vector<int> a(n);
	for(int &i: a) {
		int64_t x;
		cin >> x;
		i = x;
	}

	set<pair<int,int>> act;

	for(int i=0;i<n;i++) {
		act.emplace(a[i], i);
	}

	int r = 0;
	while(!act.empty()) {
		int mn = act.begin()->first - r;
		if(mn * act.size() <= k ) {
			r += mn;
			k -= mn * act.size();
		} else if(act.size() <= k) {
			int c = k / act.size();
			k -= c*act.size();
			r += c;
		} else {
			vector<int> rem;
			for(auto [__val, id]: act)
				rem.push_back(id);
			sort(all(rem));
			for(int i=0;i<k;i++) {
				a[rem[i]]--;
			}
			break;
		}
		while(!act.empty() && act.begin()->first == r) {
			act.erase(act.begin());
		}
	}

	for(int i=0;i<n;i++) {
		a[i] = max<int>(0, a[i] - r);
	}
	for(int i: a) {
		int64_t x = i;
		cout << x << ' ';
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
