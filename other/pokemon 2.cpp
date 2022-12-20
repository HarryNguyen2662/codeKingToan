#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
double dp[140000][18];
struct ldk
{
	long long f;
	long long s;
	int cs;
};
vector<ldk> ds[18];
int main()
{
	int n,m,i,t,x,y,a,j; double kq=1e12;
	cin>>n>>m;
	for (i=1;i<n;i++) 
	{
		cin>>x>>y>>t;
		 ds[t].push_back({x,y,i});
	}
      for (i=1;i<1<<m;i++)
       for (j=0;j<=n;j++) dp[i][j]=1e12;
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
	                    dp[i][v.cs]=(double)sqrt((v.f)*(v.f)+(v.s)*(v.s));
   		              }
				}
				for (int k=0;k<m;k++)
				 if (ss[k]==1)
				 {
				 	for (auto u:ds[m-j])
				 	for (auto v:ds[m-k]) 
				 	{
				 	 dp[i][u.cs]=min(dp[a][v.cs]+(double)sqrt((v.f-u.f)*(v.f-u.f)+(v.s-u.s)*(v.s-u.s)),dp[i][u.cs]);
				 	 if (i+1==1<<m) kq=min(kq,dp[i][u.cs]);
			        }
				 }
			}
	   }
	   cout<<kq;
}
