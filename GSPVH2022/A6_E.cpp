#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353; 
const long long MODo = 1e5;
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;
vector<int> ldk;
bool kt[1000005];
long long fact[1000005], ifact[1000005];
long long MOD3;
int testcase;
long long power(long long a, long long b)
{
    if(b == 0) return 1;
    long long y = power(a, b/2);
    if (b%2) return y*y%MOD3*a%MOD3; else return y*y%MOD3;
}  
long long C1(long long k, long long n)
{
    long long res = 1;
    for (auto v : ldk)
    {
        long long chia = v;
        int mu = 0;
        while (true)
        {
            mu += n/chia - k/chia -(n-k)/chia;
            if (chia > n/v) break;
            chia = chia*1ll*v;
        }
        res = res*power(v, mu)%MOD3;
    }
    return res;
} 
long long C(int k, int n)
{
    return fact[n]*ifact[k]%MOD1*ifact[n-k]%MOD1;
}
long long C2(int k, int n)
{
    long long res = ifact[k];
    for (int i = 1; i <= k; i++) res = (res * 1ll*(n-i+1))%MOD1;
    return res;
}
void solve1()
{
    for (int i =2 ; 1ll*i*i <= 1e6+3; i++)
        if (kt[i] == false)
            for (int j = i*i; j <= 1e6+3; j += i) kt[j] = true;
    for (int i = 2; i <= 1e6 +1; i++) if (kt[i] ==false) ldk.pb(i);
    while(testcase--)
    {
        long long n, k, m;
        cin >> n >>m >> k;
        cout << C1(k,n-1)*m%MOD3*power(m-1, k)%MOD3 <<"\n";
    }
}
void solve()
{
    fact[0] = 1;
    for (int i = 1; i <= 1e6+1; i++) fact[i] =(fact[i-1]*1ll*i)%MOD1;
    ifact[1000001] = power(fact[1000001], MOD1-2); 
    for (int i = 1e6; i>=0 ;i --) ifact[i]= (ifact[i+1]*1ll*(i+1))%MOD1;
    while(testcase--)
    {
        int n, k, m;
        cin >> n >> m >> k;
        if (n <= 1e6)
        cout << C(k, n-1)*m%MOD1*power(m-1, k)%MOD1 <<"\n";
        else
        cout << C2(k, n-1)*m%MOD1*power(m-1, k)%MOD1 <<"\n";
    }
}
int main()
{   
     #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("flowers.inp","r",stdin); freopen("flowers.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> testcase; cin >> MOD3;
    //solve1();
    if (MOD3 != MOD1) solve1();
    else solve();
}