#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
long long f[1000005];
void khoitao()
{
    f[0] = 1;
    for (long long i = 1; i<= 1e6+3 ;i ++)
    {
        f[i] = f[i-1]*i%MOD;
    }
}
long long power(long long a, long long b)
{
    if (b==0) return 1;
    long long y = power(a,b/2);
    if (b%2==0) return y*y%MOD; else return y*y%MOD*a%MOD;
}
long long c(int b,int a)
{
    if  (b == 0 || b == a) return 1;
    return f[a]*power(f[b]*f[a-b]%MOD,MOD-2)%MOD;
}
void solve()
{
    long long n,m,x,y,u,v,ans = 0;
    cin >> n >>m;
    cin >> x >> y >> u >> v;    
    for (long long i = u; i <n;i ++)
    {
        long long w = c(i,i+y-2)*c(m-y,m-y+n-i-1)%MOD;
        ans = (ans +w)%MOD;
    }
 
    for (long long i =v; i < m; i++)
    {
        long long w = c(i,i+x-2)*c(n-x,n-x+m-i-1)%MOD;
        ans = (ans + w)%MOD;
    }
    cout << ans;
}
int main()
{
    freopen("lololoin.txt","r",stdin);
     khoitao();
     solve();
}