#include<bits/stdc++.h>
using namespace std;
long long dp[405][405],a[405],f[405];
long long solve(int i, int j)
{
	if(dp[i][j]!=-1) return dp[i][j];
	if(i==j) return dp[i][j]=0;
	if(j-1==i) return dp[i][j]=a[i]+a[i+1];
	long long ans = 1e18;
	for(int x=i; x<j ;x++)
	{
		ans = min(ans,solve(i,x)+solve(x+1,j)+f[j]-f[i-1]);
	}
	return dp[i][j]=ans;
}
int main()
{
	freopen("lololoin.txt","r",stdin);
	int n;
	cin >> n;
	for(int i = 1; i<=n;i++)
	{
		cin>>a[i];
		f[i]=f[i-1]+a[i];
	}
	memset(dp,-1,sizeof dp);
	cout<<solve(1,n);
}