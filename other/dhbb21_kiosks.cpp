#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mask(n) (1ll << (n))
#define ck(n, i) (((n) >> (i)) & 1) 
#define getcnt1(n) __builtin_popcount(n)
#define ALL(n) n.begin(), n.end()

const long long MOD = (long long )1e9 + 7;

vector<int> a[10005];
long long dp[10005];
int c[10005];

void dfs(int u, int par)
{
	for (auto v : a[u])
	if (v != par)
	{
		dfs(v, u);
		dp[u] = dp[u]*dp[v]%MOD;
	}
	dp[u]++; dp[u]%= MOD;
}


void solve()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		c[i]--;
	}

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	long long res = 0;

	for (int msk = 0; msk < mask(k); msk++)
	{
		for (int i = 1; i <= n; i++) if (c[i] < k && ck(msk, c[i])) dp[i] = 0; else dp[i] = 1;
		dfs(1, 0);
		
		long long heso = MOD - 1;
		if (getcnt1(msk)%2 == 0) heso = 1;
	
		for (int i = 1; i <= n; i++)
		{
			res = (res + heso*dp[i]%MOD)%MOD;
		}
	}
	cout << res;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
}