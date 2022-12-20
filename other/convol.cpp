#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 1e9; 
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 9223372036854775807;
vector<int> a[1005];
bool kt[1005];
int euler[3005];
int cnt = 0;
void dfs(int u, int par)
{
    euler[++cnt] = u;
    for (auto v : a[u])
    if (v != par)
    {
        dfs(v, u);
    }
    euler[++cnt] = u;
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    cout << "? " << n << " ";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
    int maxdist; cin >> maxdist;

    dfs(1, 0);
    vector<int> ldk;
    int l = 1, r = cnt;
    while (r - l > 1)
    {
        int mid = (l + r)/2;
        ldk.clear();
        for (int i = l; i <= mid; i++)
        if (kt[euler[i]] == false)
        {
            kt[euler[i]] =  true;
            ldk.pb(euler[i]);
        }
        for (int i = l; i <= mid; i++) if (kt[euler[i]]) kt[euler[i]] = false;
        int curdist = -1; 
        if ((int)ldk.size() > 1)
        {
            cout << "? " << (int)ldk.size() << " ";
            for (auto v : ldk) cout << v << " "; cout << endl;
            cin >> curdist;
        }
        if (curdist == maxdist) r = mid; else l = mid - 1;
    }
    cout << "! " << euler[l] << " " << euler[r] << endl;
}