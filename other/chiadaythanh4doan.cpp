#include<bits/stdc++.h>
using namespace std;
long long max2[100002],max1[100002],a[100002];
int main()
{
	 ios_base::sync_with_stdio(0);
	 cin.tie(0); cout.tie(0);
     int n,i,j;
	 cin>>n;
	 long long sum=0,maxx=0; 
	 for (i=1;i<=n;i++) 
	 {
	 	cin>>a[i]; sum+=a[i];
	 	max1[i]=2*maxx-sum;
	 	maxx=max(maxx,sum);
     }
     sum=0; maxx=0; long long kq=-1e18;
     for (i=n;i;i--)
     {
     	sum+=a[i];
        	max2[i]=sum-2*maxx;
     	maxx=min(maxx,sum);
	 }
	  for (i=1;i<=n;i++)
	   kq=max(kq,max1[i]+max2[i+1]);
	  cout<<kq;
}
