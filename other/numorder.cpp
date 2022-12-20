#include<bits/stdc++.h>
using namespace std;
long long l,r,n,m,k,mid=0,ans;
long long solve(long long a,long long i)
{
    long long l=1,r=m,x,res=0;
    while(l<=r)
    {
        x=(l+r)/2;
        if(x*x+i*i<=a)
        {
            res=x;
            l=x+1;
        }
        else r=x-1;
    }
    return res;
}
bool check(long long x)
{
    long long ij=0;
    for(long long i=1;i<=n;i++) ij=ij+solve(x,i);
    return ij>=k;
}
int main()
{
    freopen("yeunhi.txt", "r", stdin);
    cin>>m>>n>>k;
    if(m<n) swap(m,n);
    r=1e18; l=1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }
    cout<<ans;
}