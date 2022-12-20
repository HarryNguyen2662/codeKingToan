#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define mask(i) (1 << (i))
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6+5;
const int oo = 1e9;
long long res;
int s;
long long dp[100005], dp1[100005], max1[100005], max2[100005];
vector<pair<int,int > > a[100005];
void dfs(int u, int par)
{
    max1[u] = max2[u] = 0;
    for (auto v : a[u])
      if (v.fi != par)
      {
        dfs(v.fi, u);
        if (dp[v.fi] + v.se > max1[u]) 
        {
           max2[u] = max1[u];
           max1[u] = dp[v.fi] + v.se;
        }
        else max2[u] = max(max2[u], dp[v.fi] + v.se);
      }
      dp[u] = max1[u];
}
void dfs1(int u, int par)
{
    for (auto v : a[u])
    if(v.fi != par)
    {
        dp1[v.fi] = dp1[u] + v.se;
        if (dp[v.fi]+v.se != max1[u]) dp1[v.fi] = max(dp1[v.fi], max1[u]+v.se);
        else dp1[v.fi] = max(dp1[v.fi], max2[u] + v.se);
        if(v.se > s)
        {
            res = min(res, max(dp[v.fi], dp1[v.fi]));
        }
        else
        {   if (dp[v.fi]+v.se != max1[u])
            res = min(res, max({dp[v.fi], max1[u], dp1[u]}));
            else res = min(res, max({dp[v.fi], max2[u], dp1[u]}));
        }
        dfs1(v.fi, u);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int u,v,uv;
    cin >> n >> s;
    for (int i = 1; i < n; i++)
    {
      cin >> u >> v >> uv;
      a[u].pb({v,uv});
      a[v].pb({u,uv});
    }
    dfs(1, 0);
    res = dp[1];
    dfs1(1,0);
    cout << res;
}