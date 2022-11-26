#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) //{cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

void solve() {
	int n,k; cin >> n >> k;
	vector<pair<int,int>> v(n);
	for(auto &[a,b]: v) cin >> a >> b;
	if(k <= v[0].first) {
		cout << "YES" << endl;
		return;
	}

	if(k - v[0].second > v[0].first) {
		cout << "NO" << endl;
		return;
	}

	if(max_element(all(v)) != v.begin()) {
		cout << "YES" << endl;
		return;
	}

	int des = k - v[0].second;
	swap(v[0], v.back());
	v.pop_back();

	sort(all(v), [](auto x, auto y) {
		return x.first + x.second < y.first + y.second;
	});

	multiset<int> mxa;
	for(auto [a, _b]: v) mxa.insert(a);
	multiset<pair<int,int>> act;

	while(true) {
		while(!v.empty() && v.back().first + v.back().second >= des) {
			mxa.erase(mxa.find(v.back().first));
			act.emplace(v.back());
			v.pop_back();
		}
		if(!mxa.empty() && des <= *mxa.rbegin()) {
			cout << "YES" << endl;
			return;
		}
		if(!act.empty() && des <= act.rbegin()->first) {
			cout << "YES" << endl;
			return;
		}
		if(act.empty()) {
			cout << "NO" << endl;
			return;
		}
		auto [a, b] = *act.rbegin();
		des -= b;
		act.erase(act.find(*act.rbegin()));
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
