#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const long long MOD = 1e9 + 7;
long long dp[320][100005];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("yeunhi.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n;
    m = sqrt(n);
    dp[0][0] = 1;
    for (int i = 1; i<= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if(i-j>=0&&i-2*j+1>=0)
                dp[j][i] = (dp[j][i-j] + dp[j-1][i-2*j+1])%MOD;
    }
    long long ans = 0;
    for (int i = 1; i<=m; i++) ans= (ans+dp[i][n])%MOD;
    cout << ans;
}