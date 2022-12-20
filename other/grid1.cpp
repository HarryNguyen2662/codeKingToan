#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
long long dp[1005][1005];
char a[1005][1005];
void solve()
{
	int n ,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	dp[0][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j]!='#') dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
	cout << dp[n][m];	
}
int main()
{
 //ios_base::sync_with_stdio(0);
   // cin.tie(0); cout.tie(0);
    freopen("lololoin.txt","r",stdin);
	solve();
}