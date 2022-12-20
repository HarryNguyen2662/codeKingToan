#include<bits/stdc++.h>
using namespace std;
int dp[105][105],cost[105];
int main()
{
    freopen("TEA.INP","r",stdin);
    freopen("TEA.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= k ; i++)
        cin >> cost[i];
    for (int i = 0; i<=n; i++)
        for (int j = 0; j <= k; j++) dp[i][j] = 1e9;
    dp[0][0]=0;
    for (int i = 0; i< n; i++)
        for (int j = 0; j< k; j++)
            for (int e = 0; e <= k; e++)
              if (cost[e]!=-1&&j+e<=k)
                dp[i+1][j+e] = min(dp[i+1][e+j],dp[i][j]+cost[e]);
    if (dp[n][k]!=1e9) cout << dp[n][k]; else cout << -1;
}