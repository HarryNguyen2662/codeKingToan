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
const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int lim = 125250;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 9223372036854775807;
map<int,int> d, dd;
void solve()
{   
    int n, m;
    vector<int> ldk;
    cin >> n >> m;
    for (int i = 2; 1ll*i*i <= n; i++)
        if (n%i == 0)
        {
            ldk.pb(i);
            while(n%i == 0)
            {
                d[i]++;
                n /= i;
            }
        }
    if (n > 1)
    {
        d[n]++; ldk.pb(n);
    }
    for (int i = 2; 1ll*i*i <= m; i++)
        if (m%i == 0)
        {
            while(m%i == 0)
            {
                dd[i]++;
                m /= i;
            }
        }
    if (m > 1) dd[m]++;
    int dem = 0;
    for (auto v : ldk)
    {
       // cout << v << " ";
        long long x = d[v], y = dd[v];
        while(x*mask(dem) < y) dem++;
    }
    // cout << endl;
    // for (auto v : ldk) cout << d[v] << " ";
    // cout << endl;
    // for (auto v : ldk) cout << dd[v] << " ";
    // cout << endl;
    // cout << dem << endl;
    long long res = 0;
    for (int e = 0; e <= dem; e++)
    {
        int t = 1;
        if (e != 0) t = 2; 
        for (auto v : ldk)
        {
            long long x = t*d[v], y = dd[v];
            int de = 0;
            while(x!= 0 && (x-1)*(mask(dem)/mask(e)) >= y)
            {
                de++;
                res++;
                x--;
            }
            d[v] = x;
        }
        if (e != 0) res ++;
    }   
    cout << res;
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
