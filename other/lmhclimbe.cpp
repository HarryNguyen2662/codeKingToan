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
const long long MODo = 123456789; 
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 9223372036854775807;
int a[100005], b[100005], cs[100005];
bool cmp(const int &x, const int &y)
{
    if (a[x] < b[x] && a[y] < b[y])
    {
        return a[x] < a[y];
    }
    else if (a[x] >= b[x] && a[y] >= b[y])
    {
        return b[x] > b[y];
    }
    else if (a[x] < b[x] && a[y] >= b[y]) return true;
    else if (a[x] >= b[x] && a[y] < b[y]) return false;
}
void solve()
{
    int n;
    long long res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        res += a[i];
    }
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cs[i] = i;
    sort(cs + 1, cs + 1 + n, cmp);
    long long tg = 0;
    tg = b[cs[1]];
    for (int i = 2; i <= n; i++) 
    {
        tg = b[cs[i]] + max(0ll, tg-a[cs[i]]);
        //cout << tg << endl;
    }
    cout << tg + res << "\n";
    for (int i = 1; i <= n; i++) cout << cs[i] << " ";
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //freopen("putnik.inp","r",stdin); freopen("putnik.out","w",stdout);
    #endif
   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;    
    while (testcase--)
        solve();
}
