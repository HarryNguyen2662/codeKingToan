#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
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
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission    
    #endif
    // freopen("paths.inp","r", stdin);
    // freopen("paths.out","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
                res+=dem[i][e];
            }
            cout << res <<" ";
        }
        cout << "\n";
    }
}   