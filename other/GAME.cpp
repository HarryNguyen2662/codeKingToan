#include<bits/stdc++.h>
using namespace std;
long long dp[17][70000],a[17][17];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t,n,i,j;
	cin>>t;
	while (t--)
	{
	 cin>>n;
	 for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++) cin>>a[i][j];
	   bitset<16> s;
	   for (i=1;i<1<<n;i++)
	   {
	   	s=i; 
	   	j=s.count(); dp[j][i]=1e18;
	   	for (int e=0;e<n;e++)
	   	 if (s[e]==1) dp[j][i]=min(dp[j][i],dp[j-1][i^(1<<e)]+a[j][e+1]);
	   }
	   cout<<dp[n][(1<<n)-1]<<"\n";
	}
}
