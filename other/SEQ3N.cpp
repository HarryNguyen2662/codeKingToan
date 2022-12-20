#include<bits/stdc++.h>
using namespace std;
priority_queue<int> s,ss;
int a[300001];
long long k[100001],kk[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,i; long long maxx=-1e18, tong=0;
	cin>>n;
	for (i=1;i<=3*n;i++) cin>>a[i];
    for (i=1;i<2*n;i++)
    { 
       s.push(-1*a[i]); tong+=a[i];
       if (i==n) k[0]=tong;
       if(i>n) {
       	 tong+=s.top();
       	 k[i-n]=tong;
         s.pop();
	   }
	}
	tong=0;
	for (i=3*n;i>n;i--)
	{
	   ss.push(a[i]); tong=tong+a[i];
	   if (i==2*n) kk[0]=tong;
	   if (i<2*n)
	   {
	   	 tong=tong-ss.top();
	   	 kk[2*n-i]=tong;
	   	 ss.pop();
	   }	
	}
	for (i=0;i<=n;i++)
	{
		cout<<k[i]<<" "<<kk[i]<<endl;
		maxx=max(maxx,k[i]-kk[n-i]);
	}
	cout<<maxx;
}

