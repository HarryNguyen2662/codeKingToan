#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
		int n,k;
	cin >>n >> k;
	if(k==1) cout << 1;
	if(k==2) cout << (n-1)/2;
	if (k==3)
	{
		int ans = 0;
		for (int i = 1; i<=n; i++)
			for (int j =i +1; j<=n; j++)
				if (n-i-2*j>0) ans++;
			cout << ans;
	}
	if (k==4)
	{
		int ans =0; 
		for (int i= 1; i<=n; i++)
			for(int j = i+1; j<=n; j++)
				if(n-i-3*j>=3) ans=ans+(n-i-3*j-1)/2;
		cout << ans;
	}
}