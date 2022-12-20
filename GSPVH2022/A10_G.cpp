#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 17
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define ALL(v) v.begin(), v.end()
#define ck(n, i) (((n) >> (i)) & 1) 
#define getbit(x) __builtin_popcount(x)

const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> a[1000005];
int mx[3][1000005], w[1000005];
long long dist[1000005], mx12[1000005], mx13[1000005], mx23[1000005], g[1000005], gg[1000005];
long long res = 0;

void dfs(int u, int par)
{

	dist[u] = w[u];

	for (auto v : a[u])
	if (v != par)
	{
		dfs(v, u);
		dist[u] = max(dist[u], dist[v] + w[u]);
		g[u] = max(g[u], g[v]);
		g[u] = max(g[u], dist[mx[0][v]] + dist[mx[1][v]] + w[v]);

		gg[u] = max(gg[u], gg[v] + w[u]);

		if (dist[v] > dist[mx[0][u]])
		{
			mx[2][u] = mx[1][u]; mx[1][u] = mx[0][u]; mx[0][u] = v;
		}
		else if (dist[v] > dist[mx[1][u]])
		{
			mx[2][u] = mx[1][u]; mx[1][u] = v;
		}
		else if (dist[v] > dist[mx[2][u]])
		{
			mx[2][u] = v;
		}

	}

	for (auto v : a[u])
	if (v != par)
	{
		if (v == mx[0][u])
		{
		 	gg[u] = max(gg[u], dist[mx[1][u]] + w[u] + max(g[v], dist[mx[0][v]] + dist[mx[1][v]] + w[v])); 
			res = max(res, gg[v] + dist[mx[1][u]] + w[u]);
		}
		else
		{
			res = max(res, gg[v] + dist[u]);
			gg[u] = max(gg[u], dist[mx[0][u]] + w[u] + max(g[v], dist[mx[0][v]] + dist[mx[1][v]] + w[v])); 
		}

		if (v != mx[0][u] && v != mx[2][u])
		{	
			mx13[u] = max(mx13[u], g[v]);
			mx13[u] = max(mx13[u],  dist[mx[0][v]] + dist[mx[1][v]] + w[v]);
		}

		if (v != mx[1][u] && v != mx[0][u])
		{	
			mx12[u] = max(mx12[u], g[v]);
			mx12[u] = max(mx12[u],  dist[mx[0][v]] + dist[mx[1][v]] + w[v]);
			
		}

		if (v != mx[2][u] && v != mx[1][u])
		{
			mx23[u] = max(mx23[u], g[v]);
			mx23[u] = max(mx23[u],  dist[mx[0][v]] + dist[mx[1][v]] + w[v]);
		}

	}
}

void dfs1(int u, int par)
{
	long long x = -1, xx = -1;
	for (auto v : a[u])
	if (v != par)
	{
		long long val = max(g[v], dist[mx[0][v]] + dist[mx[1][v]] + w[v]);
		if (val > x)
		{
			xx = x; x = val;
		}
		else xx = max(xx, val);

		dfs1(v, u);
	
	}

	res = max(res, gg[u]);

	if (mx[0][u] != 0 && mx[1][u] != 0)
	{
		res = max(res, dist[mx[0][u]] + dist[mx[1][u]] + w[u] + mx12[u]);
	}

	if (mx[0][u] != 0 && mx[2][u] != 0)
	{
		res = max(res, dist[mx[0][u]] + dist[mx[2][u]] + w[u] + mx13[u]);
	}

	if (mx[1][u] != 0 && mx[2][u] != 0)
	{
		res = max(res, dist[mx[1][u]] + dist[mx[2][u]] + w[u] + mx23[u]);
	}

	if (x != -1 && xx != -1)
	res = max(res, x + xx);
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}


	dfs(1, 0); dfs1(1, 0);

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
    //freopen("twopaths.inp","r",stdin); freopen("twopaths.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
