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

int pa[100005], num[100005], low[100005], cnt = 0;
vector<pair<int,int>> a[100005];
int dem[100005];
pair<int,int> luu[100005];
bool cau[100005];

int findpar(int u)
{
	return pa[u] < 0 ? u : pa[u] = findpar(pa[u]);
}

bool merge(int u,int v)
{
	u = findpar(u); v = findpar(v);

	if (u == v) return false;

	if (pa[u] > pa[v]) swap(u, v);

	pa[u] += pa[v];
	pa[v] = u;

	return true;
}

void dfs(int u, int par)
{
	num[u] = low[u] = ++cnt;

	for (auto v : a[u]) if (v.fi != par)
	{
		if (num[v.fi])
		{
			low[u] = min(low[u], num[v.fi]);
		}
		else
		{
			dfs(v.fi, u);
			low[u] = min(low[u], low[v.fi]);
		}

		if (low[v.fi] > num[u])
		{
			cau[v.se] = true;
		}
	}
}

void solve() 
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb({v, i}); a[v].pb({u, i});
		luu[i] = {u, v};
	}

	for (int i = 1; i <= n; i++) pa[i] = -1;

	dfs(1, 0);

	for (int i = 1; i <= m; i++) if (!cau[i]) merge(luu[i].fi, luu[i].se);

	for (int i = 1; i <= m; i++) if (cau[i]) 
	{
		int u = findpar(luu[i].fi), v = findpar(luu[i].se);
		dem[u]++; dem[v]++;
		//dem[luu[i].fi]++; dem[luu[i].se]++;
	}

	int res = 0;

	for (int i = 1; i <= n; i++) if (pa[i] < 0 && dem[i] == 1) res++;

	cout << (res + 1)/2;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("NETX.inp","r",stdin); freopen("NETX.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
