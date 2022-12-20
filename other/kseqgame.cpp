#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 998244353;
const int MAXN = 1e6;
const int oo = 1e9;
long long dp[1005][1005][6];
int x[1050], y[1050];
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
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin>> x[i];
    for (int i = 1; i <= n; i++)
        cin >> y[i];
    for(int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int sl = 1; sl <=k; sl++) dp[i][j][sl] = -oo;
    dp[0][0][0] = 0;
    for (int sl = 1; sl <= k; sl++)
        for (int i = sl; i <= n; i++)
        for (int j = sl; j<= n; j++)
            dp[i][j][sl] = max({dp[i-1][j-1][sl-1] + 1ll*x[i]*y[j], dp[i-1][j][sl], dp[i][j-1][sl]});
    cout << dp[n][n][k];
}