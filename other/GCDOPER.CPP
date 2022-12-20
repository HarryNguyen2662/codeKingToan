#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	freopen("lololoin.txt","r",stdin);
	// freopen("GCDOPER.INP","r",stdin);
	// freopen("GCDOPER.OUT","w",stdout);
	int ans =1e9,n,t;
	cin>>n;
	for(int i = 1; i<= n; i++) cin>>a[i];
	for(int i = 1; i<=n; i++)
	{
		t=a[i];
			for(int j=i; j<=n; j++)
		{
			t=__gcd(t,a[j]);
			//cout<<t<<endl;
			if(t==1)
			{
				ans = min(ans,j-i+n-1);
				break;
			}
		}
	}
	if(ans!=1000000000) cout<<ans; else cout << -1;
}