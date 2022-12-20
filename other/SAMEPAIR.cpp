#include<bits/stdc++.h>
using namespace std;
int dem[1000001],kt[1000001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long kq=0,k; int i,l,r,j;
	cin>>l>>r;
	 for (i=2;i<=r;i++) kt[i]=1;
	 for (i=2;i<=r;i++)
     if (kt[i]==1)
    {
      for (j=i;j<=r;j+=i) kt[j]=kt[j]*i;
      }
      for (i=l;i<=r;i++) dem[kt[i]]++;
      for (i=2;i<=1e6;i++)
      {
      	k=dem[i];
		kq=kq+k*(k-1)/2;
	  }
	  cout<<kq;
}
