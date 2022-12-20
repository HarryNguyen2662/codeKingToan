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
const int lim = 1e6 + 2;;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
long long dp[1005][1005];
int m, k;
long long n;
int s[1005];
void sub1()
{
    dp[0][0] = 1;
    for(int i = 0; i < n ; i++)
    for (int j = 0; j <= k; j++)
    if (dp[i][j] > 0)
    {
        if (j == k)
        { 
            if (s[i+1] == 1 || s[i+1] == 0) dp[i+1][j] += dp[i][j], dp[i+1][j] %= MOD;
            if (s[i+1] == -1 || s[i+1] == 0) dp[i+1][j] += dp[i][j], dp[i+1][j] %= MOD;
        }
        else {
            if (s[i+1] == 1 || s[i+1] == 0) dp[i+1][j+1] += dp[i][j], dp[i+1][j+1] %= MOD;
            if (s[i+1] == -1 || s[i+1] == 0) dp[i+1][0] += dp[i][j], dp[i+1][0] %= MOD;
        }
    }
    long long res = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= k; j++) cout << dp[i][j] <<" ";
    //         cout << endl;
    // }
    for (int i = 1; i <= n; i++) res += dp[i][k], res %= MOD;
    cout << res;
}
struct MATRIX
{
    int c[13][13];
};
MATRIX operator *(const MATRIX &a, const MATRIX &b)
{
    MATRIX res;
    for (int i = 0; i <= k+1; i++)
        for (int j = 0; j <= k+1; j++)
        {
            res.c[i][j] = 0;
            for (int e = 0; e <= k+1; e++)
            {
                res.c[i][j] = res.c[i][j] + 1ll*a.c[i][e]*1ll*b.c[e][j]%MOD;
                if (res.c[i][j] >= MOD) res.c[i][j] -= MOD;
            }
        }
    return res;
}
MATRIX power(MATRIX a, long long w)
{
    if(w == 1) return a;
    MATRIX aa = power(a, w/2);
    if (w%2) return aa*aa*a; else return aa*aa;
}
vector<pair<long long, int> > ldk;
void sub2()
{
    MATRIX A, B, C, res;
    sort(ldk.begin(), ldk.end());
    for (int i = 0; i <= k+1; i++)
        for (int j = 0; j <= k+1; j++) 
            A.c[i][j] = B.c[i][j] = C.c[i][j] = res.c[i][j] = 0;
    for (int i = 0; i < k; i++) 
    {
        A.c[i][0] = C.c[i][0] = 1;
    }
    for (int i = 1; i <= k+1; i++) A.c[i-1][i] = B.c[i-1][i] = 1;
    A.c[k+1][k+1] = B.c[k+1][k+1] =  C.c[k+1][k+1] = 1;
    A.c[k][k] = 2; B.c[k][k] = 1; C.c[k][k] = 1; C.c[k][k+1] = 1;
    // for (int i = 0; i <= k + 1; i ++)
    // {
    //     cout << endl;
    //     for (int j = 0; j <= k + 1; j++) cout << A.c[i][j] <<" ";
    // }
    // cout << endl;
    // for (int i = 0; i <= k + 1; i ++)
    // {
    //     cout << endl;
    //     for (int j = 0; j <= k + 1; j++) cout << B.c[i][j] <<" ";
    // }
    // cout << endl;
    // for (int i = 0; i <= k + 1; i ++)
    // {
    //     cout << endl;
    //     for (int j = 0; j <= k + 1; j++) cout << C.c[i][j] <<" ";
    // }
    // cout << endl;
    res.c[0][0] = 1;
    // for (int i = 0; i <= k + 1; i ++)
    // {
    //     cout << endl;
    //     for (int j = 0; j <= k + 1; j++) cout << res.c[i][j] <<" ";
    // }
    long long l = 0;
    for (auto v : ldk)
    {
        //cout << v.fi << endl;
        if (v.fi - l - 1> 0) 
        {
            res = res*power(A, v.fi - l - 1);
        }
        if (v.se == 0) res = res*C; else res = res*B;
        l = v.fi;
    }
    if (n - l>0) res = res*power(A, n-l);
    // // res = res * A*A*C*A*A*B*A*C*A*A;
    // cout << endl;
    // //res.c[0][0] = 1;
    // for (int i = 0; i <= k + 1; i ++)
    // {
    //     cout << endl;
    //     for (int j = 0; j <= k + 1; j++) cout << res.c[i][j] <<" ";
    // }
    //cout << endl;
    cout << (res.c[0][k+1] + res.c[0][k])%MOD;
}   
void solve()
{
    
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        long long val;
        cin >> val;
        if (n <= 1000)
        {
            if (val > 0) s[val] = -1; else s[-val] = 1;
        }
        else
        {
            if (val > 0) ldk.pb({val, 0}); else ldk.pb({-val, 1});
        }
    }
    if (n <= 1000) sub1(); else sub2();
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
    //cin >> testcase;
    while(testcase--)
        solve();
}
