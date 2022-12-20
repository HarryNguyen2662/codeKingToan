#include<bits/stdc++.h>
using namespace std;
const long long MOD = 20071008;
long long dp[1005][1005]; 
int main()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    string s,st;
    //cin >> t;
   // while(t--)
    //{
        cin >> s;
        cin >> st;
        int n = s.size(), m =st.size();
        memset(dp, 0 ,sizeof dp);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j<= m; j++)
                {
                    if (s[i-1]==st[j-1])
                    {
                        dp[i][j] =  (dp[i - 1][j ] + 1+dp[i][j-1]) % MOD;
                    }
                    else
                    {
                        dp[i][j] =(dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+MOD)%MOD;
                    }
                    //cout << dp[i][j]<<endl;
                }
        cout << dp[n][m] << endl;
    //}
}