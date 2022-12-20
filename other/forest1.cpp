#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e6 + 3;
const int MAXN = 1e6;
const int oo = 1e9;
long long dp[1100][1100];
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
    int n , m , k; 
    long long x;    
    cin >> n >> m >> k;
    for (int i = 1; i<= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            dp[i][j] = dp[i-1][j]+dp[i][j-1] - dp[i-1][j-1]+x;
        }
    long long ans = 0;
    for (int i = k; i <= n; i++)
        for (int j = k; j <= m; j++)
        {
            ans = max(ans, dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k]);
        }
    cout << ans;
}