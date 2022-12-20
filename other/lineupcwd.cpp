#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define mask(i) (1 << (i))
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6+5;
const int oo = 1e9;
long long dt[2005], dp[2005][2005];
long long power(long long x, long long y)
{
  if (y == 0) return 1;
  long long e = power(x,y/2);
  if(y%2) return e*e%MOD*x%MOD; else return e*e%MOD;
}
long long c(int k, int n)
{
  if (k > n) return 0;
  if (k == 0||k == n) return 1;
  return dt[n]*power(dt[k]*dt[n-k]%MOD, MOD-2)%MOD;
}
int main()
{
     #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    // freopen("pupil.inp","r",stdin);
    // freopen("pupil.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x,y,m;
    cin >> n >> x >> y;
    dt[0] = 1;
   // for (long long i = 1; i <= n; i++) dt[i] = dt[i-1]*i%MOD;
    m = max(x,y);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= min(i,m); j++)
       dp[i][j] = (1ll*(i-1)*dp[i-1][j]%MOD + dp[i-1][j-1])%MOD;
     dt[i] =1ll*i*dt[i-1]%MOD;
    // cout<< dt[i] << endl;
    }
   // cout << c(2,4)<<endl;
    long long ans = 0;
    for (int i = x; i <= n-y + 1; i++)
      ans = (ans + dp[i-1][x-1]*dp[n-i][y-1]%MOD*c(i-1,n-1)%MOD)%MOD;
    cout << ans;
}