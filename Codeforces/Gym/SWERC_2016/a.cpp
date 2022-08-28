#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(),x.end()
#define double long double

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

using pt = complex<double>;
const double PI = acos(-1);

double ang(double a, double b, double c) {
	return (b*b+c*c-a*a)/(2*b*c);
}

pt p;

void solve () {
	int n; cin >> n;
	vector<double> l(n);
	for(auto& a: l) cin >> a;
	sort(l.rbegin(),l.rend());
	double x, y; cin >> x >> y;
	p = pt(x, y);
	double a = l[0];
	double c = abs(p);;
	
	if(n == 1) {
		if(c < 1e-6) {
			p = pt(a, 0);
		} else {
			p *= a/c;
		}
		cout << p.real() << ' ' << p.imag() << endl;
		return;
	}

	double b = accumulate(l.begin()+1,l.end(),(double)0);


	if(c <= a-b) {
		if(c < 1e-6) {
			p = pt(a-b, 0);
		} else {
			p *= (a-b)/c;
		}
		c = a-b; // == p.abs()
	} else if(c >= a+b) {
		p *= (a+b)/c;
		c = a+b;
	}

	double cosa = ang(b,a,c), sena = sqrt(1-cosa*cosa);

	pt la = pt(a*cosa, a*sena), lb = pt(c, 0.0) - la;

	pt rot;
	if(c < 1e-6) rot = pt(1,0);
	else rot = p/c;

	pt tmp = la*rot;

	cout << tmp.real() << ' ' << tmp.imag() << endl;

	double len = 0;

	for(int x=1;x<l.size();x++) {
		len += l[x];

		pt tmp = la + lb*(len/c);
		tmp *= rot;

		cout << tmp.real() << ' '<< tmp.imag() << endl;

	}
}


signed main () {
	IOS;
	cout << fixed << setprecision(4);
	solve ();
}
