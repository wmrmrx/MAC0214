#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long
#define all(v) v.begin(), v.end()

struct node {
	node* next;
	int val;

	node(node* next, int val): next(next), val(val) {}
};

map<int, node*> book;

node* A = nullptr;

void solve() {
	int q; cin >> q;
	for(int i=0;i<q;i++) {
		string s; cin >> s;
		if(s[0] == 'A') {

			int x; cin >> x;
			A = new node(A, x);

		} else if(s[0] == 'D') {

			if(A) A = A->next;

		} else if(s[0] == 'S') {

			int y; cin >> y;
			book[y] = A;

		} else if(s[0] == 'L') {

			int z; cin >> z;
			if(book.find(z) == book.end()) {
				A = nullptr;
			} else {
				A = book[z];
			}

		} else {
			//unreachable
		}

		cout << (A ? A->val : -1) << " \n"[i==q-1];
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
