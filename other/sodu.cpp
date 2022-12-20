#include<iostream>
using namespace std;
int q[1000005],qq[1000005],dd[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,i,x,j;
	  scanf("%d",&n);  scanf("%d",&m);
	for (i=0;i<n;i++)
	{
		scanf("%d",&x);
		 if (dd[x]==0)
		 {
		  dd[x]=1; qq[1000000]=max(qq[1000000],1000000%x);
		  for(j=x;j<=1e6;j+=x) 
		 {
		  q[j]=-1; qq[j-1]=max(qq[j-1],x-1);
           }
         }
	}
	 for (i=1;i<=1e6;i++)
	 {
	   if (q[i]==-1) q[i]=0; 
	    else q[i]=q[i-1]+1;
	    qq[1000000-i+1]=max(qq[1000000-i+1],qq[1000000-i+2]-1);
	 }
	 for(i=0;i<m;i++)
	 {
	 		scanf("%d",&x);
	 	printf("%d %d \n", q[x], qq[x]);
	 }
}
