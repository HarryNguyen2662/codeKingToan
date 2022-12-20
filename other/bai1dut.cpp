#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
int dp[1050][1050];
char s[1050][1050];
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
    int n,m;
    cin >> n >> m;
    for (int i = 1; i<= n; i++)
        for (int j = 1;j <= m; j++)
            cin >> s[i][j];
    dp[0][1] = 1;
    for (int i = 1; i<=n ;i ++)
        for (int j = 1;j <= m; j ++)
            if (s[i][j]!='#') dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
    cout << dp[n][m];
}