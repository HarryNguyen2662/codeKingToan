#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
 int MAXN = 1e6;
const int oo = 1e9;
long long power(long long n)
{
    if (n == 0) return 1;
    long long y = power(n/2);
    if (n%2) return y*y%MOD*10%MOD; else return y*y%MOD;
}
long long g(long long x)
{
    long long v = x/9, u = x%9;
    if (v == 0) return (u+1)*u/2;
    long long k = power(v);
    long long kk = (k-1+MOD)%MOD*111111112%MOD;
    return ((36*kk%MOD + 9*((kk-v%MOD+MOD)%MOD)%MOD)%MOD + u*(u+1)/2*k%MOD + (u+1)*(k-1)%MOD)%MOD;  
}
long long solve(int q)
{
    long long res = 0;
    long long f0 = 0, f1= 1;
    while (q--)
    {
        long long f2 = f0+f1;
        res = (res + g(f2))%MOD;
        f0 = f1; f1= f2;
    }
    return res;
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission    
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);                                                                    
    int t; 
    cin >> t ;
    while (t--)
    {
        int q;
        cin >> q;
        q--;
        cout << solve(q)<<endl;
    }
}   