#include<bits/stdc++.h>
using namespace std;
int a[105];
long long dp[101][100005][2];
int main()
 {
 	freopen("lololoin.txt","r",stdin);
 	int n,m,k;
 	cin >>n >>m>>k; 
 	for (int i = 1; i<= n ;i++) cin>>a[i];
 		dp[0][0][0]=1; 
 	for (int sum =0; sum<=m; sum++)
 		for (int i=0; i<n; i++)
 		{
 			if (sum+a[i+1]<=m) dp[i+1][sum+a[i+1]][1]= dp[i][sum][1]+dp[i][sum][0];
 			dp[i+1][sum][0]= dp[i][sum][1]+dp[i][sum][0];
 		}
 	long long ans=max(dp[n][m][1],dp[n][m][0]);
 	if (ans>=k) cout<<"ENOUGH"; else cout << ans;
}