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

int res = 0;
int he[200005], sz[200005], mx[200005], va[200005];
bool lu[200005];
vector<int> a[200005], vec[200005];
map<int,int> dd;

void calsize(int u, int par)
{
	he[u] = he[par]^va[u];
	sz[u] = 1;
	mx[u] = 0;
	for (auto v : a[u])
	if (v != par)
	{
		calsize(v, u);
		sz[u] += sz[v];
		if (sz[mx[u]] < sz[v]) mx[u] = v;
	}
}

void dfs(int u, int par, bool ti)
{
	for (auto v : a[u])
	if (v != par && v != mx[u])
	{
		dfs(v, u, 0);
	}

	if (mx[u]) 
	{
		dfs(mx[u], u, 1);
		if (!lu[mx[u]])
		swap(vec[u], vec[mx[u]]);
	}

	bool kt = false;
	if (dd[he[u]^va[u]] > 0) kt = true;
	vec[u].pb(u); dd[he[u]]++; //cout << u << " " << he[u] << " " <<vec[u].size() << endl;
	for (auto v : a[u])
	if (v != u && v != mx[u])
	if (!lu[v])
	{
		if (!kt)
		for (auto x : vec[v])
		{
			//cout << "ua " << x << " " << (he[x]^va[u]) << endl;
			if (dd[he[x]^va[u]] > 0) 
			{
				kt = true;
				break;
			}
		}

		for (auto x : vec[v])
		{
			dd[he[x]] ++;
			vec[u].pb(x);
		}
	}
	res += kt;
	lu[u] = kt;
	if (ti == 0 || kt) 
	{
		for (auto v : vec[u]) dd[he[v]]--;
	}
}

void solve() 
{	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> va[i];
	}

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
