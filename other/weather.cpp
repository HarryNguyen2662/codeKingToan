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
const int oo = 2e9;
vector<int> a[1000];
int cnt = 0;
int low[1000], num[1000];
int numnode[1000];
long long ans;
int n;
void dfs(int u, int par)
{
     low[u] = num[u] = ++cnt;
     numnode[u] = 1;
     for(auto v : a[u])
     if (v != par)
     {
          if (num[v])
          {
               low[u] = min(low[u],num[v]);
          }
          else
          {
               dfs(v, u);
               low[u] = min(low[u], low[v]);
               numnode[u] += numnode[v];
               if (low[v] > num[u])
               {
                    //cout << u << " "<< v;
                    ans += 1ll*(numnode[v])*(n - numnode[v]);
               }
          }
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
     int  m, u, v;
     cin >> n;
     cin >> m;
     while (m--)
     {
          cin >> u >> v;
          a[u].pb(v);
          a[v].pb(u);
     }
     dfs(1, 1);
     cout << ans;
}