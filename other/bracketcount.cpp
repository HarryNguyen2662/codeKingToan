#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1 << (i))
#define setp(x) setprecision(x)
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 1e5;
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo18 = 1e18;
const long long oo15= 1e15;
char s[205];
bool kt = false;
long long dp[205][205];
long long add(long long x, long long y)
{
    x += y;
    if (x >= MODo) kt =true;
    return x%MODo;
}
long long nhan(long long x, long long y)
{
    x *= y;
    if (x >= MODo) kt = true;
    return x%MODo;
}
bool check(char x, char y)
{
    if (x == ']')
        return (y == '['||y =='?');
    if (x == '}')
        return (y == '{'||y =='?');
    if (x == ')')
        return (y == '('||y =='?');
    if (x == '?')
    {
        if (y == '[' || y == '(' || y == '{'||y =='?') return true;
    }
    return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 2; i <= n; i++)
    for(int j = i-1; j; j--)
    {   
        //cout <<"lo "<<j <<" "<<i << endl;
        if (i - j + 1 == 2 && check(s[i], s[j]))
        {
            dp[j][i] = 1 + 2*(s[j] == s[i]);
           // cout << dp[j][i]<< endl;
            continue;
        }
        int val = 1 + 2*(s[i] == s[j]);
        if (check(s[i], s[j])) dp[j][i] = nhan(dp[j+1][i-1], val);
        if (check(s[i], s[i-1])) dp[j][i] = add(dp[j][i],nhan(dp[j][i-2] ,(1 + 2*(s[i] == s[i-1]))));
        for(int e = j + 1; e < i-1; e++)
        if (check(s[i], s[e]))
        {
            val = 1 + 2*(s[i] == s[e]);
            dp[j][i] = add(dp[j][i],nhan(dp[e+1][i-1],nhan(dp[j][e-1], val)))%MODo;
        }
 
    } 
    if (!kt) cout << dp[1][n];
    else
    {
        int w = 10000;
        for (int i = 1; i <= 5; i++)
        {
            cout << dp[1][n]/w;
            dp[1][n] %= w;
            w /= 10; 
        }            
    }
}

