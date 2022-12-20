#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
int main()
{
    freopen("SEAWEED.INP","r",stdin);
    freopen("SEAWEED.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k; long long ans=2,t=1;
    cin >> n >> k;
    if (k==1)  cout << 2*n;
    else
    {
        for (int i = 2; i<= k; i++)
            {
                t=(ans+t)%MOD;
                ans =(ans+t)%MOD;
            }
        cout << (long long )ans*n%MOD;
    }
}