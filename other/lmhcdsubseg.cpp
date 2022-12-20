#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 19
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 1e9; 
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 9223372036854775807;
int GCD[1000005][20], lg[1000005], n;
int getgcd(int l, int r)
{
    int k = lg[r - l  +1];
    return __gcd(GCD[l][k], GCD[r-mask(k)+1][k]);
}
bool check(int x)
{
    for (int i = 1; i <= n-x+1; i++)
        if (getgcd(i, i + x-1) != 1) return true;
    return false;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> GCD[i][0]; if (GCD[i][0] < 0) GCD[i][0] = -GCD[i][0];
    }
    for (int i = 1; i <= log; i++)
        for (int j = 1; j <= n - mask(i) + 1; j++)
            GCD[j][i] = __gcd(GCD[j][i-1], GCD[j+mask(i-1)][i-1]);
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r)/2;
        if (check(mid)) l = mid + 1; else r = mid - 1;
    }
    cout << r << "\n";
}
int main()
{   
   
   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    for (int i = 1; i <= 1000002; i++)
    {
        while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
    }
    int testcase = 1;
    cin >> testcase;    
    while (testcase--)
        solve();
}
