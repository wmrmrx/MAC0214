#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

typedef long long ll;
#define pb push_back

struct point {
    ll x, y;
    point (ll x, ll y) : x(x), y(y) {}
    point () {}

    point operator + (const point & other) const {
        return point (x + other.x, y + other.y);
    }
    point operator - (const point & other) const {
        return point (x - other.x, y - other.y);
    }
    ll operator * (const point & other) const {
        return x * other.x + y * other.y;
    }
    point operator * (const ll t) const {
        return point (x * t, y * t);
    }
    ll operator ^ (const point & other) const {
        return x * other.y - y * other.x;
    }
    bool operator == (const point & other) const {
        return x == other.x and y == other.y;
    }
    bool operator < (const point & other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

ll area2 (point a, point b, point c) {
    return (b - a) ^ (c - a);
}

bool left (point a, point b, point c) {
    return area2 (a, b, c) > 0;
}

bool right (point a, point b, point c) {
    return area2 (a, b, c) < 0;
}

vector<point> convexHull (vector<point> p) {
    int n = p.size();
    sort(p.begin(), p.end());
    vector<point> low, up;
    for (int i = 0; i < n; i++) {
        if (i && p[i] == p[i - 1]) continue;
        while (up.size() >= 2 && !right(up[up.size() - 2], up.back(), p[i]))
            up.pop_back();
            up.pb(p[i]);    
        while (low.size() >= 2 && !left(low[low.size() - 2], low.back(), p[i]))
            low.pop_back();
        low.pb(p[i]);
    }
    vector<point> ch;
    if (low.size() == 1) return low;
    for (int i = 0; i < low.size() - 1; i++)
        ch.pb(low[i]);
    for (int i = up.size() - 1; i >= 1; i--)
        ch.pb(up[i]);
    return ch;
};

struct line {
    point a, b;

    line (point A, point B) : a(A), b(B) {}
    line () {}

};

double proj (line r, point p) {
    auto [a, b] = r;
    p = p - a;
    point v = b - a;
    pair<double, double> lol;
    lol.first = v.x; lol.second = v.y;
    double den = (double) (p*v), quo =  (double) (v*v); 
    double rat = den / quo;
    
    lol.first *= rat; lol.second *= rat;

    lol.first += (double)a.x; lol.second += (double)a.y;

    // dbg(a.x, a.y, b.x, b.y, p.x, p.y);
    // dbg(lol.first, lol.second);

    p = p + a;

    double dx = (lol.first - (double)p.x), dy = (lol.second - (double)p.y);
    return sqrt(dx*dx + dy*dy);
}

int n, R;

void solve () {
    cin >> n >> R;
    vector<point> p;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        p.pb(point(x, y));
    }

    double ans = 1e18;
    auto CH = convexHull (p);
    if (CH.size() <= 2) {
        cout << (double) 0 << "\n";
        return;
    }
    n = CH.size();
    dbg (CH.size());
    int l = 0, r = 1;
    for (int l = 0; l < n; l++) {
        line t (CH[l], CH[(l + 1) % n]);

        while (true) {
            if (proj (t, CH[r]) < proj(t,  CH[(r + 1) % n]))
                r = (r + 1) % n;
            else break;
        }
        // dbg (CH[l].x, CH[l].y, CH[(l + 1) % n].x, CH[(l + 1) % n].y, CH[r].x, CH[r].y);
        ans = min(ans, proj(t, CH[r]));
    }
    cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
    cout << setprecision(10) << fixed;
	solve();
}
