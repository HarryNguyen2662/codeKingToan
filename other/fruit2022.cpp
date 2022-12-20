#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

const int lim = 250000;

vector<int> a[lim + 3], id[lim + 3], vec[lim + 3];
int high[lim + 3], st[lim + 3], ed[lim + 3], lca[lim + 3][log + 2], c[lim + 3], cnt = 0, dem[log + 2][2*lim + 2];

void dfs(int u, int par)
{	
	high[u] = high[par] + 1;
	lca[u][0] = par;

	st[u] = ++cnt;
	id[c[u]].pb(cnt);
	if (!(int)vec[c[u]].size()) vec[c[u]].pb(1); else vec[c[u]].pb(vec[c[u]].back() + 1); 

	for (auto v : a[u])
	if (v != par)
	{
		dfs(v, u);
	}

	ed[u] = ++cnt;
	id[c[u]].pb(cnt);
	vec[c[u]].pb(vec[c[u]].back() - 1); 

}

int findlca(int u, int v)
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

int col(int u, int v)
{
	int uv = findlca(u, v);
	int co = 0;
	int len = high[u] + high[v] - 2*high[uv] + 1;

	//cout << u << " " << v << " " << uv << " " << len << endl;
	for (int i = 0; i <= log; i++)
	{
		int bit1 = dem[i][st[u]] + dem[i][st[v]] - 2*dem[i][st[uv]] + ck(c[uv], i);

		//cout << dem[i][st[u]] << " " << dem[i][st[v]]<< endl;
		if (bit1 == len - bit1) return -1;
		if (bit1 > len - bit1) co += mask(i);
	}
   // cout << co <<endl;

    //cout << st[u] << " " << st[v] << " " << st[uv] << endl;
    //for (auto v : id[co]) cout << v << " "; cout << endl;

	if (co > lim) return -1;

    if ((int)id[co].size()/2 <= len/2) return -1;

    int l = lower_bound(ALL(id[co]), st[uv]) - id[co].begin();

    int r = upper_bound(ALL(id[co]), st[u]) - id[co].begin();

    int r1 = upper_bound(ALL(id[co]), st[v]) - id[co].begin();

	int se = (r == 0 ? 0 : vec[co][r-1]) + (r1 == 0 ? 0 : vec[co][r1-1]) - 2*(l == 0 ? 0 : vec[co][l-1]) - (c[uv] == co);

	if (se > len/2) return co; else return -1;
}

void solve() 
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	dfs(1, 0); 


	for (int i = 0; i <= log; i++) 
	{
		for (int j = 1; j <= n; j++)
		{
			dem[i][st[j]] = ck(c[j], i);
			dem[i][ed[j]] = -ck(c[j], i);
			if (i)
			lca[j][i] = lca[lca[j][i-1]][i-1];
		}
		for (int j = 1; j <= cnt; j++) dem[i][j] += dem[i][j-1];
	}

	
	while(q--)
	{
		int u, v;
		cin >> u >> v;
	
		cout << col(u ,v) << "\n";
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
