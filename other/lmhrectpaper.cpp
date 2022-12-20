#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
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
pair<int,int> a[4];
void solve()
{
    vector<pair<long long, long long > > ldk;
    cin >> a[1].fi >> a[1].se >> a[2].fi >> a[2].se >> a[3].fi >> a[3].se;
    int res = 0;
    for (int i = 0; i < 2; i++)
    {
        if (i) swap(a[1].fi, a[1].se);
        for (int j = 0; j < 2; j++)
        {
            if (j) swap(a[2].fi, a[2].se);
            for (int e = 0; e < 2; e++)
            {
                if (e) swap(a[3].fi, a[3].se);
                if (a[1].fi == a[2].fi && a[2].fi == a[3].fi)
                {
                    ldk.pb({min(a[1].fi, a[1].se + a[2].se + a[3].se), max(a[1].fi, a[1].se + a[2].se + a[3].se)});
                }
                int w = max({a[1].fi, a[2].fi, a[3].fi});
                if (a[1].fi == w)
                {
                    if (a[1].fi == a[2].fi + a[3].fi && a[2].se == a[3].se)
                    {
                        ldk.pb({min(a[1].fi, a[1].se + a[2].se), max(a[1].fi, a[1].se + a[2].se)});
                    }
                }
                else if (a[2].fi == w)
                {
                    if (a[2].fi == a[1].fi + a[3].fi && a[1].se == a[3].se)
                    {
                        ldk.pb({min(a[2].fi, a[1].se + a[2].se), max(a[2].fi, a[1].se + a[2].se)});
                    }
                }
                else
                {
                    if (a[3].fi == a[2].fi + a[1].fi && a[2].se == a[1].se)
                    {
                        ldk.pb({min(a[3].fi, a[3].se + a[2].se), max(a[3].fi, a[3].se + a[2].se)});
                    }
                }
                if (e) swap(a[3].fi, a[3].se);
            }
            if (j) swap(a[2].fi, a[2].se);
        }
        if (i) swap(a[1].fi, a[1].se);
    }
    if ((int)ldk.size() == 0)
    {
        cout << 0 <<"\n";
    }
    else
    {
        //cout << ldk.size() << endl;
        //cout << ldk[0].fi << " "<< ldk[0].se << endl;
        sort(ldk.begin(), ldk.end());
        int res = 1;
        for (int i = 1; i < (int)ldk.size(); i++) if (ldk[i] != ldk[i-1]) res++;
        cout <<res << "\n";
    }
}   
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
    //freopen("LEHOI.inp","r",stdin); freopen("LEHOI.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    
    int testcase = 1;
    cin >> testcase;    
    while (testcase--)
        solve();
}
