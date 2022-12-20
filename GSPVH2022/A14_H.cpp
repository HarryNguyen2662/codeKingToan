#include<bits/stdc++.h>
 
 using namespace std;
 
 #define NMOD 3
 #define ll long long
 #define fi first
 #define se second
 #define pb push_back
 #define log 17
 #define mask(i) (1ll << (i))
 #define setp(x) setprecision(x)
 #define ALL(v) v.begin(), v.end()
 #define ck(n, i) (((n) >> (i)) & 1) 
 #define getbit(x) __builtin_popcount(x)
 
 const double PI = acos(-1);
 const long long MOD = 1e9 + 7;
 const long long MOD1 = 998244353;
 const long long MODo = 123456789;
 
 const int oo = 1e9 + 100;
 const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;
 
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 int dem[505][505], d[505][505], cost[505][505];
 bool minimize(int &x, int y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else return false;
}
 
 void solve() 
 {
    int t;
    int n,m,u,v,l;
    cin >> t;
    cin >> n >> m;
    memset(d,0x3f, sizeof d);
    memset(cost,0x3f, sizeof cost);
    for (int i = 1; i<= m ; i++)
    {
        cin >> u >> v >> l;
        cost[u][v] = cost[v][u] = d[u][v] = d[v][u] = l;
    }
    for (int i = 1; i <= n; i++) d[i][i] =  0;
    for(int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j<= n; j++)
            if (d[i][j] > d[i][k] + d[j][k])
            {
                d[i][j] = d[j][k] + d[i][k];
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int node = 1; node <= n; node++)
            if (d[i][j] < oo&&d[i][j] == d[i][node] + cost[node][j])
            {
               // cout << i <<" "<<j<<" "<<node<<endl;
                dem[i][j] ++; 
            }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
           // cout << d[i][j]<<endl;
            int res = 0;
            for (int e = 1; e <= n; e++)
            if (d[i][j] < oo &&d[i][j] == d[i][e] + d[e][j])
            {
                res += dem[i][e];
            }
            cout << res <<" ";
        }
        cout << "\n";
    }
 }
 
 int main() 
 {   
     #ifndef ONLINE_JUDGE
     freopen("hellodking.txt","r",stdin);
     freopen("goodbyedking.txt","w",stdout);
     #else
     //hellooooooo
     #endif
     //freopen("paths.inp","r",stdin); freopen("paths.out","w",stdout);
     ios_base::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);  
     int testcase = 1;
     //cin >> testcase;
     while(testcase--)
         solve();
 }
