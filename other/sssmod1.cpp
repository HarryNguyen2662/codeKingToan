#include<bits/stdc++.h>
using namespace std; 
int dem[1000000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; long long n,i,k,m,tong=0;
	cin>>s; cin>>n;
	if (n==2)
	{
		long long kq=0;
		for (i=0;i<s.size();i++) if (s[i]%2==0) kq+=i+1; 
		cout<<kq; return 0;
	}
	if (n==5)
	{
		long long kq=0;
		for (i=0;i<s.size();i++) if ((s[i]-48)%5==0) kq+=i+1; 
		cout<<kq; return 0;
	}
	m=1;
	for (i=s.size()-1;i>=0;i--)
	{
		 long long k=s[i]-48;
		 tong=((k*m%n)+tong)%n; dem[tong]++;
		 m=m*10%n;
 }
	dem[0]++; long long kq=0;
	for (i=0;i<n;i++) 
	{
		m=dem[i]; kq=kq+m*(m-1)/2;
	}
	cout<<kq;
}
