#include<bits/stdc++.h>
using namespace std;
int a[10001][5],dp[10001][17];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,kq,i,j,e,f;
	cin>>n;	
	for (i=1;i<=n;i++)
    	for(j=1;j<=4;j++)
            {
			    cin>>a[i][j]; }
              bitset<4> s;
	  for (i=1;i<1<<4;i++)
	   if ((i&(i/2))==0)  
	    {
	    	s=i;
		  for (j=0;j<4;j++)
	       if (s[j]==1) dp[1][i]+=a[1][j+1];
		}
	   for (i=2;i<=n;i++)
	      for (j=0;j<1<<4;j++)
	        {
		       if ((j&(j/2))==0)
		       {
			      s=j;
	           	int kk=0;
				for (e=0;e<4;e++) if (s[e]==1) kk+=a[i][e+1];
	         	 for (f=0;f<1<<4;f++)
	         	  if (((j&f)==0)&&((f&(f/2))==0))
					dp[i][j]=max(dp[i][j],dp[i-1][f]+kk); 	
	             if (i==n) kq=max(kq,dp[i][j]);  
	         } 
           }
           cout<<kq;
 } 
