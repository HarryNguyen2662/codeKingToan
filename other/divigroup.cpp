#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
long long dp[100005],cal[100005],a[20][20];
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
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    for (int i =0 ; i < (1 << n); i++) dp[i] = -1e15;
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            if (i&(1 << j))
                for (int e = j+1; e < n; e++)
                    if (i&(1 << e))
                        cal[i] += a[j][e];
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int submask = (((1 << n) -1)^mask);
      //  cout << dp[mask]<<endl;
        for (int sub = submask; sub; sub= (sub-1)&submask)
            {
                int newmask = (mask^sub); //cout << cal[sub]<<endl;
                dp[newmask] = max(dp[newmask],dp[mask]+cal[sub]); 
            }
    }
    cout << dp[(1 << n)-1];
}