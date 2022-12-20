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
long long a[300005];
void solve()
{
    int n, p, k;
    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        a[i] = a[i]*a[i]%p*a[i]%p*a[i]%p - 1ll*k*a[i]%p;
        a[i] %= p; a[i] += p; a[i] %= p;
        //cout << a[i] << endl;
    }
    sort(a + 1, a + 1 + n);
    long long res = 0;
    long long sl = 1;
    for (int i = 2; i <= n; i++)
    if (a[i] != a[i-1])
    {
        //cout << sl << endl;
        res = res + sl*(sl-1)/2;
        sl = 1;
    }
    else sl++;
    res = res + sl*(sl-1)/2;
    cout << res;
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