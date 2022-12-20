#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
const long long nMOD = 500000004;
int n, k, aa[205];
vector<int> a[205];
int dp[205][205];
int res = 0;
void dfs(int u, int par)
{
    vector<int> sum(k + 1, 0);
    for (auto v : a[u])
    if (v != par)
    {
        dfs(v, u);
        for (int i = 0; i <= k; i++)
        {
            sum[i] += dp[v][i];
        }
    }
    dp[u][0] = aa[u] + sum[k];
    for (auto v : a[u])
    if (v != par)
    {
        for (int i = 1; i <= k + 1; i++)
        {
            dp[u][i] = max(dp[u][i], dp[v][i-1] + (sum[k + 1 - min(i + 1, k - i + 2)] - dp[v][k + 1 - min(i + 1, k - i + 2)]));
        }
    }
    for (int i = k; i >= 0; i--) dp[u][i] = max(dp[u][i], dp[u][i+1]);
    res = max(res, dp[u][0]);
}
void solve()
{   
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> aa[i];
    for (int i= 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    dfs(1, 0);
    cout << res;
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    // 
    #endif
    //freopen("dienbien.inp","r",stdin); freopen("dienbien.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
