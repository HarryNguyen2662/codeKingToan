#include<bits/stdc++.h>
using namespace std;
int ds[1001];
struct kk
{
	double f;
	int s;
	int e;	
    bool operator < (kk other) {
	  if (other.f>f)
	 	return true;
	    return false;
}
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,i; double x,y,d; vector<kk> ldk;
	cin>>n>>d;
	for (i=1;i<=n;i++)
	{
		cin>>x>>y;
		if (y>d) {
			cout<<-1; return 0;
		}
		double e=sqrt(d*d-y*y);
		ldk.push_back({x-e,0,i}); 	ldk.push_back({x+e,1,i});
	}
	 sort(ldk.begin(),ldk.end());
	 int kq=0,dd=1;
	  for (auto k:ldk)
	  	if (k.s==0)
	  	{
	  		ds[k.e]=dd;
		  }
		  else 
		  {
		  	if (ds[k.e]==kq+1)
		  	{
		  		kq=dd; dd++;
			}
		  }
		  cout<<kq;
}
