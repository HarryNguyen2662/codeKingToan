#include<bits/stdc++.h>
using namespace std;
long long kq[501];
int main()
{
	bitset<13> s; long long j,i,tt,m;
    for (i=1;i<2<<12;i++)
    {
    	s=i;
    	m=1; tt=0;
    	for (j=0;j<=12;j++)
    	{
    		if (s[j]==1) tt=9*m+tt;
    		m=m*10;
		}
		for (j=1;j<=500;j++)
			if (tt%j==0)
			{
				if (kq[j]==0) kq[j]=tt;
				else kq[j]=min(kq[j],tt);
			}
	}
	int n,q;
	cin>>q;
	while (q--)
	{
		cin>>n;
		cout<<kq[n]<<"\n";
	}
}
