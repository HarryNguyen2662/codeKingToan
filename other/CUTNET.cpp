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

int par[100005], ans[100005];
bool ok[100005];

int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}

bool merge(int u, int v)
{
	u = findpar(u); v = findpar(v);

	if (u == v) return 0;

	if(par[u] > par[v]) swap(u, v);
	
	par[u] += par[v];
	par[v] = u;

	return 1;
}

void solve() 
{
	int n, m;
	vector<pair<int,int>> ldk, dk;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		par[i] = -1;
	}

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		ldk.pb({u, v});
	}
	sort(ALL(ldk));

	int t;
	cin >> t; 

	for (int i = 1; i <= t; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u ,v);
		dk.pb({u, v});
		int id = lower_bound(ALL(ldk),	dk.back()) - ldk.begin();
		if (id != (int)ldk.size() && ldk[id] == dk.back()) ok[id] = true;
	}

	int tplt = n;
	for (int i = 0; i < (int)ldk.size(); i++) if (!ok[i]) 
	{
		tplt -= merge(ldk[i].fi, ldk[i].se);
	}

	for (int i = t - 1; i >= 0; i--)
	{
		ans[i] = tplt; 
		tplt -= merge(dk[i].fi, dk[i].se); 
	}

	for (int i = 0; i < t; i++) cout << ans[i] << "\n";
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
