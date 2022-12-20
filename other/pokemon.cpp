#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int m;
vector<pair<long long, long long > > ds[19];
double dequy(int t,long long x, long long y)
{
	double kq=10000000000.0;
     for (auto e:ds[t])
     {
     	if (t==m) 
     	{
     		kq=min(kq,(double)sqrt((e.f-x)*(e.f-x)+(e.s-y)*(e.s-y)));
		 }
		 else kq=min(kq,(double)sqrt((e.f-x)*(e.f-x)+(e.s-y)*(e.s-y))+dequy(t+1,e.f,e.s));
	 }
	 return kq;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,i,x,y,t; double kqq;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>x>>y>>t;
		ds[t].push_back({x,y});
	}
	kqq=0;
	   cout<<dequy(1,0,0);
}
