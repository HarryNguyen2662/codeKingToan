#include<bits/stdc++.h>
using namespace  std;
int na,nb,nc,nd;
long long dp[3005],dpp[3005];
struct slv
{
     long long x,y;
};	
slv a[3005],b[3005],c[3005],d[3005];
void input()
{
	cin >> na >> nb >> nc >> nd;
	for (int i = 1; i <= na; i++)
		cin >> a[i].x >> a[i].y;
	for (int i = 1; i <= nb; i++)
		cin >> b[i].x >> b[i].y;
	for (int i = 1; i <= nc; i++)
		cin >> c[i].x >> c[i].y;
	for (int i = 1; i <= nd; i++)
		cin >> d[i].x >> d[i].y;
}
void solve()
{
	for (int i = 1; i <=na; i++)
	for (int j = 1; j<= nb; j++)
	{
		if (dp[j] == 0) dp[j] = (a[i].x-b[j].x)*(a[i].x-b[j].x) + (a[i].y-b[j].y)*(a[i].y-b[j].y);
		else dp[j] = min(dp[j],(a[i].x-b[j].x)*(a[i].x-b[j].x) + (a[i].y-b[j].y)*(a[i].y-b[j].y));
	}
	//cout << dp[1] << " "<<dp[2]<<endl;
	for (int i = 1; i <=nd; i++)
	for (int j = 1; j<= nc; j++)
	{
		if (dpp[j] == 0) dpp[j] = (c[j].x-d[i].x)*(c[j].x-d[i].x) + (c[j].y-d[i].y)*(c[j].y-d[i].y);
		else dpp[j] = min(dpp[j],(c[j].x-d[i].x)*(c[j].x-d[i].x) + (c[j].y-d[i].y)*(c[j].y-d[i].y));
	}
	long long ans = 1e18;
	for (int i = 1; i <=nb; i++)
	for (int j = 1; j<= nc; j++)
	{
         ans = min (ans, dp[i]+dpp[j] +(c[j].x-b[i].x)*(c[j].x-b[i].x) + (c[j].y-b[i].y)*(c[j].y-b[i].y));
	}
	cout << ans;
}
int main()
{
	freopen("lololoin.txt","r",stdin);
	// ios_base::sync_with_stdio(0)
	input();
	solve();
}
	