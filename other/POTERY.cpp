#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,i,t,m;
	cin>>t;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for (i=1;i<=m;i++) cin>>b[i];
	long long l, r,mid, ans,kq,kq1,ans1,ans2;
    l=0; r=t;
    while(l<=r)
	{
		mid=(l+r)/2;
		kq=0; kq1=0;
		for (i=1;i<=n;i++) kq+=mid/a[i];
		for (i=1;i<=m;i++) kq1+=(t-mid)/b[i];
		if (kq<kq1) l=mid+1; else r=mid-1;
	}
		kq=0; kq1=0;
		for (i=1;i<=m;i++) kq+=(t-r)/b[i];
		for (i=1;i<=n;i++) kq1+=r/a[i];
		ans1=min(kq,kq1);
      if (r+1<=t)
      {
      	r++;
       kq=0; kq1=0;
		for (i=1;i<=m;i++) kq+=(t-r)/b[i];
		for (i=1;i<=n;i++) kq1+=r/a[i];
		ans2=min(kq,kq1);
	  }
	cout<<max(ans1,ans2);
}
