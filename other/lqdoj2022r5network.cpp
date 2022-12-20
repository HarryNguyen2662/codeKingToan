#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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

const int lim = 100000;

int c[lim + 5], dd[lim + 5], high[lim + 5], par[lim + 5], vermx;
vector<int> adj[lim + 5], ldk[lim + 5];
bool ok[lim + 5];

bool cmp(const int &x, const int &y)
{
    return c[x] < c[y];
}

void dfs(int u, int par)
{
    if (high[u] > high[vermx]) vermx = u;
    
    for (auto v : adj[u])
    if (v != par)
    {
        high[v] = high[u] + 1;
        dfs(v, u);
    }
}

int findpar(int u)
{
    return par[u] < 0 ? u : par[u] = findpar(par[u]);
}

void merge(int u, int v)
{
    u = findpar(u); v = findpar(v);
    ok[u] = ok[v] = true;

    if (u == v) return;

    if (par[u] > par[v]) swap(u, v);

    par[u] += par[v];
    par[v] = u;
}

void solve() 
{
	int n, k, m, mxdist = 0; vector<int> dk; vector<pair<int,int>> ans;
	cin >> n >> k >> m;

	for (int i = 1; i <= n; i++) cin >> c[i];

	for (int i = 1; i <= k; i++)
	{
		int len;
        cin >> len;
        for (int j = 1; j <= len; j++)
        {
            int u;
            cin >> u;
            dd[u] = i;
        }
        par[i] = -1;
	}

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }

    for (int i = 1; i <= n; i++) 
    {
        int pa = findpar(dd[i]);
        if ((int)ldk[pa].size() == 0) dk.pb(pa);
        ldk[pa].pb(i);
    }

    for (auto e : dk)
    {
        if (ok[e] == false) continue;
        sort(ALL(ldk[e]), cmp);
       
        queue<int> qe;
       
        qe.push(ldk[e].back()); ldk[e].pop_back();
        int st = qe.front();
       
        while(!qe.empty())
        {
            int u = qe.front(); qe.pop();
            while(c[u]--)
            {
                if ((int)ldk[e].size() == 0) break;
                int v = ldk[e].back(); ldk[e].pop_back();
                
                adj[u].pb(v); adj[v].pb(u);
                
                ans.pb({u, v});
                
                c[v]--; 
                
                if (c[v]) qe.push(v);
            }
            if ((int)ldk[e].size() == 0) break;
        }

        vermx = st; high[st] = 0;
        dfs(st, 0); 
        high[vermx] = 0; 
        dfs(vermx, 0);

        mxdist = max(mxdist, high[vermx]);
    }


    cout << 1ll*(int)ans.size()*n + mxdist << "\n";

    for (auto v : ans) cout << v.fi << " " << v.se << "\n";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("NETWORK.inp","r",stdin); freopen("NETWORK.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}

/*

*/
