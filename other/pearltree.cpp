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
const long long mxx = 1e15;
long long res[15];
long long dp[300005][15];
vector<int> a[300005];
void dfs(int u, int par)
{    
    for (auto v: a[u])
    if(v != par)
    {
        dfs(v, u);
        for (int i = 1; i <= 14; i++) res[i] = 0;  
        for (int i = 1; i <= 14; i++)
            for (int j = 1; j <= 14; j++)
                {
                    res[i] = (res[i] + dp[u][i]*dp[v][j]%MOD)%MOD;
                    if((i|j)!= 7 &&(j|j)!=15)
                    res[(i|j)] = (res[(i|j)] + dp[u][i]*dp[v][j]%MOD)%MOD;
                }
        for (int i = 1; i <= 14; i++) dp[u][i] = res[i];
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    #else
    //online submission
    #endif
    //freopen("string.inp", "r", stdin);freopen("string.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    char x;
    int u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x == 'D') dp[i][mask(0)] = 1;
        else if (x == 'X') dp[i][mask(1)] = 1;
        else if (x=='L') dp[i][mask(2)] = 1;
        else dp[i][mask(3)] = 1;
    }
    for (int i = 1; i< n; i++)
    {
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1, 0);
    long long ans =0;
    for (int i = 1; i <= 14; i++) ans = (ans + dp[1][i])%MOD;
    cout << ans;
}