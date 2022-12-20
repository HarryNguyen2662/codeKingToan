#include<bits/stdc++.h>
using namespace std;
long long dp[10001][10001];
long long a[10001],b[10001];
int main()
{
    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
    long long ans=1e18; int n;
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i]; b[i]=a[i];
    }
    sort(b+1,b+n+1);
    dp[1][0]=1e18;
    for (int i = 1; i<= n; i++)
    {
        dp[1][i]=min(dp[1][i-1],abs(a[1]-b[i]));
    }
    for (int i = 2; i <=n; i++)
    {
        dp[i][0]=1e18;
        for (int j = 1; j <= n; j++)
            dp[i][j] = min(dp[i][j-1], dp[i-1][j] + abs(a[i]-b[j]));
    }
    for (int i = 1; i<=n; i++) ans = min(ans, dp[n][i]);
    cout <<ans;   
}