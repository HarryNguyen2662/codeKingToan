#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const long long MOD = 1e9 + 7;
long long dp[3000000];
int a[25][25];
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    dp[0] = 1;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int hag = __builtin_popcount(mask);
        for (int cot = 0; cot < n; cot ++)
            if (!(mask & (1 << cot)) && (a[hag][cot]))
            {
                int newmask = mask ^ (1 << cot);
                dp[newmask] = (dp[newmask] + dp[mask])%MOD;
             }
    }
    cout << dp[(1 << n) - 1];
}