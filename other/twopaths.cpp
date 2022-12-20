#include <bits/stdc++.h>
using namespace std;
long long dp[405][205][205],a[205][205];
int main ()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ,m ;
    cin >> n >> m;
    for (int i = 1; i<= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    for (int i = 1; i<= m+n-1; i++)
        for (int j = 0; j<= max(n,m) ; j++)
            for(int k = 0; k<= max(n,m); k++) dp[i][j][k] = -1e18;
    dp[2][1][2] = a[1][2] + a[2][1];
    for (int i = 3; i < m+n-1; i++)
        {
            for (int j =max(i+1-m,1); j < min(i,n) ; j++)
                 for (int k = j + 1; k <= min(i,n); k++)
                       dp[i][j][k] = max({dp[i-1][j][k], dp[i-1][j-1][k-1],dp[i-1][j-1][k], dp[i-1][j][k-1]}) + a[j][i+1-j] + a[k][i+1-k];
        }
    cout <<dp[m+n-2][n-1][n];
}