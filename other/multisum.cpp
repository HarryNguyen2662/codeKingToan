#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const long long MOD = 1e9 + 7;
long long dp[10005][105];
int a[10005], n, d;
long long solve(int i, int sum, int gh)
{
    if (i == n + 1) return (sum == 0);
    if (dp[i][sum]!=-1 && !gh) return dp[i][sum];
    int limit = (gh) ? a[i] : 9;
    long long ans = 0;
    for (int j = 0; j <= limit; j++)
    {
        int newgh = (a[i] == j) ? gh : 0;
        ans = (ans + solve(i + 1, (sum + j)%d, newgh))%MOD;
    }
    if (!gh) dp[i][sum] = ans;
    return ans;
}
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
    string s; 
    cin >> s;
    cin >> d;
    memset(dp, -1, sizeof dp);
    n = s.size() - 1;
    for (int i = 0; i <= n; i++)
    {
        a[i] = s[i]-48;
    }
    cout << (solve(0, 0 , 1) - 1 + MOD) % MOD;
}