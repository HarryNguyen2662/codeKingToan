#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
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

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[5005][5005], s[5005], sz[5005];
vector<int> a[5005];

void dfs(int u, int par)
{
    sz[u] = 0;
    int w = 0, ww = 0;
    if ((int)a[u].size() == 1) sz[u] = 1;
    for (auto v : a[u]) if (v != par)
    {
        dfs(v, u);
        for (int i = 0; i <= sz[u]; i++)
        for (int j = 0; j <= sz[v]; j++) 
        {
            s[i + j] = max(s[i + j], dp[u][i] + dp[v][j] + i*j);
            w = max(w, ww + dp[v][j] + j);
        }
        ww = w; w = 0;
        sz[u] += sz[v];
        for (int i = 0; i <= sz[u]; i++)
        {
            dp[u][i] = s[i];
            s[i] = 0;
        }
    }
    dp[u][1] = max(dp[u][1], ww);
    
}

void solve() 
{
    int n;
    cin >> n;
    for (int i = 1; i  <= n; i++) 
    {
        a[i].clear();
        for (int j = 0; j <= n; j++) dp[i][j] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }

    dfs(1, 0);
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dp[1][i]);
    cout << res << "\n";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
