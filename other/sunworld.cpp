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
bool special[100005];
vector<int> a[100005];
int dp[100005];
void findspecial(int u, int par)
{
    for (auto v: a[u])
      if (v!= par)
      {
        findspecial(v, u);
        if (special[v]) special[u] = true;
      }
}
int maxdist = 0, edge = 0;
void dfsfindmax(int u, int par)
{
    int dem = 0;
    for (auto v : a[u])
    if (v != par&& special[v])
    {
        dem++;
        dfsfindmax(v, u);
        if (dp[u] < dp[v] + 1)
          dp[u] = dp[v] +1;
    }
    maxdist = max(maxdist, dp[u]);
    edge += dem;
    if (dem < 2) return;
    bool kt = false;
    int w = 0;
    for (auto v : a[u])
    if (v!= par&&special[v])
    {
        if (dp[v] == dp[u] - 1&&!kt) 
        {
          kt = true;
          continue;
        }
        w = max(w, dp[v] + 1);
    }
    maxdist = max(maxdist, dp[u]+w);
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
    int n, m, u ,v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
      cin >> u;
      special[u+1] = true;
    }
    int w = u + 1;
    for (int i = 1; i < n; i++)
    {
      cin >> u >> v;
      a[u+1].pb(v+1);
      a[v+1].pb(u+1);
    }
    findspecial(w, 0);
    dfsfindmax(w, 0);
    cout << 2*edge - maxdist;
}