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

int n, ff[4005], ans[4005], in[4005], out[4005], child1[4005], child[4005], t;
int cnt = 0;
vector<int> ed[4006], ed1[4005];

void dfs1(int u, int par)
{
	child1[u] = 1;
	ff[u] = (in[t] <= in[u] && in[u] <= out[t]);// cout << ff[u] << endl;
	for (auto v : ed1[u])
	if (v != par)
	{
		dfs1(v, u);
		//cout << " hi " << v << endl; 
	//	cout <<" alo " <<  ff[v] << " " << child[t] << endl;
		int cu = max({ff[v], child[t] - ff[v], child1[v] - ff[v], n - child1[v] - child[t] + ff[v]});
		//cout << ff[v] << " "<< child[t] - ff[v] << " "<< child1[v] - ff[v] << " "<< n - child1[v] - child[t] + ff[v] << endl;
		ans[cu]++;
		ff[u] += ff[v];
		child1[u] += child1[v];
	}
}

void dfs(int u, int par)
{
	child[u] = 1;
	for (auto v : ed[u])
	if (v != par)
	{
		dfs(v, u);
		t = v;
		//cout << " aka " << t << endl;
		child[u] += child[v];
		dfs1(1, 0);
	}
}

void euler(int u, int par)
{
	in[u] = ++cnt;
	for (auto v : ed[u])
	if (v != par)
	{
		euler(v, u);
	}
	out[u] = ++cnt;
}

void solve() 
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		//cout << u << " " << v << endl;
		ed[u].pb(v); ed[v].pb(u);
	}

	for (int i = 1 ; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		ed1[u].pb(v); ed1[v].pb(u);
	}

	euler(1, 0);
	//for (int i = 1; i <= cnt; i++)
	dfs(1, 0);
	for (int i = 0; i <= n; i++) cout << ans[i] << " ";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("twotrees.inp","r",stdin); freopen("twotrees.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
