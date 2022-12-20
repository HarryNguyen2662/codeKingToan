#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1 << (i))
#define setp(x) setprecision(x)
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 0;
const int MAXN = 1e6+5;
const int oo = 1e9;
const long long oo18 = 1e18;
const long long oo15= 1e15;
long long maxflow;
int s, t;
vector<int> a[505];
long long f[505][505], c[505][505];
int  trace[505];
long long q[505];
bool bfs()
{
    memset(trace, 0 , sizeof trace);
    trace[s] = - 1;
    queue<int> q; q.push(s);

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        //cout << u << endl;
        for (auto v : a[u])
        if (trace[v] == 0 && f[u][v] < c[u][v])
        {
            //cout <<"check "<< v << endl;
            trace[v] = u;
            q.push(v);
        }
    }
    return trace[t] > 0;
}
void incmaxflow()
{
    int v = t;
    long long inc = oo15;
    while (v != s)
    {
        int u = trace[v];
        inc = min(inc, c[u][v] - f[u][v]);
        v = u;
    }
    v = t;
    while(v != s)
    {
        int u = trace[v];
        f[u][v] += inc;
        f[v][u] -= inc;
        v = u;
    }
    maxflow += inc;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
     freopen("MAFIA.inp","r",stdin); freopen("MAFIA.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v, w;
    cin >> n >> m;
    cin >> s >> t;
    t = t+n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w;
        a[i].pb(i+n); a[i+n].pb(i);
        c[i][i+n] = w;
        q[i] = w;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u+n].pb(v); a[v+n].pb(u);
        a[v].pb(u+n); a[u].pb(v+n);
        c[u+n][v] = oo15;
        c[v+n][u] = oo15;
    }
    maxflow = 0;
    while (bfs()) 
    {
        //cout <<"lo "<< endl;
        incmaxflow();
    }
   // cout << maxflow;
   // cout << endl;
    for (int i = 1; i <= n; i++)
        if (trace[i] && !trace[i+n]) cout << i <<" ";
}