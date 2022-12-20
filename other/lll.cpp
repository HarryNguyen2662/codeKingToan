#include<bits/stdc++.h>
using namespace std;
long long dp[5][1005][1005];
int n,k;
long long solve(int i,int sl, int keo)
{
	if(dp[i][sl][keo]!=-1) return dp[i][sl][keo];
	if (keo>n) return dp[i][sl][keo]=0;
	if (i==k) 
		{
			//cout << 1;
			return (keo==n);
		}
	long long ans = 0;
	for (int e = sl+1; e <= (n-keo)/(k-i); e++) 
		ans+=solve(i+1,e,keo+e);
	return dp[i][sl][keo] = ans;
}
int main()
{
//	freopen("lololoin.txt","r",stdin);
	cin >>n >> k;
	memset(dp,-1,sizeof dp);
	cout<<solve(0,0,0);
}
