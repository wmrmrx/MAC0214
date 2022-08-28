#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(),x.end()

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;




void solve () {
	int m;
	cin >> m;
	set<tuple<int, int, int>> s1;
	set<tuple<int, int>> s2;
	set<pair<tuple<int, int, int>, tuple<int, int, int>>> ed1;
	set<pair<tuple<int, int>, tuple<int, int>>> ed2;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= m; i++) {
		int a, b, c, d, e, f;
		cin >> a >> b >> c;
		cin >> d >> e >> f;
		tuple<int, int, int> x1 = {a, b, c};
		tuple<int, int, int> y1 = {d, e, f};
		tuple<int, int> x2 = {a, b};
		tuple<int, int> y2 = {d, e};
		if (x1 > y1) swap(x1, y1);
		if (x2 > y2) swap(x2, y2);
		if (x1 != y1 && ed1.find({x1, y1}) == ed1.end()) {
			s1.insert(x1);
			s1.insert(y1);
			ed1.insert({x1, y1});
			cnt1++;
		}
		if (x2 != y2 && ed2.find({x2, y2}) == ed2.end()) {
			s2.insert(x2);
			s2.insert(y2);
			ed2.insert({x2, y2});
			cnt2++;
		}
	}

	// cout << cnt1 << " " << cnt2 << endl; cout << s1.size() << " " << s2.size() << endl;
	if (cnt1 >= s1.size()) cout << "True closed chains"<< '\n';
	else cout << "No true closed chains" << '\n';

	if (cnt2 >= s2.size()) cout << "Floor closed chains" << '\n';
	else cout << "No floor closed chains" << '\n';
}

signed main () {
	IOS;
	solve ();
}