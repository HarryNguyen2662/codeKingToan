#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1 << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int lim = 125250;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
long long dp[505][2*lim+5];
void solve()
{
    dp[0][lim] = true;
    for (int i = 0; i < 500;i++)
    for (int j = -lim; j <= lim; j++)
    if (dp[i][j + lim] == true)
    {
        if (j + i + 1 <= lim) dp[i+1][j+i+1+lim] = true;
        if (j - i - 1 >= -lim) dp[i+1][j-i-1+lim] = true;
    }
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int n, sum;
        cin >> n >> sum;
        cout << dp[n][sum+lim] <<"\n";
    }
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
    solve();
}