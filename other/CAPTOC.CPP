#include<bits/stdc++.h>
using namespace std;
long long dp[105][105],a[105][105];
int main()
{
    freopen("CAPTOC.INP","r",stdin);
    freopen("CAPTOC.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    long long ans = 0;
    cin >> n >> x;
    for  (int i = 1;i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
            cin >> a[i][j];    
    }
    for (int i = 1; i<= n; i++)
        for (int j = 0; j<=x; j++)
            for (int e = 0; e<=j; e++)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][e]+a[i][j-e]);
                    ans = max(ans,dp[i][j]);
                }
    cout << ans;
}