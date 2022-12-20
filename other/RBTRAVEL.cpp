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

const int lim = 100000;

long long res = 0;
int sz[100005], mx[100005], dem[200005], dem1[200005], dd[200005];
vector<pair<int,int>> a[100005];
bool visit[100005];

void calsize(int u)
{
    sz[u] = 1;
    mx[u] = 0;
    visit[u] = true;

    for (auto v : a[u]) if (visit[v.fi] == false)
    {
        calsize(v.fi);
        if (sz[v.fi] > sz[mx[u]]) mx[u] = v.fi;
        sz[u] += sz[v.fi];
    }

    visit[u] = false;
}

int findroot(int u)
{
    int num = sz[u]/2;
    while(sz[mx[u]] > num) u = mx[u];
    return u;
}

void dfs1(int u, int he)
{

    res += dem1[-he + lim]; 
    if (dd[he + lim])
    {
        res += dem[-he + lim];
    }

    if (he == 0) 
    {
        res += (dd[he + lim] > 1);
    }


    dd[he + lim]++;

    visit[u] =  true;

    for (auto v : a[u]) if (visit[v.fi] == false)
    {
        dfs1(v.fi, he + v.se);
    }

    dd[he + lim]--;

    visit[u] = false;
}

void dfs2(int u, int he)
{

    if (dd[he + lim])
    {
        dem1[he + lim]++;
    } else dem[he + lim]++;
    
    dd[he + lim]++;

    visit[u] =  true;

    for (auto v : a[u]) if (visit[v.fi] == false)
    {
        dfs2(v.fi, he + v.se);
    }

    dd[he + lim]--;

    visit[u] = false;
}

void dfs3(int u, int he)
{
    if (dd[he + lim])
    {
        dem1[he + lim]--;
    } else dem[he + lim]--;
    
    dd[he + lim]++;

    visit[u] =  true;

    for (auto v : a[u]) if (visit[v.fi] == false)
    {
        dfs3(v.fi, he + v.se);
    }

    dd[he + lim]--;

    visit[u] = false;
}

void centroid(int u)
{
    calsize(u); u = findroot(u);
    visit[u] = true;
    dd[lim] = 1;
    
    for (auto v : a[u]) if (visit[v.fi] == false)
    {
        dfs1(v.fi, v.se);
        dfs2(v.fi, v.se);
    }

    for (auto v : a[u]) if (visit[v.fi] == false)
    {
        dfs3(v.fi, v.se);
    }

    for (auto v : a[u]) if (visit[v.fi] == false)
    {
        centroid(v.fi);
    }

}

void solve() 
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (!w) w = -1;
        a[u].pb({v, w}); a[v].pb({u, w});
    }

    centroid(1);

    cout << res;
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
