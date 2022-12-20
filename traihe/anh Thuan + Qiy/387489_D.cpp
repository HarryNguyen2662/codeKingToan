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

vector<int> a[100005];
int sz[100005], mx[100005], dad[100005], high[100005], lca[100005][log+5];
bool visit[100005], coler[100005];


void dfs(int u, int par)
{
	high[u] = high[par] + 1;
	lca[u][0] = par;
	for(auto v : a[u]) if (v != par)
	{
		dfs(v, u);
	}
}
int findlca(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);
	for (int i = log; i >= 0; i--) if (high[lca[u][i]] >= high[v]) u = lca[u][i];
	if (u == v) return u;
	for (int i = log; i >= 0; i--) if (lca[u][i] != lca[v][i])
	{
		u = lca[u][i]; v = lca[v][i];
	}
	return lca[u][0];
}

int dist(int u, int v)
{
	return high[u] + high[v] - 2*high[findlca(u, v)];
}

void calsize(int u)
{
	visit[u] = true;
	sz[u] = 1;
	mx[u] = 0;

	for(auto v : a[u]) if (visit[v] == false)
	{
		calsize(v);
		if (sz[v] > sz[mx[u]]) mx[u] = v;
		sz[u] += sz[v];
	}
	visit[u] = false;
}

int findpar(int u)
{
	int num = sz[u]/2;
	while(sz[mx[u]] > num) u = mx[u];
	return u;
}


void centroid(int u, int par)
{
	calsize(u); u = findpar(u); 
	dad[u] = par;
	visit[u] = true;
	for (auto v : a[u]) if (visit[v] == false)
	{
		centroid(v, u);
	}
}
typedef pair<int,int> DATA;

priority_queue<DATA, vector<DATA>, greater<DATA>> sg[1000005];

void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}
	//high[0] = 0;
	dfs(1, 0);
	for (int  i = 1; i <= log; i++) for (int j = 1; j <= n; j++)
	lca[j][i] = lca[lca[j][i-1]][i-1];
	centroid(1, 0);
		
	while(m--)
	{
		int type, u;
		cin >> type >> u;
		if (type == 1)
		{
			coler[u] = 1 - coler[u];
			if (coler[u])
			{
				for (int i = u; i; i = dad[i])
				{
					sg[i].push({dist(u, i), u});
				}
			}
			
		}
		else
		{
			int res = oo;
			for (int i = u; i; i = dad[i])
			{
				while(!sg[i].empty())
				{
					DATA w = sg[i].top(); 
					if (coler[w.se])
					{
						res = min(res, w.fi + dist(u, i));
						break;
					}
					else sg[i].pop();
				}
			}
			//cout << u << endl;
			if (res == oo) cout << "-1\n";
			else cout << res << "\n"; 
		}
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
