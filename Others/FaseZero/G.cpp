#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<":";dbg_out(__VA_ARGS__);}

int n, X = 1;

bool check_square (int k) {
    int raiz = sqrt (k);
    return ((raiz - 1) * (raiz - 1) == k || raiz * raiz == k || (raiz + 1) * (raiz + 1) == k);
}

void back (int x, int sum, vector<int> &freq) {
        dbg (x, sum);
    if (x == 0) {
        if (check_square (sum)) {
            for (int j = 1; j <= 9; j++)
                cout << freq[j] << " ";
                cout << "\n";
                exit (0);
        }
        return;
    }
    for (int j = 1; j <= 9; j++) {
        freq[j]++;
        sum += j * j;
        back (x - 1, sum, freq);
        sum -= j * j;
        freq[j]--;
    }
}

void solve() {
    cin >> n;
    // n = X++;
    vector<int> freq(10);
    // back (n, 0, freq);
    if (n == 2) {
        cout << "0 0 1 1 0 0 0 0 0\n";
        return;
    }
    if (n == 12) {
        cout << "11 0 0 0 1 0 0 0 0\n";
        return;
    }
    if (n == 15) {
        cout << "13 1 0 0 0 0 0 1 0\n";
        return;
    }
    if (n == 23) {
        cout << "21 0 0 0 0 1 0 1 0\n";
        return;
    }
    int ini = 1, fim = 1e9;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (meio * meio < n) ini = meio + 1;
        else fim = meio - 1;
    }

    int x = ini;
    freq[1] = n;

    int dif = x * x - n;
    if (dif % 3 == 2 and dif < 8) x++;
    else if (dif % 3 == 1 and dif < 16) x++;
    dif = x * x - n;

    if (dif % 3 == 2) {
        // podemos adicionar 3^2 e varios 2^2
        // se nao der, tentamos para a proxima potencia
        freq[3]++;
        freq[1]--;
        dif -= 8;

        dif /= 3;
        freq[2] += dif;
        freq[1] -= dif;
    }
    else if (dif % 3 == 1) {
        // podemos so adicionar 2^2
        freq[3] += 2;
        freq[1] -= 2;
        dif -= 16;

        dif /= 3;
        freq[2] += dif;
        freq[1] -= dif;
    }
    else {
        dif /= 3;
        freq[2] += dif;
        freq[1] -= dif;
    }

    int k = 0;
    for (int i = 1; i <= 9; i++) {
        // if (freq[i] < 0) {
        //     dbg (n);
        //     break;
        // }
        // k += i * i * freq[i];
        cout << freq[i] << " ";
        // dbg (freq[i]);
        // assert (freq[i] >= 0);
    }
    cout << "\n";

    // int raiz = sqrt (k);
    // assert ((raiz - 1) * (raiz - 1) == k || raiz * raiz == k || (raiz + 1) * (raiz + 1) == k);
    // cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--)
	solve();
}

// n: 2
// n: 12
// n: 15
// n: 23