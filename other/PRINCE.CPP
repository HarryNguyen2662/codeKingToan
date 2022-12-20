#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
long long dp[505][505],maxdp[505][505];
pair<int,int> a[505];
int main()
{
    freopen("PRINCE.INP","r",stdin);
    freopen("PRINCE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,l,r,mid; long long  ans=0;
    cin>>n;
    for (int i = 1; i<= n; i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    cin>>a[n+1].x; 
    for (int i = 0;i <= n; i++)
    {
        for (int j =i+1; j<= n+1; j++)
        {
            l=0; r=i-1;
            while(l<=r)
            {
                mid=(l+r)/2;
                if (a[i].x-a[mid].x>=a[j].x-a[i].x) l=mid+1; else r=mid-1; 
            }
            if (r!=-1)dp[i][j]=maxdp[r][i]+a[j].y;
            else if (i==0) dp[0][j]=a[j].y;
           if (i!=0) maxdp[i][j]=max(maxdp[i-1][j],dp[i][j]); else maxdp[0][j]=dp[0][j];
        }
        ans=max(ans,dp[i][n+1]);
    }
    cout<<ans;
}