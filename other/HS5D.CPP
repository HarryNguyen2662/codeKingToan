#include<bits/stdc++.h>
#define k long long
using namespace std;
int kt[1000001];
const k m=1e9+7;
k y;
k mu(k a,k b)
{
	if (b==0) return 1;
	k u=mu(a,b/2)%m;
	u=u*u%m;
	if (b%2!=0) u=u*a%m;
	return u;
}
k lkk(k a,k b)
{
	if (b==0)
	{
	y=0; return 1;
	}
	k t=lkk(b,a%b), t1=y;
	y=t-a/b*t1; return t1;
}
int main()
{
    k l,r,i,km,kq,kk,j,z,u; vector<long long> ldk;
    for (i=2;i*i<=1e6;i++)
      if  (!kt[i])
      {
      	 for (j=i*i;j<=1e6;j+=i) kt[j]=1;
	  }
	for (i=2;i<=1e6;i++)
	 if (!kt[i]) ldk.push_back(i);
    cin>>l>>r;
     z=l-1; km=1;
      if (l==r) {  cout<<l; return 0;}
     for (auto w:ldk)
     {
     	if (w>r) break;
         kq=0; j=0; kk=w; u=0;
         while(r/kk-z/kk>0)
         {
            j++; kq=kq+r/kk-z/kk;   kk=kk*w;
         }
         kq=kq-j; 
         km=km*mu(w,kq)%m;
     }
     km=lkk(km,m); km=(km%m+m)%m;
     for (i=l;i<=r;i++)
     {
         km=(i%m)*km%m;
     }
     cout<<km;
}
