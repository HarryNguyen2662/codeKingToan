#include<bits/stdc++.h>
using namespace std;
double d[1000001][2];
int a[1000001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t,n,i; double kq;
    cin>>t;
    while(t--)
    {
       cin>>n;
       for (i=1;i<=n;i++)
       {
       	cin>>a[i]; 
       	d[i][0]=d[i][1]=0;
	   }
	    d[0][0]=0; kq=0;
	    for (i=1;i<=n;i++)
	    {
	    	d[i][0]=max(d[i-1][0]+a[i-1], d[i-1][1]);
	    	d[i][1]=max(d[i-1][0]+(a[i-1]+a[i+1])/2.0 ,d[i-1][1]+a[i+1]);
	    	kq=max({kq,d[i][0],d[i][1]});
		}
		cout <<fixed<<setprecision(1);
		cout<<kq<<"\n";	
	}
}
