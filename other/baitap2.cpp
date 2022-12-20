#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000];
int main()
{
	int i,j,n, kq=2e9;
	cin>>n;
	for ( i=0;i<n;i++) cin>>a[i];
	for (i=0;i<n;i++) cin>>b[i];
	sort(a,a+n); sort(b,b+n);
	 i=n-1; j=0;
	 while (i>=0&&j<n)
	 {
	 	kq=min(kq,abs(a[i]+b[j]));
	 	if (a[i]+b[j]<0) j++; else i--;
	 }
	 cout<<kq;
}
