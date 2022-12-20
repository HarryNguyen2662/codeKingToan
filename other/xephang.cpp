#include<bits/stdc++.h>
using namespace std; 
long long dp[21][1050000],a[21][21];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,i,j,e;
	cin>>n;
	for (i=1;i<=n;i++)
	 for (j=1;j<=n;j++)
	  cin>>a[i][j];
	bitset<20> s;
	for (i=1;i<1<<n;i++)
	{
		s=i; 
		 j=s.count();
		 for (e=0;e<n;e++)
		 if (s[e]==1) dp[j][i]=max(dp[j][i],dp[j-1][i-(1<<e)]+a[j][e+1]);
		 cout<<s<<" "<<j<<" "<<dp[j][i]<<endl;
	}
	cout<<dp[n][(1<<n)-1];
}
