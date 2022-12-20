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
int high[300005], par[300005][log+5];
vector<int> a[300005];
pair<int,int> ed[300005];
void dfs(int u, int dad)
{
	high[u] = high[dad] + 1;
	par[u][0] = dad;
	for (auto v : a[u])
	if (v != dad)
	{
		dfs(v, u);
	}
}
int getlca(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);
	for (int i = log; i >= 0; i--)
	if (high[par[u][i]] >= high[v]) u = par[u][i];
	if (u == v) return u;
	for (int i = log; i >= 0; i--) if (par[u][i] != par[v][i])
	{
		u = par[u][i]; v = par[v][i];
	}
	return par[u][0];
}
int getpar(int u, int dai)
{
	for (int i = log; i >= 0; i--)
	if (dai >= mask(i))
	{
		dai -= mask(i);
		u = par[u][i];
	}
	return u;
}
bool thuoc(int x, int y)
{
	if (x == y) return true;
	if (high[x] < high[y]) swap(x, y);
	return y == getpar(x, high[x] - high[y]);
}
bool check(int i, int j)
{
	int u = ed[i].fi, v = ed[i].se, x = ed[j].fi, y = ed[j].se;
	bool kt1 = thuoc(x, u, v), kt2 = thuoc(y, u, v);
	if (kt1 == kt2)
	{
		if (kt1) return true;
		else
		{
			if (thuoc(getlca(u, v), x, y) || thuoc(getlca(x, y), u, v)) return false;
			return true;
		}
	}
	return false;
}
void solve() 
{
	int w;
	int n;
	cin >> w;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= log; i++) for (int j = 1; j <= n; j++) par[j][i] = par[par[j][i-1]][i-1];
	int q;
	cin >> q;

	while(q--)
	{
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++) cin >> ed[i].fi >> ed[i].se;
		bool kt = true;
		for (int i = 1; i <= k; i++)
		{
			for (int j = i + 1; j <= k; j++) 
			{
				int id1 = getlca(ed[i].fi, ed[i].se), id2 = getlca(ed[j].fi, ed[j].se);
				if (high[id1] < high[id2]) swap(id1, id2);
				if (id1 == id2)
				{
					if ()
				}
				else if (thuoc(id1, id2))
				{
					if (thuoc())
				}
			}
		}
		if (kt) cout << "RO RANG\n"; else cout << "MAP MO\n";
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
