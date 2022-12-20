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

const long double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long double res = 0;
long double f[500005], de[500005], x[500005], y[500005];
vector<pair<int, int>> a[500005];
int n, s, t;

void dfs(int u, int par)
{
	//cout << u << endl;
	x[u] = 1;
	if ((int)a[u].size() == 1)
	{
		y[u] = (long double)a[u][0].se/de[u];
		//cout << u << " " << x[u] << " " << y[u] << endl;
		
		return;
	}
	long double luu;
	for (auto v : a[u])
	if (v.fi != par)
	{
		dfs(v.fi, u);
		x[u] += x[v.fi]*(long double)v.se/de[u];
		y[u] += y[v.fi]*(long double)v.se/de[u];
	} else 
	{
		luu = v.se;
	}
	y[u] = 1 - y[u];
	x[u] = x[u]/y[u]; y[u] = (luu/de[u])/y[u];
	//cout << u << " " << x[u] << " " << y[u] << endl;
}

void dfs1(int u, int par)
{
	if (u == s)
	{
		cout << fixed << setp(9) << f[s];
		exit(0);
	}
	for (auto v : a[u])
	if (v.fi != par)
	{
		f[v.fi] = x[v.fi] + y[v.fi]*f[u];
		dfs1(v.fi, u);
	}
}

void solve() 
{
	cin >> n >> s >> t;
	for (int i = 1; i < n; i++)
	{
		int u, v; int w;
		cin >> u >> v >> w;
		de[u] += w; de[v] += w;
		a[u].pb({v, w}); a[v].pb({u, w});
	}
	if (s == t)
	{
		cout << fixed << setp(9) << res;
		return;
	}
	for (auto v : a[t])
	{
		dfs(v.fi, t);
		//cout << v.fi << endl;
		f[v.fi] = x[v.fi];
		dfs1(v.fi, t);
	}

	cout << fixed << setp(9) << f[s];

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
