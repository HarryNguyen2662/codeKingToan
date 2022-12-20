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
struct DATA
{
    int lim, len, id;
};
int n;
int dem[1000005], st[1000005], ed[1000005], a[1000005], p[1000005], res[1000005], ip[1000005];
vector<int> aa[1000005];
vector<DATA> luu[1000005];
void dfs(int u, int par)
{
    int e = ed[dem[a[u]]];
    //cout  << ip[a[u]] << " " << e << endl;
    int ee = p[e];
    swap(p[ip[a[u]]], p[e]); 
    //cout << p[e] << " ";
    //cout << ip[a[u]] << " " << e << endl;
    swap(ip[a[u]], ip[ee]);
    if (dem[p[e - 1]] == dem[a[u]]) ed[dem[a[u]]]--; else ed[dem[a[u]]] = 0;
    //cout << ed[dem[a[u]]] << " " << dem[a[u]] << endl;
    dem[a[u]]++;    
    if (ed[dem[a[u]]] == 0) ed[dem[a[u]]] = e;
    st[dem[a[u]]] = e;
    // for(int i = 1; i <= n; i++) cout << p[i] << " ";
    //     cout << endl;
    for (auto v : aa[u])
    {
        dfs(v, u);
    }
    for (auto x : luu[u])
    {
        int l = 1, r = n;
        while(l <= r)
        {
            int mid = (l + r)/2;
            if (dem[p[mid]] >= x.lim) r = mid - 1; else l = mid + 1;
        }
        if (l + x.len - 1 <= n) res[x.id] = p[l + x.len - 1]; else res[x.id] = -1;
    }
    // if (u == 3)
    // {
    //     for(int i = 1; i <= n; i++) cout << p[i] << " ";
    //     cout << endl;
    // }
    e = st[dem[a[u]]];
    ee = p[e];
    swap(p[ip[a[u]]], p[e]); 
    swap(ip[a[u]], ip[ee]);
    if (dem[p[e+1]] == dem[a[u]]) st[dem[a[u]]]++; else st[dem[a[u]]] = 0;
    dem[a[u]]--; 
    if (st[dem[a[u]]] == 0) st[dem[a[u]]] = e;
    ed[dem[a[u]]] = e;
}
void solve()
{
    int  q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i], 
        dem[i] = ed[i] = st[i] = 0;
        p[i] = i;
        ip[i] = i;
        aa[i].clear();
        luu[i].clear();
    }
    
    for (int i = 2; i <= n; i++)
    {
        int par;
        cin >> par;
        aa[par].pb(i);
    }
    for (int i = 1; i <= q; i++)
    {
        int u, l, k;
        cin >> u >> l >> k;
        luu[u].pb({l, k, i});
    }
    st[0] = 1; ed[0] = n;
    p[0] = p[n + 1] = n + 1; dem[n + 1] = -1;
    dfs(1, 0);
    for (int i = 1; i <= q; i++) cout << res[i] << " ";
    cout << "\n";
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
    cin >> testcase;
    while(testcase--)
        solve();
}
