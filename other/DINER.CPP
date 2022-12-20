#include<bits/stdc++.h>
using namespace std;
int n,m,x[100],y[100],sm[100],pm[100],sv[100],pv[100];
bool check(int a)
{
	if (a==0) return true;
	int cost=0,cost1,u,z,t; 
	for (int i=0;i<n;i++)
	{
	  u=x[i]*a-y[i];  t=(u/sm[i])+(u%sm[i]!=0);
	  cost1=t*pm[i];
	  for (int j=0;j<=t;j++)
	  {
	  	z=u-j*sm[i]; z=(z/sv[i])+(z%sv[i]!=0); 
		  cost1=min(cost1,z*pv[i]+j*pm[i]);
	  }
	  cost+=cost1; if (cost>m) return false;
	}
	return true;
}
int main()
{
	freopen("DINER.INP","r",stdin);
	freopen("DINER.OUT","w",stdout);
	int l,r,mid,i;
	cin>>n>>m;
	for (i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>sm[i]>>pm[i]>>sv[i]>>pv[i];
	}
	l=0; r=1e5;
	while (l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))l=mid+1; else r=mid-1;
	}
	cout<<r;
}