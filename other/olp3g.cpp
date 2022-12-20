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

vector<pair<int, pair<int,int>>> ldk, qa;
int par[1000005], c[1000005];
int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}

long long res = 0;
void merge(int val, int u, int v)
{
	u = findpar(u); v = findpar(v);
	if (u == v) return;
	if (par[u] > par[v]) swap(u, v);
	res = res + 1ll*par[u]*1ll*par[v]*1ll*val; 
	par[u] += par[v];
	par[v] = u;
}
void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		ldk.pb({min(c[v], c[u]), {u, v}});
		qa.pb({max(c[v], c[u]), {u, v}});
	}

	
	for (int i = 1; i <= n; i++) par[i] = -1;
	sort(ALL(ldk));
	for (int i = (int)ldk.size() - 1; i >= 0; i--)
	{
		merge(ldk[i].fi, ldk[i].se.fi, ldk[i].se.se);
	}

	long long resmin = res; res = 0;
	for (int i = 1; i <= n; i++) par[i] = -1;
	sort(ALL(qa));
	for (auto v : qa)
	{
		merge(v.fi, v.se.fi, v.se.se);
	}
	cout << res - resmin;
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
