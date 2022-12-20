#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
double cost[18][18],dp[140000][18];
vector<pair<long long,long long> > ds[18];
int main()
{
	int n,m,i,t,x,y,a,j; double kq=1e12;
	cin>>n>>m;
	for (i=1;i<n;i++) 
	{
		cin>>x>>y>>t;
		 ds[t].push_back({x,y});
	}
	for (i=1;i<m;i++)
	 for (j=i+1;j<=m;j++)
	 {
	 	 double z=1e12;
	  for (auto u:ds[i])
	   for (auto v:ds[j])
	    {
	          z=min(z,(double)sqrt((u.f-v.f)*(u.f-v.f)+(u.s-v.s)*(u.s-v.s)));
   		}
   		cout<<z<<endl;
   		cost[i][j]=cost[j][i]=z;
      }
      for (i=1;i<1<<m;i++)
       for (j=0;j<=m;j++) dp[i][j]=1e12;
      bitset<17> s,ss; 
      for (i=1;i<1<<m;i++)
       {
       	   s=i;
       	   for (j=0;j<m;j++)
       	    if (s[j]==1)
       	    {
       	    	a=i^(1<<j); 
       	    	ss=a;
       	    	if(a==0)
       	    	{
       	    		 double z=1e12;
       	    	    for (auto v:ds[m-j])
	                   {
	                       z=min(z,(double)sqrt((v.f)*(v.f)+(v.s)*(v.s)));
   		              }
   		              dp[i][m-j]=z;
				}
				for (int k=0;k<m;k++)
				 if (ss[k]==1)
				 {
				 	 dp[i][m-j]=min(dp[i][m-j],dp[a][m-k]+cost[m-j][m-k]);
				 }
				 if (i+1==(1<<m)) kq=min(kq,dp[i][m-j]);
			}
	   }
	   cout<<kq;
}
