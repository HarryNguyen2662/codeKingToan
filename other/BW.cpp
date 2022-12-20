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

long long val[300005];
int n;

long long st[1200005];
void update(int id, int l, int r, int i, int vall)
{
    if (l > i || r < i) return;
    
    if (l == r)
    {
        st[id] = vall;
        return;
    }
    
    int mid = (l + r)/2;
    update(id*2, l, mid, i, vall); update(id*2 + 1, mid + 1, r, i, vall);
    st[id] = max(st[id*2], st[id*2+1]);
}

int lefttnode(int id, int l, int r, int leftt, int vall)
{
    if (l > leftt ||  st[id] < vall) return -1;

    if (l == r) return l;

    int mid = (l + r)/2;
    int x = lefttnode(id*2 + 1, mid + 1 , r, leftt, vall);
    if (x!=-1) return x;
    else return lefttnode(id*2, l, mid, leftt, vall);
}

int righttnode(int id, int l, int r, int rightt, int vall)
{
    if ( r < rightt || st[id] < vall) return -1;

    if (l == r) return l;

    int mid = (l + r)/2;
    int x = righttnode(id*2, l, mid, rightt, vall);
    if (x!=-1) return x;
    else return righttnode(id*2+1, mid+1, r, rightt, vall);
}


int cnt = 0, DFS[300005], inDFS[300005], high[300005], lca[300005][log+3];;
vector<int> a[300005];

void dfs(int u)
{
    DFS[u] = ++cnt;
    inDFS[cnt] = u;
    for (auto v: a[u])
    {
        lca[v][0] = u;
        high[v] = high[u] + 1;
        dfs(v);
    }
}


int findlca(int u, int v)
{
    if (high[u] < high[v]) swap(u, v);

    for (int i = log; i >= 0; i--)
        if (high[lca[u][i]] >= high[v]) u = lca[u][i];

    if (u == v) return u;

    for (int i = log; i >= 0; i--) 
        if (lca[u][i] != lca[v][i])
        {
            u = lca[u][i];
            v = lca[v][i];
        }

    return lca[u][0];
}


int cal(int i)
{
    int leftt = lefttnode(1, 1, n+1, DFS[i]-1, val[i]);
    int rightt = righttnode(1, 1, n+1, DFS[i]+1, val[i]);
    
    if (leftt == -1) leftt = rightt;
    if (rightt == -1) rightt = leftt;
    
    if (leftt == -1 || rightt == -1) return high[i];
    
    leftt = findlca(inDFS[leftt], i);
    rightt = findlca(inDFS[rightt], i);

    return min(high[i]-high[leftt], high[i]-high[rightt]) - 1;
}

void solve() 
{
    cin >> n;
    cin >> val[0];
    for (int i = 1; i <= n; i++)
    {
        int u;
        cin >> val[i] >> u; 
        a[u].pb(i);
    }

    dfs(0);

    for (int i = 1; i <= log ; i++)
    for (int j = 0; j <= n; j++) lca[j][i] = lca[lca[j][i-1]][i-1];


    update(1, 1, n+1, DFS[0], val[0]);
    
    for (int i = 1; i <= n; i++)
    {
        cout << cal(i) <<"\n";
        update(1, 1, n+1, DFS[i], val[i]);
    }
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //
    freopen("BW.inp","r",stdin); freopen("BW.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
