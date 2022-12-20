#include<bits/stdc++.h>
using namespace std;
long long int a[100001],b[100001];
int main()
{
	freopen("MATRIX.INP","r",stdin);
	freopen("MATRIX.OUT","w",stdout);
	long long n,k,i,j,kq,u,x,y; string s;
	cin>>n>>k;
	cin>>s;
	a[0]=1; b[0]=n*n;
	for (i=1;i<n;i++)
	{
	if (i%2!=0) a[i]=a[i-1]+1; else a[i]=a[i-1]+2*i;
	if (i%2!=0) b[i]=b[i-1]-1; else b[i]=b[i-1]-2*i;
	}
	kq=1; x=0;y=0;
	for (i=0;i<k;i++)
	{
		if (s[i]=='U') y--;
		if (s[i]=='D') y++;
		if (s[i]=='R') x++;
		if (s[i]=='L') x--;
		u=x+y;
	if (u<=n-1)
	{
		if(u%2==0)
		{
			kq=kq+a[u]-y;
		}
		else
		{
			kq=kq+a[u]+y;
		}
	}
	else
	{
		u=2*n-u-2;
			if(u%2!=0)
		{

			kq=kq+b[u]-n+y+1;
		}
		else
		{
			kq=kq+b[u]+n-y-1;
		}
	}
	}
	cout<<kq;
}1