#include <bits/stdc++.h>
using namespace std;
int n, S,a[1005];
void solve()
{
    long long dp[n+1][S+1];
    memset(dp,0,sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= n ;i ++)
    {
        dp[i][0] = 1;
        for (int s = 1 ; s <= S; s++)
            if (s>=a[i]) dp[i][s] = dp[i-1][s] + dp[i-1][s-a[i]];
            else dp[i][s] = dp[i-1][s];
    }
    for (int i = S; i>=1; i--)
    if (dp[n][i])
    {
        cout << i << endl;
        cout << dp[n][i];
        return;
    }
    cout << 0; 
    return;
}
int main() 
{
    freopen("lololoin.txt","r",stdin);
    cin >> n >> S;
    for (int i= 1; i <= n; i++) cin >> a[i];
    solve();
    return 0;
}
    