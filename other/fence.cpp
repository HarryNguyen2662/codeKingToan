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
int n, k;
int x[100005];
bool check(long long val)
{
    long long dem = 0;
    for (int i = 2; i <= n; i++)
    {
        int y = (x[i] - x[i - 1] - 1) / val;
        //if (val == 3) cout << y << endl;
        if (y > 0) dem += y;
    }
    //if (val == 3) cout << dem << endl;
    return dem <= k;
}
void solve()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    sort(x + 1, x + 1 + n);
    long long l = 1, r = 2*oo;
    while (l <= r)
    {
        long long mid = (l + r)/2;
        if (check(mid)) r = mid - 1; else l = mid + 1;
    }
    cout << l;
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