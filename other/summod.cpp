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
long long calsum(long long l, long long r)
{
    long long sum = (l + r)%MOD;
    long long dai = (r - l + 1)%MOD;
    return sum*dai%MOD*nMOD%MOD;
}
long long cal(long long dai, long long val)
{
    dai %= MOD; val %= MOD;
    return dai*val%MOD;
}
void solve()
{   
    long long a, b, c;
    cin >> a >> b >> c;
    a--;
    long long r = b, r1 = a;
    long long res = 0, res1 = 0;
    for (int i = 2; 1ll*i*i <= c; i++)
    {
        long long l = c/i + 1;
        if (i <= a) res1 = (res1 + c%i)%MOD;
        if (i <= b) res = (res + c%i)%MOD;
        if (l <= r)
        {
            res = res + cal(r - l + 1, c) - 1ll*(i-1)*calsum(l, r)%MOD;
            res %= MOD;  res += MOD; res %= MOD; 
            r = l - 1;
        }
        if (l <= r1)
        {
            res1 = res1 + cal(r1 - l + 1, c) - 1ll*(i-1)*calsum(l, r1)%MOD;
            res1 %= MOD; res1 += MOD; res1 %= MOD;
            r1 = l - 1;
        }
    }
    long long  l = sqrt(c) + 1 ;
    //cout << l << endl;
    if (l <= r)
    {
        res = res + cal(r - l + 1, c) - 1ll*(l-1)*calsum(l, r)%MOD;
        res %= MOD;  res += MOD; res %= MOD; 
    }
    if (l <= r1)
    {
        res1 = res1 + cal(r1 - l + 1, c) - 1ll*(l-1)*calsum(l, r1)%MOD;
        res1 %= MOD; res1 += MOD; res1 %= MOD;
    }
    cout << (res - res1 + MOD)%MOD;
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
\