#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e6 + 3;
const int MAXN = 1e6;
const int oo = 1e9;
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int n,m;
    cin >> n >> m;
    vector<vector<long long int>> cost(n + 2, vector<long long int>(n + 2));
    vector<long long int> lich(n + 2);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
        }
    }
    for (int i = 1; i <= m; i++) cin >> lich[i];
    vector<vector<vector<long long int>>> dp(m + 2, vector<vector<long long int>>(m + 2, vector<long long int>(m + 2, 1e9)));
    dp[1][2][3] = dp[1][3][2] = dp[2][1][3] = dp[2][3][1] = dp[3][2][1] = dp[3][1][2] = 0;
    for (int j = 1; j <= m; i++)
    {
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                for (int c = 1; c <= n; c++)
                {
                    dp[a][b][lich[j]] = min(dp[a][b][lich[j]], dp[a][b][c] + cost[c][lich[j]]);
                    dp[a][lich[j]][c] = 
                    dp[lich[j]][b][c] = 
                }
            }
        }
    }
    return 0;
}