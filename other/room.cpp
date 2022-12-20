#include<bits/stdc++.h>
using namespace std;
#define r first
#define l second
pair<int,int>a[10005];
int dp[10005];
int main()
{
    freopen("yeunhi.txt","r",stdin);
   // ios_base::sync_with_stdio(0);
   // cin.tie(0); cout.tie(0);
    int n,ans=0,ll,rr,mid;
    cin >>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].l>>a[i].r;
    }
    sort(a+1,a+n+1);
    for (int i= 1;i <= n; i++)
    {
        ll=1; rr=i-1;
        while(ll<=rr)
        {
            mid=(ll+rr)/2;
            if (a[mid].r<=a[i].l) ll=mid+1; else rr=mid-1; 
        }
        dp[i]=max(dp[i-1],dp[rr]+a[i].r-a[i].l);
        ans=max(dp[i],ans);
    }
    cout<<ans;
}