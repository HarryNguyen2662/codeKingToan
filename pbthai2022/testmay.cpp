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

long long power(long long x, long long y)
{
    if (y == 0) return 1;
    long long xx = power(x, y/2);
    if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

vector<int> ldk[100005], a[100005];

int high[100005];

void dfs(int u, int par)
{
    high[u] = high[par] + 1;
    ldk[u].pb(high[u]);

    for (auto v : a[u]) if (v != par)
    {
        dfs(v, u);
        for (auto e : ldk[v]) ldk[u].pb(e);
    }

    sort(ALL(ldk[u]));
}


void solve() 
{
    int n, q;
    cin >> n >> q;
    assert(n <= 10000);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
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
