#include<bits/stdc++.h>
using namespace std;
vector<int> a[100005];
int dp[100005];
int dfs(int u)
{
	if (dp[u]!=-1) return dp[u];
	dp[u] = 0;
	for (auto v : a[u])
	{
		int giatri = dfs(v) + 1;
		dp[u] = max(dp[u],giatri);
	}
	return dp[u];
}
void solve()
{
	int n , m , u, v, ans =0;
	cin >> n >> m;
	for (int i = 0; i < m ;i++)
	{
		cin >> u >> v;
		a[u].push_back(v);
	}
	memset(dp,-1,sizeof dp );
	for (int i = 1; i<= n ;i++)
	{
		ans  = max (ans,dfs(i));
	}
	cout << ans;
}
int main()
{
 //ios_base::sync_with_stdio(0);
   // cin.tie(0); cout.tie(0);
    freopen("lololoin.txt","r",stdin);
	solve();
}