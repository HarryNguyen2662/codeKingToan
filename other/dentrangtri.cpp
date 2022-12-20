#include<bits/stdc++.h>
using namespace std;
string a[16];
int dp[50000][15],cost[16][16];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int i,j,m,n,e,t,z;
	cin>>n>>m;
	for (i=1;i<=m;i++) cin>>a[i];
	for (i=1;i<m;i++)
	 for (j=i+1;j<=m;j++)
	  {
	  	 int sl=0;
	    for (e=0;e<n;e++) if (a[i][e]!=a[j][e]) sl++;
	    cost[i][j]=cost[j][i]=sl;
      }
       for (i=1;i<1<<m;i++)
       for (e=0;e<=m;e++) dp[i][e]=1e9; int kq=1e9; 
       bitset<15> s,ss;
      for (i=1;i<1<<m;i++)
      {
      	s=i;
         for (e=0;e<m;e++)
           if (s[e]==1)
           {
           	z=i^(1<<e);
           	 ss=z;
           	 if (z==0)
           	 {
           	 	int sl=0;
	                 for (int q=0;q<n;q++) if (a[m-e][q]=='1') sl++;
           	 	dp[i][m-e]=sl;
				}
           	 for (t=0;t<m;t++)
           	  if (ss[t]==1)
           	  {
           	  	dp[i][m-e]=min(dp[i][m-e],dp[z][m-t]+cost[m-e][m-t]);
				 }
				 if (i+1==(1<<m)) kq=min(kq,dp[i][m-e]);
		   }
	  }
	  cout<<kq;
}
