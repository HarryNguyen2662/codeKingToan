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

long long dist[200005][2], child[200005][2];

vector<int> a[200005];

void dfs(int u, int par)
{
	child[u][0] = 1;
	for (auto v : a[u]) 
	if (v != par)
	{
		dfs(v, u);
		child[u][0] += child[v][1];
		child[u][1] += child[v][0];

		dist[u][0] += dist[v][1];
		dist[u][1] += dist[v][0] + child[v][0];
	}	
}

long long res = 0;

void dfs1(int u, int par)
{
	if (u != 1)
	{
		dist[u][0] = dist[u][0] + dist[par][1] - dist[u][0] - child[u][0];
		dist[u][1] = dist[u][1] + dist[par][0] - dist[u][1] + child[par][0] - child[u][1];
		child[u][0] = child[par][1];
		child[u][1] = child[par][0];
	}

	res += dist[u][0] + dist[u][1];

	for (auto v : a[u]) if (v != par)
	{
		dfs1(v, u);
	}

}

void solve() 
{
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	dfs(1, 0); dfs1(1, 0);


	//cout << child[1][0]  << endl;

	cout << res/2;
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
