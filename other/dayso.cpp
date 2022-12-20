#include<bits/stdc++.h>
using namespace std;
int a[100001]; 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,l,i,kq,dem=0; map<int,int> dd;
	cin>>n>>m;
	l=1;
	for (i=1;i<=n;i++) 
	{
		cin>>a[i];
		if (dd[a[i]]==0) dem++;
		   dd[a[i]]++; 
		while (dem>m) 
		{
			dd[a[l]]--; if (dd[a[l]]==0) dem--; 
			l++; 
		}
		kq=max(kq,i-l+1);
	}
	 cout<<kq;
}
