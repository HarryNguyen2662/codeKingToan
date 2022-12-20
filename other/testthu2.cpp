#include<bits/stdc++.h>
#define maxn 300
using namespace std;
int dp[maxn][maxn][maxn];
int col[maxn][maxn], row[maxn][maxn], trace[maxn][maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i <= n;i++){
        col[0][i] = 0;
    }
    for (int i = 0; i <= m;i++){
        row[i][0] = 0;
    }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int x;
                cin >> x;
                col[i][j] = col[i - 1][j] + x;
                row[i][j] = row[i][j - 1] + x;
            }
        }
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= m;j++){
    //         col[i][j] = col[i][j-1] + col[i][j];
    //     }
    // }
    for (int i = 1; i <= n;i++){
        for (int j = i + 1;j<=m; j++)
        {
            dp[0][i][j] = 0;
            trace[0][i][j] = 0;
        }
    }
    for (int k = 1; k <= n;k++){
        for (int i = 1; i <= m;i++){
            for (int j = i + 1; j <= m;j++){
                if(dp[k-1][i][j]<col[k][j]+col[k][i]){
                    dp[k][i][j] = dp[k - 1][i][j];
                    trace[k][i][j] = trace[k - 1][i][j];
                }
                else{
                    dp[k][i][j] = col[k][j]+ col[k][i];
                    trace[k][i][j] = k;
                }
                cout << k << ' ' << i << ' ' << j << ' ' << trace[k][i][j] << ' ' << dp[k][i][j]<<'\n';
            }
        }
    }
    int maxres = -1e9;
    for (int i = 2; i <= n;i++){
        for (int j = 2; j <= m;j++){
            for (int k = j - 1; k >= 1;k--){
                // maxres = max(maxres,col[i][j]-col[i][k-1]-dp[i-2][k][j]);
                maxres = max(maxres, (row[i][j] - row[i][k - 1]) + (row[trace[i - 2][k][j]][j] - row[trace[i - 2][k][j]][k - 1]) + (col[i][j] - col[trace[i - 2][k][j]][j]) + (col[i][k] - col[trace[i - 2][k][j]][k]));
                // if (((row[i][j] - row[i][k - 1]) + (row[trace[i - 2][k][j]][j] - row[trace[i - 2][k][j]][k - 1]) + (col[i][j] - col[trace[i - 2][k][j]][j]) + (col[i][k] - col[trace[i - 2][k][j]][k]))>maxres){
                //     cout << trace[i - 2][k][j] << ' ' << k << ' ' << i << ' '<< j<<'\n';
                // }
            }
        }
    }
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= m;j++){
    //         cout << row[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << maxres;
    return 0;
}