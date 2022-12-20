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
long long g[10][100005], f[10][100005];
const long long mod = 123456789;
void prepare()
{
    for (int i = 0; i < 10 ; i++) 
    {
        f[i][0] = i; g[i][0] = 10;
    }
    for (int i = 1; i <= 1e5+2; i++)
        for (int j = 0; j < 10; j++)
        {
            if (j*3 < 10) 
            {
                f[j][i] = f[j*3][i-1]; g[j][i] = g[j*3][i-1];
            }
            else
            {
                f[j][i] = (f[(j*3)/10][i-1]*g[(j*3)%10][i-1]%mod + f[(j*3)%10][i-1])%mod;
                g[j][i] = g[(j*3)/10][i-1]*g[(j*3)%10][i-1]%mod;
            }
        }
}
void solve()
{
    long long res = 0;
    long long curlen = 1;
    int k, n;
    cin >> k >> n;
    while(k > 0)
    {
        res += f[k%10][n]*curlen%mod; res %= mod;
        curlen = curlen*g[k%10][n]%mod;
        k /= 10;
    }
    cout << res << "\n";
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
    prepare();
    int testcase = 1;
    cin >> testcase;    
    while (testcase--)
        solve();
}
