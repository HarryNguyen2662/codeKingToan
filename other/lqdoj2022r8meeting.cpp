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

vector<int> edge[1000005];
int high[1000005];
int lca[1000005][log + 5];

pair<int,int> p[1000005];

void dfs(int u, int par)
{
	high[u] = high[par] + 1;
	lca[u][0] = par;
	for (auto v : edge[u]) if (v != par)
	{
		dfs(v, u);
	}

}

int getlca(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);

	for (int i = log; i >= 0; i--) if (high[lca[u][i]] >= high[v])
	{
		u = lca[u][i];
	}

	if (u == v) return u;

	for (int i = log; i >= 0; i--) if (lca[u][i] != lca[v][i])
	{
		u = lca[u][i]; v = lca[v][i];
	}

	return lca[u][0];
}

 ll cal(int u, int v)
 {
 	int uv = getlca(u, v);

 	vector<int> ldk, dk;

 	// cout << u << " " << v << " " << uv << endl;
 	while(true)
 	{
 		ldk.pb(p[u].fi);
 		dk.pb(p[u].se);
 		if (u == uv) break;
 		u = lca[u][0];
 	}

 	while(true)
 	{
 		if (v == uv) break;
 		ldk.pb(p[v].fi);
 		dk.pb(p[v].se);
 		v = lca[v][0];
 	}

 	sort(ALL(ldk)); sort(ALL(dk));
 	int sz =(int)ldk.size() - 1;

 	int x = ldk[(sz)/2], y = dk[(sz)/2];

 	ll ans = 0;

 	for (auto v : ldk) ans += abs(v - x);
 	for (auto v : dk) ans += abs(v - y);

 	return ans;
 }

void solve() 
{
	int n, q;

	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].fi;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].se;
	}

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		edge[u].pb(v); edge[v].pb(u);
	}

	dfs(1, 0);

	for (int i = 1; i <= log; i++) for (int j = 1; j <= n; j++)
		lca[j][i] = lca[lca[j][i - 1]][i - 1];

	while(q--)
	{
		int u, v;
		cin >> u >> v;
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
    //freopen("MEETING.inp","r",stdin); freopen("MEETING.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
