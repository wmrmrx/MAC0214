#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(),x.end()

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

void dbg_out() {cerr<<endl;}
template <typename H, typename ...T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr<<#__VA_ARGS__<<':'; dbg_out(__VA_ARGS__);}

#define pb push_back

const int N = 4e5 + 10;
mt19937_64 rng(3);

// 9ceeb0
template <typename T>
struct Treap {
    struct no {
        array<no*, 2> c;
        T dat;
        int sum;
        int cnt, h;

        // reverse interval
        bool rev;

        no(T dat=T()): c({0, 0}), dat(dat), cnt(1), h(rng()), rev(0), sum(dat) {}

        // propagate
        void prop() {
            if(rev) {
                swap(c[0], c[1]);
                for(no* x: c) {
                    if(x) {
                        x->rev ^= !x->rev;
                    }
                }
                rev = 0;
            }
        }

        // refresh
        no* ref() {
            cnt = 1;
            sum = dat;
            for(no* x: c) if(x) {
                x->prop();
                cnt += x->cnt;
                sum += x->dat; 
            }
            return this;
        }

        // left child size
        int l() {
            return c[0] ? c[0]->cnt : 0;
        }
    };

    using childs = array<no*, 2>;

    int sz;
    no *root;
    unique_ptr<no[]> arena;

    Treap(int mxsz): sz(0), root(0), arena(new no[mxsz]) {}

    no* new_no(T dat) {
        arena[sz] = no(dat);
        return &arena[sz++];
    }

    int cnt(no* x) { return x ? x->cnt : 0; }

    void merge(childs c, no*& res) {
        if(!c[0] || !c[1]) {
            res = c[0] ? c[0] : c[1];
            return;
        }
        for(int i: {0, 1}) c[i]->prop();
        int i = c[0]->h < c[1]->h;
        no *l = c[i]->c[!i], *r = c[!i];
        if(i) swap(l, r);
        merge({l, r}, c[i]->c[!i]);
        res = c[i]->ref();
    }

    // left treap has size pos
    void split(no* x, int pos, childs& res, int ra = 0) {
        if(!x) {
            res.fill(0);
            return;
        }
        x->prop();
        ra += x->l();
        int i = pos > ra;
        split(x->c[i], pos, res, ra+(i?1:-x->l()));
        x->c[i] = res[!i];
        res[!i] = x->ref();
    }

    int sum_range (int l, int r) {
        int ans = 0;
        array<no*, 2> sl, sr;
        split(root, l, sl);
        split(sl[1], r-l+1, sr);
        ans += sr[0]->sum;
        // sr[0]->rev = !sr[0]->rev;
        merge({sl[0], sr[0]}, root);
        merge({root, sr[1]}, root);
        return ans;
    }

    void insert(T dat, int idx) {
        childs s;
        split(root, idx, s);
        merge({s[0], new_no(dat)}, root);
        merge({root, s[1]}, root);
    }

    void erase(int idx) {
        childs sl, sr;
        split(root, idx, sl);
        split(sl[1], 1, sr);
        merge({sl[0], sr[1]}, root);
    }

    T get(int idx) {
        no* x = root;
        x->prop();
        for(int ra = x->l(); ra != idx; ra += x->l()) {
            if(ra < idx) ra++, x = x->c[1];
            else ra -= x->l(), x = x->c[0];
            x->prop();
        }
        return x->dat;
    }

    void reverse(int l, int r) {
        array<no*, 2> sl, sr;
        split(root, l, sl);
        split(sl[1], r-l+1, sr);
        sr[0]->rev = !sr[0]->rev;
        merge({sl[0], sr[0]}, root);
        merge({root, sr[1]}, root);
    }
};


int n, a[N];

void solve () {
    cin >> n;
    Treap<int> treap (4 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        treap.insert (a[i], i);
    }

    if (a[0] < 0 || a[n - 1] < 0) {
        cout << "-1\n";
        return;
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (treap.get (i) < 0) {
            int old_val = treap.get (i + 1);
            treap.erase (i + 1);
            old_val += treap.get(i);
            treap.insert (old_val, i + 1);

            int ini = 0, fim = i;
            while (ini <= fim) {
                int meio = (ini + fim) / 2;
                // dbg (ini, fim, meio);
                if (treap.sum_range (meio, i) < 0) fim = meio - 1;
                else ini = meio + 1;
            }

            ini = fim;
            ans += i - ini;
            if (ini < 0) {
                cout << "-1\n";
                return;
            }
            int sum = treap.sum_range(ini + 1, i);
            dbg (ini, i, sum);
            treap.erase (i);
            treap.insert (-sum, ini + 1);

            int dat = treap.get (ini);
            treap.erase (ini);
            treap.insert (dat + sum, ini);
            dbg (treap.get (ini));
        }
    }
    if (a[n - 1] < 0) {
        cout << "-1\n";
        return;
    }
    cout << ans << "\n";
}

// caso que dava errado:
// 3 2 -2 -2 4
// 3 0 2 -4 4
// 3 0 -2 4 0
// 3 -2 2 2 0
// 1 2 0 2 0

//      i

// (x, -y) x - y < 0
// 0 (x - y, y) y
// x - y (y - x, y) y
// 0 (z + x - y, y - x, y) y // se z + x - y < 0
// z + x - y (y - z - x, y - x, y) y // se z + x - y < 0


// 3 -2 2 2 0
// 1 2 0 2 0

// a[i], a[i + 1], a[i + 2], ..., a[j - 1], a[j]
// a[i] eh o primeiro indice tal que sum (a[i]+...+a[j] >= 0)

// ans += j - i;
// a[i],                        a[i + 1],                         a[i + 2] ... , a[j];

// a[i] + a[i + 1] +... + a[j], -(a[i + 1] + a[i + 2] +...+ a[j]), a[i + 1], a[i + 2],..., a[j - 1]

// a[1], a[2], a[3], a[4]
// a[1], a[2], a[3] + a[4], -a[4]
// a[1], a[2] + a[3] + a[4], -(a[3] + a[4]), a[3]
// a[1] + a[2] + a[3] + a[4], -(a[2] + a[3] + a[4]), a[2], a[3]

signed main () {
    IOS;
    solve ();
}

