#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

vector<int> a[50005], ldk[50005], sum[50005];

int child[50005][17], dp[50005][17], co[50005], high[50005], pa[50005][17], numchild[50005], cnt;

pair<int,int> id[50005];

void dfs(int u, int par)
{   
    pa[u][0] = par;
    
    high[u] = high[par] + 1;
    
    id[u].fi = ++cnt; ldk[co[u]].pb(cnt);
    
    if ((int)sum[co[u]].size() > 0) sum[co[u]].pb(sum[co[u]].back() + 1);
    else sum[co[u]].pb(1);
    
    for (int i = 0; i <= 15; i++) if (co[u]&mask(i)) dp[u][i] = dp[par][i] + 1; else dp[u][i] = dp[par][i];
    
    numchild[u] = 1;

    for (int i = 0; i <= 15; i ++) 
        if (co[u]&mask(i)) child[u][i] = 1;
    
    for (auto v : a[u])
    if (v != par)
    { 
        dfs(v, u);
        
        numchild[u] += numchild[v];
        
        for (int i = 0; i <= 15; i++) 
           child[u][i] += child[v][i];
    }
    
    id[u].se = ++cnt; ldk[co[u]].pb(cnt); 
    
    sum[co[u]].pb(sum[co[u]].back() - 1);
}
int getlca(int u, int v)
{
    if (high[u] < high[v]) swap(u, v);
    
    for (int i = 15; i >= 0; i--)
        if (high[pa[u][i]] >= high[v]) u = pa[u][i];
    
    if (u == v) return u;
    
    for (int i = 15; i >= 0; i--)
        if (pa[u][i] != pa[v][i])
        {
            u = pa[u][i]; v = pa[v][i];
        }
    
    return pa[u][0];
}
void query1()
{
    int u;
    cin >> u;
    
    int pos = 0;
    
    for (int i = 0; i <= 15; i++)
    {
        if (2*child[u][i] > numchild[u]) pos += mask(i);
    }
    
    int l = lower_bound(ldk[pos].begin(), ldk[pos].end(), id[u].fi) - ldk[pos].begin();
    int r = upper_bound(ldk[pos].begin(), ldk[pos].end(), id[u].se) - ldk[pos].begin();
    
    if (r - l > numchild[u]) cout << pos << "\n"; else cout << -1 << "\n";
}
void query2()
{
    int u;
    cin >> u;
    
    int pos = 0;
    
    for (int i = 0; i <= 15; i++)
    {
        if (2*(child[1][i]-child[u][i]) > numchild[1] - numchild[u]) pos += mask(i);
    }

    int l = lower_bound(ldk[pos].begin(), ldk[pos].end(), id[u].fi) - ldk[pos].begin();
    int r = upper_bound(ldk[pos].begin(), ldk[pos].end(), id[u].se) - ldk[pos].begin();

    if ((int)ldk[pos].size() - (r - l) > numchild[1] - numchild[u]) cout << pos << "\n"; else cout << -1 << "\n";
}
void query3()
{
    int u, v, uv;
    cin >> u >> v;
    uv = getlca(u, v);
    
    int pos = 0;
    
    for (int i = 0; i <= 15; i++)
    {
        if (2*(dp[u][i] + dp[v][i] - 2*dp[uv][i] + ((co[uv]&mask(i)) > 0)) > high[u] + high[v] - 2*high[uv] + 1) pos += mask(i);
    }
    
    int l = 0;
    if ((int)ldk[pos].size() > 0)
    l = lower_bound(ldk[pos].begin(), ldk[pos].end(), id[uv].fi) - ldk[pos].begin();
    
    int r = 0;
    int x = 0, y = 0;
    
    if (u == uv) x = (co[u] == pos); 
    else if((int)ldk[pos].size() > 0)
    {
        //cout << id[u].fi << endl;
        r = upper_bound(ldk[pos].begin(), ldk[pos].end(), id[u].fi) - ldk[pos].begin();
        if (r > 0  && r - 1 < (int)sum[pos].size()) x += sum[pos][r-1]; 
        if (l > 0 && l - 1 < (int)sum[pos].size()) x -= sum[pos][l-1];
        
    }
    
    if (v == uv) y = (co[v] == pos);
    else if((int)ldk[pos].size() > 0)
    {
        r = upper_bound(ldk[pos].begin(), ldk[pos].end(), id[v].fi) - ldk[pos].begin();
        if (r > 0 && r - 1 < (int)sum[pos].size()) y += sum[pos][r-1]; 
        if (l > 0 && r - 1 < (int)sum[pos].size()) y -= sum[pos][l-1];
        
    }
    
    x += y; if (co[uv] == pos) x--;
    
    if (2*x > high[u] + high[v] - 2*high[uv] + 1) cout << pos << "\n"; else cout << -1  << "\n";
}
void solve()
{
    int n, q;
    cin >> n >> q;
  
    for (int i = 1; i <= n; i++) cin >> co[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
  
    dfs(1, 0);
  
    for (int i = 1; i <= 15; i++)
        for (int j = 1; j <= n; j++)
            pa[j][i] = pa[pa[j][i-1]][i-1];
  
    while(q--)
    {
        int type;
        cin >> type;
        
        if (type == 1) query1();
        else if (type == 2) query2();
        else query3();
    }
    
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
    //cin >> testcase;
    while(testcase--)
        solve();
}
