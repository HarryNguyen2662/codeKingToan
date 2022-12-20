#include<bits/stdc++.h>
using namespace std;
int f[5001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long kq=0; int i,n,k,dem,so,t,l,kt=1; string s;
	cin>>k;
	cin>>s; l=0; t=0; dem=0; so=1;
	for (i=0;i<s.size();i++)
	{
		if (s[i]=='1') dem++;
		if (dem>k)
		{
			 while (dem>k&&l<i)
		 {
		 	if (s[l]=='1') dem--;
		 	l++;
		 }
			t=l; so=1;
		}
		if (dem==k)
		{ 
			while (s[t]=='0'&&t<i) {
				so++; t++;
	
		}
				kq+=so; 
		}
	
	}
      cout<<kq;
}
