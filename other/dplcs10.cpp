#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t ;
    string s,st;
    cin >> t;
    while (t--)
    {
        cin >> s;
        cin >> st;
        int n = s.size(), m = st.size();
        for (int i = 0; i<= n; i++)
            for (int j = 0; j<=m;j ++) dp[i][j] = 1e9;
        for (int i = 1; i <= m; i++)
            if (s[0]==st[i-1]) dp[1][i] =i-1;
            else dp[1][i] = min(dp[1][i-1]+1,i);
        for (int i = 1; i <= n; i++)
            if (st[0]==s[i-1]) dp[i][1] =i-1;
            else dp[i][1] = min(dp[i-1][1]+1,i);
        for (int i = 2; i<= n;i++)
            for (int j = 2;j <=m; j++)
                if (s[i-1]==st[j-1]) dp[i][j] = min({dp[i-1][j-1],dp[i-1][j]+1,dp[i][j-1]+1});
                else dp[i][j] = min({dp[i-1][j-1]+1, dp[i-1][j]+1,dp[i][j-1]+1});
        cout << dp[n][m]<<endl;
    }
}