#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353; 
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18;   
const long long oooo = 9223372036854775807;
vector<pair<int,int> > a[100005];
long long dp[100005];
int p[100005];
long long child[100005];
void dfs(int u, int par)
{
    child[u] = p[u];
    for (auto v : a[u])
    if (v.fi != par)
    {
        dfs(v.fi, u);
        dp[u] += dp[v.fi] + child[v.fi]*1ll*v.se;
        child[u] += child[v.fi];
    }
}
void dfs1(int u, int par)
{
    for (auto v : a[u])
    if (v.fi != par)
    {
        dp[v.fi] = dp[v.fi] + (dp[u] - dp[v.fi] - child[v.fi]*1ll*v.se) + (child[1]-child[v.fi])*1ll*v.se;
        dfs1(v.fi, u);
    }
   // cout << u << " "<<dp[u]<<endl;
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].pb({v, w});
        a[v].pb({u, w});
    }
    for (int i = 1; i <= n; i++) cin >> p[i];
    dfs(1, 0); dfs1(1, 0);
    long long mx = -oo18, mn = oo18;
    for (int i = 1; i <= n; i++)
    {
        //cout << dp[i] << endl;
        mx = max(mx, dp[i]); 
        mn = min(mn, dp[i]);
    }
    cout << mn <<" "<< mx;
}