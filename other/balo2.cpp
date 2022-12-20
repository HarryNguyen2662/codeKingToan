#include<bits/stdc++.h>
using namespace std;
long long dp[100005],w[105];
int v[105];
void solve()
{
    int n,kk,i,j,ww;
    cin >> n >>ww; 
    kk = 1e5;
    for (int i =1 ; i<= n;i++)
    {
        cin >> w[i] >> v[i];
       // cout << w[i] <<" "<< v[i] << endl;
    }
     for (int i  = 1; i <=kk; i++) dp[i] = 1e18;
    
    for (int i = 1; i<= n ;i++)
        for (int j = kk; j >= v[i]; j--)
             if (dp[j-v[i]]!=1e18)
             {
                 dp[j] = min(dp[j], dp[j-v[i]]+w[i]);
             }
    for (int i = kk; i>=0; i--) 
        if (dp[i]<=ww)
        {
            cout << i; break;
        }
}
int main()
{

    freopen("lololoin.txt","r",stdin);
    solve();
}