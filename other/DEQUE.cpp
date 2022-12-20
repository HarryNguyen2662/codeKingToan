#include<bits/stdc++.h>
using namespace std;
const long long u = -1e18;
long long dp[3005][3005];
int a[3005];
long long solve(int i, int j)
{
	if (dp[i][j]!=u) return dp[i][j];
	if (i==j) return dp[i][j] = a[i];
	return dp[i][j]=max(a[i]-solve(i+1,j),a[j]-solve(i,j-1));
}
int main()
{
	freopen("lololoin.txt","r",stdin);
	int n;
	cin >> n;
	for (int i = 1; i <=n; i++) 
		cin >> a[i];
	for (int i =1 ; i <= n ; i++)
		for (int j = 1; j <= n; j ++) dp[i][j]=u;
   cout << solve(1,n);
}