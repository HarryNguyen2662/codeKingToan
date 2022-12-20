#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 20
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
bool minimize(int &x, int y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else return false;
}
int type[MAXN],cs[MAXN], numc[MAXN], xs[MAXN], h[MAXN], bo[MAXN][log+1], oldlca[MAXN];
set<int> se[MAXN];
vector<int> c[MAXN];
int dem = 0;
void dfs(int u,  int rr)
{
    type[u] = rr;
    cs[u] = ++dem;
    xs[dem] = u;
    numc[u] = 1;
    for (int i =0; i < (int)c[u].size(); i++)
    {
        h[c[u][i]] = h[u] + 1;
        dfs(c[u][i],rr);
        numc[u] +=numc[c[u][i]];
    }
}
int lca(int u, int v)
{
    //if(u == v) return bo[u][0];
    if(h[v] > h[u]) swap(u,v);
    for (int i = log; i >= 0; i--) if (h[bo[u][i]] >= h[v]) u = bo[u][i];
    if (u == v) return u;
    for (int i = log;i >=0 ; i--) if (bo[u][i]!=bo[v][i])
    {
        u = bo[u][i];
        v = bo[v][i];
    }
    return bo[u][0];
}
int getlca(int rr)
{
    if (se[rr].empty()) return 0;
    return(lca(xs[*se[rr].begin()],xs[*se[rr].rbegin()]));
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission    
    #endif
    // freopen("stalingrad.inp","r", stdin);
    // freopen("stalingrad.out","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    int n ,q, u;
    cin >> t;
    cin >> n >> q;
    for (int i = 2; i<= n; i++)
    {
        cin >> u;
        bo[i][0] = u;
        c[u].pb(i);
    }
    int m = c[1].size();
    for (int i = 0; i < m; i++)
    {
        h[c[1][i]] = 1;
        dfs(c[1][i],i);
    }
    for (int i = 1; i <= log ; i ++)
    {
        for (int j = 1; j <= n; j++)
            bo[j][i] = bo[bo[j][i-1]][i-1];
    }
    int numnut = 0, numrod =0, numx = 0;
    char kt;
    while (q--)
    {
        cin >> kt >> u;
        if (kt == '+')
        {
            if (se[type[u]].empty()) numrod++;
            numx++;
            se[type[u]].insert(cs[u]);
            numnut-=numc[oldlca[type[u]]];
            int w = getlca(type[u]);
           // cout << "lca "<<w<<endl;
            numnut += numc[w];
            oldlca[type[u]] = w;
        }
        else
        {
            se[type[u]].erase(cs[u]);
            if (se[type[u]].empty()) numrod--;
            numx--;
            numnut-=numc[oldlca[type[u]]];
            int w = getlca(type[u]);
            numnut += numc[w];
            oldlca[type[u]] = w;
        }
        cout << numrod <<" "<<numnut - numx<<"\n";
    }
    //cout << lca(7,7)<<endl;
}   