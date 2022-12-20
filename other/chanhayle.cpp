#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
	int n,l,r,i,q;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	while (q--)
	{
	    cin>>l>>r;
		if (l>r) cout<<"Odd"<<"\n";
		else if (l==r||(l<r&&a[l+1]!=0)) {
			if (a[l]%2==0) cout<<"Even"<<"\n";
			else cout<<"Odd"<<"\n";
		 } else cout<<"Odd"<<"\n";	
	}
 } 
