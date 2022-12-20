#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
#define fi first
#define se second
#define pb push_back
#define log 19
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

const int maxn = 1e6 + 5;

int lca[maxn][log + 5], high[maxn], luu[maxn];
ll dist[maxn];
vector<pair<int,int>> a[maxn];

void dfs(int u, int par)
{
	lca[u][0] = par;
	high[u] = high[par] + 1;

	for (auto v : a[u])
	if (v.fi != par)
	{
		dist[v.fi] = dist[u] + v.se;
		dfs(v.fi, u);
	}
}

int getlca(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);

	for (int i = log; i >= 0; i--) if (high[lca[u][i]] >= high[v]) u = lca[u][i];

	if (u == v) return u;

	for (int i = log; i >= 0; i--) if (lca[u][i] != lca[v][i])
	{
		u = lca[u][i]; v = lca[v][i];
	}

	return lca[u][0];
}

ll getdist(int u, int v)
{
	return dist[u] + dist[v] - 2*dist[getlca(u, v)];
}

void solve() 
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w; w++;
		a[u].pb({v, w}); a[v].pb({u, w});
	}

	dfs(1, 0);

	for (int i = 1; i <= log; i++) for (int j = 1; j <= n; j++)
	{
		lca[j][i] = lca[lca[j][i-1]][i-1];
	}

	while(q--)
	{
		int k;
		cin >> k;
		int st = 0;

		for (int i = 1; i <= k; i++)
		{
			cin >> luu[i];
			if (dist[luu[i]] > dist[st]) st = luu[i];
		}

		ll res = 0;

		for (int i = 1; i <= k; i++)
		{
			res = max(res, getdist(st, luu[i]));
		}

		cout << res << "\n";
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
