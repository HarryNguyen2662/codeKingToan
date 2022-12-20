#include<bits/stdc++.h>
using namespace std;
long long dp[1005][10105],sum[1005][10105];
int main()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n , m;
    cin >> n >> m;
    int mod = 1e9+7;
    //for (int i = m; i<= m +n; i++ ) sum[n][i] = 1;
    dp[0][0]=1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            dp[i%2][j]=j?((dp[(i+1)%2][j]-(j>=i?dp[(i+1)%2][j-i]:0)+mod)%mod+dp[i%2][j-1])%mod:1;
        }
    cout << dp[n%2][m];
}
