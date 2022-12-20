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

int mx = 0;
bool de[35][100005], dd[100005];
vector<int> a[100005];
int par[100005];

void dfs(vector<int> ldk, int tt)
{
	mx = max(mx, tt);
	int nn = (int)ldk.size()/2;

	// cout << (int)ldk.size()<< endl;

	for (int i = 0; i < nn; i++) de[tt][ldk[i]] = true;

	vector<int> dk; 
	
	while((int)ldk.size() > nn) 
	{
		dk.pb(ldk.back()); ldk.pop_back();
	}
	// cout  <<  (int)ldk.size() << " " << (int)dk.size() << "\n";

	if ((int)ldk.size() > 1) dfs(ldk, tt + 1);
	if ((int)dk.size() > 1) dfs(dk, tt + 1);
}

int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}

void merge(int u, int v)
{
	u = findpar(u); v = findpar(v);
	
	if (u == v) return;	
	if (par[u] > par[v]) swap(u, v);
	
	par[u] += par[v];
	par[v] = u;
}

void solve() 
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) par[i] = -1;

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);		
	}

	for (int i = 1; i <= n; i++)
	{
		for (auto v : a[i]) dd[v] = true;
	
		int v = 1;
		while(dd[v]) v++;

		merge(i, v);

		for (auto v : a[i]) dd[v] = false;
	
	}

	vector<int> ldk;

	for (int i = 1; i <= n; i++) 
	{
		for (auto v : a[i]) if (findpar(v) == findpar(i))
		{
			cout << "-1"; return;
		}
		if (par[i] < 0) ldk.pb(i); 
	}

	// for (auto v : ldk) cout << v << "\n";
	dfs(ldk, 1);

	cout << mx << "\n";
	for (int e = 1; e <= mx; e++)
	{
		for (int i = 1; i <= n; i++) cout << de[e][findpar(i)];
		cout << "\n";
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
