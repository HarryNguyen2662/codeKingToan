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
long long dp[100005][105][2];
int a[100005];
void solve()
{   
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) dp[i][j][0] = dp[i][j][1] = -oo15;
    dp[0][0][1] = 0;
    for (int i = 0; i < n; i++)
    for (int j = 0; j <= k; j++)
    for (int e = 0; e < 2; e++)
    if (dp[i][j][e] > -oo15)
    {
        dp[i+1][j][e] = max(dp[i+1][j][e], dp[i][j][e]);
        if (e == 0) dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][e] + a[i+1]);
        if (e == 1) dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][e] - a[i+1]);
    }
    long long res = -oo15;
    for (int i = 1; i <= k; i++) res = max(res, dp[n][i][1]);
    cout << res;    
}
int main()
{   
    freopen("max.inp","r",stdin); freopen("max.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
