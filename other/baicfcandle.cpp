#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
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
long long dp[5005][5005];
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int testcase;
    long long sum;
    dp[1][1] = 1;
    for (int i = 2; i <= 5000; i++)
        {
            if (i %2 == 0)
            {
                sum = dp[i-1][1];
                for (int j = 2; j<= i;  j++)
                {
                    dp[i][j] = sum;
                    sum=(sum+ dp[i-1][j])%MODo;
                }
            } 
            else 
            {
                sum = dp[i-1][min(5000-1,i-1)];
                for (int j = min(5000-1,i-1); j >= 1; j --)
                {
                    dp[i][j] = sum;
                    sum =(sum+ dp[i-1][j-1])%MODo;
                } 
            }  
        }
    cin >> testcase;
    while(testcase--)
    {
        int n;
        cin >> n;
        long long res = 0;
        for (int i = 1; i <= n; i++) 
            {
                res += dp[n][i];
                res %= MODo;
            }
        int re = res;
        int dem = 0;
        while(re) 
        {
            dem++; re /= 10;
        }
        for (int i = 1; i <= 9 - dem; i++) cout <<0;
        cout <<res << "\n";
    }
}