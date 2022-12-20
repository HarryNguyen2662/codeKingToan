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

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
vector<pair<int,int>> a[100005];
int high[100005], par[100005][log+5];
long long dist[100005];
void dfs(int u, int dad)
{
	high[u] = high[dad] + 1;
	par[u][0] = dad;
	for (auto v : a[u])
	if (v.fi != dad)
	{
		dist[v.fi] = dist[u] + v.se;
		dfs(v.fi, u);
	}
}
int findlca(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);
	for (int i = log; i >= 0; i--)
	if (high[par[u][i]] >= high[v]) u = par[u][i];
	if (u == v) return u;
	for (int i = log; i >= 0; i--) 
	if (par[u][i] != par[v][i])
	{
		u = par[u][i];
		v = par[v][i];
	}
	return par[u][0];
}
void solve() 
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		//cout << u << " " <<v << " " << w << endl;
		a[u].pb({v, w}); a[v].pb({u, w});
	}
	dfs(1, 0); 
	for (int i = 1 ; i <= log; i++) for (int j = 1; j <= n; j++) 
	par[j][i] = par[par[j][i-1]][i-1];
	while(q--)
	{
		int type, u, v;
		cin >> type >> u >> v;
		if (type == 1)
		{
			cout << dist[u] + dist[v] - 2*dist[findlca(u, v)] << "\n";
		}
		else
		{
			int k;
			cin >> k;
			int uv = findlca(u, v);
			int re;
			if (high[u] - high[uv] + 1 >= k)
			{
				re = u;
				k--;
			}
			else
			{
				re = v;
				k = k - high[u] + high[uv];
  				k = high[v] - high[uv]  - k + 1;
			}
			//cout << k << endl;
			for (int i = log; i >= 0; i--)
			if (k >= mask(i))
			{
				//cout << i << endl;
				k -= mask(i);
				re = par[re][i];
			}
			//cout << k << endl;
			cout << re << "\n";
		}
	}
}

int main() 
{   
	 #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    freopen("QGRAPH.inp","r",stdin); freopen("QGRAPH.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
