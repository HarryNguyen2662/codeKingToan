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
int n, m, na, nb, w;
vector<pair<int,int>> a[100005];
bool vit[100005];
int dd[100005];
long long re[5];

void dfs(int u, int val)
{
    re[dd[u]]++;
    vit[u] = true;
    for (auto v : a[u]) if (!vit[v.fi] && v.se <= val) dfs(v.fi, val);
}

long long get(int val)
{
    long long res = 0;
    for (int i = 1; i <= n; i++) vit[i] = false;
    for (int i = 1; i <= n; i++)
    if (vit[i] == false)
    {
        re[0] = re[1] = re[2] = 0;
        dfs(i, val);
        res += re[1]*re[2];
    }
    return res;
}
void solve() 
{
    
	cin >> n >> m >> w >> na >> nb;
	for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].pb({v, w}); a[v].pb({u, w});
    }
    for (int i = 1; i <= na; i++)
    {
        int x;
        cin >> x;
        dd[x] = 1;
    }
    for (int i = 1; i <= nb; i++)
    {
        int x; 
        cin >> x;
        dd[x] = 2;
    }
    cout << get(w) - get(w-1);
}

int main() 
{   
   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
