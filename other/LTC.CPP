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
vector<int> a[100005];
int lca[100005][log+5], high[100005], dem[100005], de[100005];
void dfs(int u, int par)
{
    high[u] = high[par] + 1;
    for (auto v : a[u])
    if (v != par)
    {
        lca[v][0] = u;
        dfs(v, u);
    }
}
int findlca(int u, int v)
{
    if (high[u] < high[v]) swap(u, v);
    for (int i = log; i >= 0; i--)
    if (high[lca[u][i]] >= high[v]) u = lca[u][i];
    if (u == v) return u;
    for (int i = log; i >= 0; i--) if (lca[u][i] != lca[v][i]) u = lca[u][i], v = lca[v][i];
    return lca[u][0];
}
long long power(int n)
{
    if (n == 0) return 1;
    long long w = power(n/2);
    
    if (n%2) return 2ll*w%MOD*w%MOD; else return w*w%MOD;
}
long long res = 0, res1 = 0;
void dfs1(int u, int par)
{
    for (auto v : a[u])
    if (v != par)
    {
        dfs1(v, u);
        dem[u] = dem[u] + dem[v]; 
        de[u] = de[u] + de[v];
    }
    //cout << u << " " << dem[u] << " " << de[u] << endl;
    res = (res + power(dem[u]) - 1 + MOD)%MOD;
    res1 = (res1 + power(de[u]) - 1 + MOD)%MOD;  
}
void solve()
{   
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= log; i++) for (int j = 1; j <= n; j++) lca[j][i] = lca[lca[j][i-1]][i-1];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        int uv = findlca(u, v);
        //cout << "hi " << u << " " << v << " " << uv << endl;
        dem[u]++; dem[v]++;
        dem[lca[uv][0]] --;
        dem[uv] --;
        de[u]++; de[v]++;
        de[uv] -= 2; 
    }
    dfs1(1, 0);
    cout << (res - res1 + MOD + 1)%MOD;
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
