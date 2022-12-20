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
const long long MODo = 123456789; 
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 9223372036854775807;
long long a[100005];
bool cmp(const long long &x, const long long &y)
{
    return abs(x) < abs(y);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    bool kt = false;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        if (a[i] >= 0) kt = true;
    }
    sort(a+1, a + 1 + n, cmp);
    long long res = 1;
    if (!kt && k%2)
    {
        for (int i = 1; i <= k; i++) res = res*1ll*a[i]%MODo;
    }
    else
    {   
        int dem = 0;
        int l = 0, r = 0, ll = 0, rr = 0;
        for (int i = n; i >= n-k+1; i--) 
        {
            res = res*1ll*a[i]%MODo;
            if (a[i] < 0) 
            {
                dem++; l = i;
            }
            else r = i;
        }
        //cout <<res << endl;
        if (dem%2)
        {
            for (int i = n - k; i >= 1; i--)
            {
                if (a[i] < 0 && ll == 0) ll = i;
                if (a[i] >= 0 && rr == 0) rr = i;
            }
            if (ll != 0 && rr != 0 && l != 0 && r != 0)
            {
                //cout << a[r]*a[rr] << " " << a[l]*a[ll] << endl;
                if (a[r]*a[rr] < a[l]*a[ll])
                {
                    res = a[ll];
                    for (int i = n; i >= n-k+1; i--) if (i != r) res = res*1ll*a[i]%MODo;
                }
                else
                {
                    res = a[rr];
                    for (int i = n; i >= n-k+1; i--) if (i != l) res = res*1ll*a[i]%MODo;
                }
            }
            else if (ll > 0 && r != 0)
            {
                res = a[ll];
                for (int i = n; i >= n-k+1; i--) if (i != r) res = res*1ll*a[i]%MODo;
            }
            else if (rr > 0 && l != 0)
            {
                res = a[rr];
                for (int i = n; i >= n-k+1; i--) if (i != l) res = res*1ll*a[i]%MODo;
            }
        }
    }
    res = res + MODo; res %= MODo;
    cout << res << "\n";
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //freopen("putnik.inp","r",stdin); freopen("putnik.out","w",stdout);
    #endif
   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;    
    while (testcase--)
        solve();
}
