#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void dbg_out(){cerr<<endl;}
template <typename H, typename... T>
void dbg_out(H h, T... t){cerr<<' '<<h;dbg_out(t...);}
#define dbg(...) {cerr<<#__VA_ARGS__<<':';dbg_out(__VA_ARGS__);}


 int b,n;


const int MAXN = 1e6+5;
const int INF = 1e18+9;
 int num;
 vector<array<int,3>>v[MAXN];
 map<string,int>d;
 vector<string> ele;
 int gval[MAXN];
 int gcus[MAXN];
 int gin[MAXN];
 int dp[MAXN];

 
 
 void dis(){
    set<pair<int, int>> s;
    for (int i = 0; i < num; i++) {
        gcus[i] = (gin[i]) ? INF : 0;
        gval[i] = 0;
        s.insert({gcus[i], i});
    }
    while(!s.empty()){
        int u = s.begin()->second;
        s.erase(s.begin());
        for (auto edge : v[u]) {
            auto [cus, pres, viz] = edge;
            if (gcus[viz] == gcus[u] + cus) {
                gval[viz] = max(gval[viz], gval[u] + pres);
            }
            if (gcus[viz] > gcus[u] + cus) {
                s.erase({gcus[viz], viz});
                gcus[viz] = gcus[u] + cus;
                gval[viz] = gval[u] + pres;
                s.insert({gcus[viz], viz});
            }
        }
    }
}
 void solve(){
     cin>>b>>n;
     string s1,s2,s3;
     int cus,pres;
     for(int i=1;i<=n;i++){
         cin>>s1>>s2>>s3;
         if(d.find(s1)==d.end()){
             d[s1]=num;
             num++;
         }
         if(d.find(s2)==d.end()){
             d[s2]=num;
             num++;
         }
         cin>>cus>>pres;
         v[d[s2]].push_back({cus,pres,d[s1]});
         gin[d[s1]]++;
     }
     dis();
     

        dp[0] = 0;
        for (int i = 1; i < MAXN; i++) dp[i] = -INF;

     for (int i = 0; i < num; i++) {
        //  dbg(i, gval[i], gcus[i]);
         for (int j = b; j >= gcus[i]; j--) {
             dp[j] = max(dp[j], dp[j-gcus[i]] + gval[i]);
         }
     }

    int bestval = -INF; int bestcost = 0;
     for (int i = 0; i <= b; i++) {
         if (dp[i] > bestval) {
             bestval = dp[i];
             bestcost = i;
         }
     }
     
     cout << bestval << "\n" << bestcost;
 }
 signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}
 

