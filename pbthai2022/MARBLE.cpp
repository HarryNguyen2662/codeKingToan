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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());int f[605][605];
bool dd[606][605];
int n, m, k;
pair<int,int> trace[606][606];
vector<pair<pair<int,int>, pair<int,int>>> ldk;

bool maximize(int &x, const int &y)
{
    if (y > x)
    {
        x = y;
        return true;
    }

    return false;
}

int dp(int i, int j)
{
    if (f[i][j] != -1) return f[i][j];
    int &res = f[i][j];
    res = 0;
    if (dd[i][j]) 
    {
        res = i*j;
        return res;
    }
    for (int e = 1; e < i; e++)
        if (maximize(res, dp(e, j) + dp(i-e, j)))
        {
            trace[i][j] = {0, e};
        }
    for (int e = 1; e < j; e++)
        if (maximize(res, dp(i, e) + dp(i, j-e)))
        {
            trace[i][j] = {1, e};
        }
    return res;
}

void dfs(int i, int j)
{
    if (trace[i][j].se == 0) return;
    ldk.pb({{i, j}, trace[i][j]});
    pair<int,int> adu  = trace[i][j];

    if (adu.fi == 0) 
    {
        dfs(adu.se, j);
        dfs(i - adu.se, j);
    }
    else
    {
        dfs(i, adu.se);
        dfs(i, j - adu.se);
    }
}
void solve()
{
    cin >> n >> m;
    cin >> k;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) f[i][j] = -1;
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        dd[u][v] = true;
    }   
    cout << n*m - dp(n, m) << " ";

    dfs(n, m); cout << (int)ldk.size() << "\n";

    for (auto v : ldk) cout << v.fi.fi << " " << v.fi.se << " " << v.se.fi << " " << v.se.se << "\n";
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
    solve();
}
