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

int high[100005], lca[100005][log +2];

long long n, m;

vector<int> a[100005];

long long child[100005], g[100005], f[100005], fg[100005];

void dfs(int u, int par)
{
	high[u] = high[par] + 1;
	child[u] = 1; g[u] = 1;
	lca[u][0] = par;

	for (auto v : a[u]) if (v != par)
	{
		dfs(v, u);
		g[u] = g[u] + 1ll*child[u]*child[v];
		child[u] += child[v];
	}

	for (auto v : a[u]) if (v != par)
	{
		f[v] = 1ll*child[v]*(child[u] - child[v]);
	}

}

void dfs1(int u, int par)
{
	fg[u] = fg[par] + g[u] - f[u];

	for (auto v : a[u]) if (v != par) dfs1(v, u); 
}

long long cal(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);
	
	int _u = u, _v = v;
	
	for (int i = log; i >= 0; i--) if (high[lca[u][i]] >= high[v]) u = lca[u][i];

	//cout << u << " " << v << endl;

	if (u == v)
	{
		int uu = _u;

		for (int  i = log; i >= 0; i--) if (high[lca[uu][i]] >= high[v] + 1) uu = lca[uu][i];

		//cout << _u << " " << uu << " " << u << endl;

		return fg[_u] - fg[u] + g[u] + (child[u] -  child[uu])*1ll*(n - child[u]);
	}

	for (int i = log; i >= 0; i--) if (lca[u][i] != lca[v][i])
	{
		u = lca[u][i]; v = lca[v][i];
	}

	int uv = lca[u][0];


	return fg[_u] + fg[_v] - 2*fg[uv] + g[uv] + child[u]*child[v] + (child[uv] - child[u] - child[v])*1ll*(n - child[uv]); 
}
void solve() 
{
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	dfs(1, 0); dfs1(1, 0);
	for (int i = 1; i <= log; i++) for (int j = 1; j <= n; j++) lca[j][i] = lca[lca[j][i-1]][i-1];

	//for (int i = 1; i <= n; i++) cout << i << " " << g[i] << " " << f[i] << " " << fg[i] << "\n";

//	cout << f[3] << " " << f[2] << endl;
//	cout << fg[2] + fg[6] - 2*fg[1] + g[1] + child[2]*child[3] << endl;

	//cout << g[1] << endl;
	while(m--)
	{
		int u, v;
		cin >> u >> v;	
		if (u == v)
		{
			cout << g[u] + child[u]*(n - child[u]) << "\n";
		}	
		else
		cout << cal(u, v) << "\n";
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
