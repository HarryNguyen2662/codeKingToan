#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
long long dp[3005][3005];
int main ()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; long long sum;
     string s;
    cin >> n;
    cin >> s;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
        {
            if (s[i-2]=='<')
            {
                sum = dp[i-1][1];
                for (int j = 2; j<= i;  j++)
                {
                    dp[i][j] = sum;
                    sum=(sum+ dp[i-1][j])%MOD;
                   // cout << dp[i][j] <<" "<<i<<" "<<j << endl;
                }
            } 
            else 
            {
                sum = dp[i-1][min(n-1,i-1)];
                for (int j = min(n-1,i-1); j >= 1; j --)
                {
                    dp[i][j] = sum;
                    sum =(sum+ dp[i-1][j-1])%MOD;
                  //  cout << dp[i][j] <<" "<<i<<" "<<j << endl;
                } 
            }  
        }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans =(ans+ dp[n][i])%MOD;
    cout << ans;
}