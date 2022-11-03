#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out() {cerr << endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr <<' '<< h; dbg_out(t...); }
#define dbg(...) //{ cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int N = 1e3 + 10;
#define pb push_back

typedef long long ll;

struct point {
    ll x, y;
    point (ll x, ll y) : x (x), y (y) {}
    point () {}
    // ll norm2 () {
    //     return *this * *this;
    // }
    bool operator == (const point &o) const {
        return x == o.x && y == o.y;
    }
    bool operator != (const point &o) const {
        return !(*this == o);
    }
    point operator + (const point &o) const {
        return point (x + o.x, y + o.y);
    }
    point operator - (const point &o) const {
        return point (x - o.x, y - o.y);
    }
    point operator * (ll t) const {
        return point (x * t, y * t);
    }
    int operator * (const point &o)  const{
        return x * o.x + y * o.y;
    }
    int operator ^ (const point &o) const {
        return x * o.y - y * o.x;
    }
};

ll area2 (point a, point b, point c) {
    return (b - a) ^ (c - a);
}

bool left (point a, point b, point c) {
    return area2 (a, b, c) > 0;
}

bool collinear (point a, point b, point c) {
    return abs (area2 (a, b, c)) == 0;
}

struct line {
    point p, q;
    line (point p, point q) : p (p), q (q) {}
    line () {}
    bool segHas (point r) {
        return collinear (p, q, r)
            && (min (p.x, q.x) <= r.x && r.x <= max (p.x, q.x))
            && (min (p.y, q.y) <= r.y && r.y <= max (p.y, q.y));

    }
};

int n;
line L[N];

void solve () {
    cin >> n;

    map<pair<int, int>, vector<point>> end_points;
    for (int i = 0; i < n; i++) {
        point p, q;
        cin >> p.x >> p.y >> q.x >> q.y;
        L[i] = line (p, q);
        end_points[{p.x, p.y}].pb (q);
        end_points[{q.x, q.y}].pb (p);
    }

    auto compute = [&] (vector<int> &esq) {
        int sum = 0;
        for (auto u : esq) sum += u;
        sum *= sum;
        for (auto u : esq) sum -= u * u;
        return sum / 2;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto &[it, ends] : end_points) {
            point p = point (it.first, it.second);
            if (L[i].segHas (p) && L[i].p != p && L[i].q != p) {
                map<pair<int, int>, int> M;
                for (auto q : ends) {
                    if (collinear (L[i].p, L[i].q, q)) continue;
                    int dx = q.x - p.x, dy = q.y - p.y;
                    int d = __gcd (abs(dx), abs(dy));
                    dx /= d; dy /= d;
                    M[{dx, dy}]++;
                }

                vector<int> esq, dir;
                for (auto it1 : M) {
                    point P = point (it1.first.first, it1.first.second);
                    if (left (L[i].p, L[i].q, L[i].p + P)) {
                        esq.push_back (it1.second);
                    }
                    else dir.push_back (it1.second);
                }
                ans += compute (esq);
                ans += compute (dir);
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int t; cin >> t;
    while (t--)
	solve();
}
