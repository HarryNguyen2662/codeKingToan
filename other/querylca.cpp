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
int cnt = 0;
vector<int> a[300005];
int permx[300001][19], permn[300001][19], par[300001][19];
int high[300001],  dd[300001];
int lg[300001];
int n;
void dfs(int u, int pr)
{
    permx[u][0] = permn[u][0] = ++cnt;
    dd[cnt] = u;
    for (auto v: a[u])
      if (v != pr)
      {
         par[v][0] = u; 
         high[v] = high[u] + 1;
         dfs(v, u);
      }
}
void prerm()
{
    for (int i = 1; i <= log; i++)
      for (int j= 1; j <= n - mask(i) + 1; j++)
        {
          permx[j][i] = max(permx[j][i-1], permx[j+ mask(i-1) ][i-1]);
          permn[j][i] = min(permn[j][i-1], permn[j + mask(i-1) ][i-1]);
        }
    for (int i = 1; i<= n; i++)
    {
       while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
    }
}
int getmax(int l, int r) 
{
  int k = lg[r - l + 1];
  return dd[max(permx[l][k], permx[r - mask(k) + 1][k])];
}
int getmin(int l, int r) 
{
  int k = lg[r - l + 1];
  return dd[min(permn[l][k], permn[r - mask(k) + 1][k])];
}
int lca(int u, int v)
{
    if(high[v] > high[u]) swap(u,v);
    for (int i = log; i >= 0; i--) if (high[par[u][i]] >= high[v]) u = par[u][i];
    if (u == v) return u;
    for (int i = log;i >=0 ; i--) if (par[u][i]!=par[v][i])
    {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}
int main()
{
     #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    // freopen("pupil.inp","r",stdin);
    // freopen("pupil.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int u, v,mx,mn;
    cin >>n ;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    high[1] = 1;
    par[1][0] = 1;
    dfs(1,0);
    for (int i = 1; i <= log ; i++)
      for (int j = 1; j <= n; j ++)
        par[j][i] = par[par[j][i-1]][i-1];
    prerm();
    //cout << permn[1][0];
    int q;
    cin >> q;
    while(q --)
    {
      cin >> u >> v;
      mx = getmax(u, v);
      mn = getmin(u, v);
      //cout << mx << " "<< mn<<endl;
      cout << lca(mn, mx)<< endl;
    }
}