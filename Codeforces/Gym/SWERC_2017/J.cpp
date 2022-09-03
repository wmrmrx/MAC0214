#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}

typedef long long ll;

const double PI=acos(-1.0);
namespace fft {
    struct num {
        double x, y;
        num () {x = y = 0;}
        num (double x, double y) : x(x), y(y) {}
    };
    inline num operator + (num a, num b) {return num (a.x + b.x, a.y + b.y);}
    inline num operator - (num a, num b) {return num (a.x - b.x, a.y - b.y);}
    inline num operator * (num a, num b) {
        return num (a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
    }
    inline num conj (num a) {return num(a.x, -a.y);}

    int base = 1;
    vector<num> roots = {{0, 0}, {1, 0}};
    vector<ll> rev = {0,1};
    const double PI = acosl(-1.0);

    void ensure_base (int nbase) {
        if (nbase <= base) return;
        rev.resize (1<<nbase);
        for (int i = 0; i < (1 << nbase); i++)
            rev[i] = (rev[i>>1] >> 1) + ((i & 1) << (nbase - 1));
        roots.resize (1<<nbase);
        while (base < nbase) {
            double angle = 2 * PI / (1<<(base + 1));
            for (int i = 1 << (base - 1); i < (1 <<  base); i++) {
                roots[i<<1] = roots[i];
                double angle_i = angle * (2 * i + 1 - (1 << base));
                roots[(i<<1) + 1] = num (cos(angle_i), sin(angle_i));
            }
            base++;
        }
    }

    void fft (vector<num> &a, int n = -1) {
        if (n == -1) n = a.size();
        assert ((n & (n - 1)) == 0);
        int zeros = __builtin_ctz (n);
        ensure_base (zeros);
        int shift = base - zeros;
        for (int i = 0; i < n; i++) {
            if (i < (rev[i] >> shift)) {
                swap(a[i], a[rev[i] >> shift]);
            }
        }
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < n; i += 2 * k) {
                for (int j = 0; j < k; j++) {
                    num z = a[i + j + k] * roots[j + k];
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] = a[i + j] + z;
                }
            }
        }
    }

    vector<num> fa, fb;
    vector<ll> multiply (vector<ll> &a, vector<ll> &b);
    vector<ll> multiply_mod (vector<ll> &a, vector<ll> &b, ll m, ll eq = 0);
    vector<ll> square_mod (vector<ll> &a, ll m);
};

vector<ll> fft::multiply (vector<ll> &a, vector<ll> &b) {
    int need = a.size() + b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base (nbase);

    int sz = 1 << nbase;
    if (sz > (int) fa.size()) fa.resize (sz);
    for (int i = 0; i < sz; i++) {
        ll x = (i < (int)a.size() ? a[i] : 0);
        ll y = (i < (int)b.size() ? b[i] : 0);
        fa[i] = num(x, y);
    }

    fft(fa, sz);
    num r(0, -0.25/sz);
    for (int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
        if (i != j) fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
        fa[i] = z;
    }

    fft (fa, sz);
    vector<ll> res(need);
    for (int i = 0; i < need; i++) res[i] = fa[i].x + 0.5;
    return res;
}

const int N = 1e5 + 10;

int n;

void solve () {
    cin >> n;

    vector<int> a(N), b(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
    }

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b[i] = x;
    }

    auto c = fft::multiply (a, b);
    vector<int> freq(3);
    for (int i = 0; i < c.size(); i++) {
        freq[i % 3] += c[i];
    }

    cout << freq[1] << " " << freq[2] << " " << freq[0] << "\n";
}


signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
