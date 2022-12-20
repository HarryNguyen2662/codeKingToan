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

vector<int> a[100005];
int fen[200005], lca[100005][log +2], high[100005], in[100005], out[100005], cnt = 0; 

void dfs(int u, int par)
{
	lca[u][0] = par;
	in[u] = ++ cnt;
	high[u] = high[par] + 1;
	
	for (auto v : a[u])
	if (v != par)
	{	
		dfs(v, u);
	}

	out[u] = ++ cnt;
}

int findlca(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);
	for (int i = log; i >= 0; i--) if (high[lca[u][i]] >= high[v]) u = lca[u][i];
	if (u == v) return u;

	for (int i = log; i >= 0; i--) if (lca[u][i]  != lca[v][i])
	{
		u = lca[u][i]; v = lca[v][i];
	} 
	return lca[u][0];
}

void update(int id, int val)
{
	for (; id <= cnt; id += (id&(-id))) fen[id] += val;
}

int get(int id)
{
	int res = 0;
	for (; id; id -= (id&(-id))) res += fen[id];
	return res;
}

void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	dfs(1, 0);

	for (int i = 1; i <= log; i++) for (int j = 1; j <= n; j++)
	lca[j][i] = lca[lca[j][i-1]][i-1];

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		int uv = findlca(u, v);
		update(in[u], 1); update(in[v], 1); update(in[uv], -2);
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max(res, get(out[i]) - get(in[i] - 1));
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
