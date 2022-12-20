#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);

   // ios_base::sync_with_stdio(0);
   // cin.tie(0); cout.tie(0);
    int n,l,r,mid; long long x,ans=0;
    cin>> n>>x;
    for (int i =1 ; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=n; i; i--)
    {
        r=i-1; l =1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if (a[i]+a[mid]<=x) l=mid+1; else r=mid-1;
        }
        if (r!=-1) ans=max(ans,a[i]+a[r]);
    }
    cout<<ans;
}