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

long long di[100005], dis[100005], dist[100005], su[100005];
vector<pair<int,int>> a[100005];
int sz[100005];
int n, k;

void dfs(int u, int par)
{
	if (sz[u])
	{
		dis[u] = di[u] = 0;
	}
	else
	{
		dis[u] = di[u] = -oo15;
	}
	for (auto v : a[u]) if (v.fi != par)
	{
		dfs(v.fi, u);
		if (sz[v.fi])
		{
			sz[u] += sz[v.fi];
			su[u] += su[v.fi] + v.se;
			if (dis[u] < dis[v.fi] + v.se)
			{
				di[u] = dis[u];
				dis[u] = dis[v.fi] + v.se; 
			}
			else di[u] = max(di[u], dis[v.fi] + v.se);

		}
	}
}

void dfs1(int u, int par)
{
	for (auto v : a[u]) if (v.fi != par)
	{
		if (sz[v.fi] && (k - sz[v.fi]))
		{
			su[v.fi] = su[u];
			dist[v.fi] = dist[u] + v.se;

			if (dis[v.fi] + v.se != dis[u] && dis[u] >= 0)
			{
				dist[v.fi] = max(dist[v.fi], dis[u] + v.se);
			}
			else if (dis[v.fi] + v.se == dis[u] && di[u] >= 0)
			{
				dist[v.fi] = max(dist[v.fi], di[u] + v.se);
			}
		}
		else if (sz[v.fi] == 0)
		{
			su[v.fi] = su[u] + v.se;
			dist[v.fi] = dist[u] + v.se;

			if (dis[v.fi] + v.se != dis[u] && dis[u] >= 0)
			{
				dist[v.fi] = max(dist[v.fi], dis[u] + v.se);
			}
			else if (dis[v.fi] + v.se == dis[u] && di[u] >= 0)
			{
				dist[v.fi] = max(dist[v.fi], di[u] + v.se);
			}
		}
		else if (sz[v.fi] == k)
		{
			su[v.fi] = su[u] - v.se;
		}
		dfs1(v.fi, u);
	}
}

void solve() 
{
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].pb({v, w});
		a[v].pb({u, w});
	}

	for (int i = 1; i <= k; i++)
	{
		int val;
		cin >> val;
		sz[val] = 1;	
	}

	dfs(1, 0); dfs1(1, 0);
	for (int i = 1; i <= n; i++)
	{
		//cout << "eehlo\n";
		cout << 2*su[i] - max(dist[i], dis[i]) << "\n";
	}

}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
