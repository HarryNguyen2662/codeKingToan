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

vector<int> a[300005], vec[300005];
int sz[300005], high[300005], sl[300005], col[300005];
long long dd[300005];
void calsize(int u, int par)
{
	sz[u] = 1;
	for (auto v : a[u])
	if (v != par)
	{
		high[v] = high[u] + 1;
		calsize(v, u);
		sz[u] += sz[v];
	}
}
long long res = 0;
void dfs(int u, int par, int tt)
{
	int mxchild = 0;
	for (auto v : a[u])
	if (v != par)
	{
		if (sz[v] > sz[mxchild]) mxchild = v;
	}

	for (auto v : a[u])
	if (v != par && v != mxchild)
	{
		dfs(v, u, 0);
	}

	if (mxchild)
	{
		dfs(mxchild, u, 1);
		swap(vec[u], vec[mxchild]);
	}
	vec[u].pb(u);
	res += (dd[col[u]] - 1ll*high[u]*sl[col[u]]);
	sl[col[u]]++; dd[col[u]] += high[u];

	for (auto v : a[u])
	if (v != u && v != mxchild)
	{
		for (auto x : vec[v])
		{
			res += (dd[col[x]] + 1ll*(high[x] - 2*high[u])*sl[col[x]]);
		}
		for (auto x : vec[v])
		{
			sl[col[x]]++; dd[col[x]] += high[x];
			vec[u].pb(x);
		}	
	}
	if (tt == 0)
	{
		for (auto v : vec[u])
		{
			sl[col[v]]--; dd[col[v]] -= high[v];
		}
	}
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> col[i];
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}
	calsize(1, 0);
	dfs(1, 0, 1);
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
