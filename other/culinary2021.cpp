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

vector<int> a[100005];
vector<pair<int,int>> ldk;
int high[100005], pa[100005][log+4];

bool dd[100005];

void dfs(int u, int par)
{
	high[u] = high[par] + 1;
	pa[u][0] = par;
	dd[u] = true;
	for (auto v : a[u])
	if (v != par)
	{
		if (dd[v] == false) 
		{
			dfs(v, u);
		}
		else if (high[v] < high[u]) ldk.pb({u, v});
	}
}

int getlca(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);

	for (int i = log; i >= 0; i--) if (high[pa[u][i]] >= high[v]) u = pa[u][i];

	if (u == v) return u;

	for (int i = log; i >= 0; i--) if (pa[u][i] != pa[v][i])
	{
		u = pa[u][i]; v= pa[v][i];
	}

	return pa[u][0];
}
	
void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n + 1; i ++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	dfs(1, 0);

	if ((int)ldk.size() == 1) ldk.pb(ldk.back());

	for (int i = 1; i <= log; i++) for (int j = 1; j <= n; j++)
	pa[j][i] = pa[pa[j][i-1]][i-1];
	
	int uv = getlca(ldk[0].fi, ldk[1].fi);

	int aa = high[ldk[0].fi] - high[ldk[0].se] + 1;
	int bb = high[ldk[1].fi] - high[ldk[1].se] + 1;
	int cc = max(0, high[uv] - max(high[ldk[0].se], high[ldk[1].se]));

	cout << 1ll*(aa-cc)*(bb-cc) + 1ll*cc*(aa - cc + bb - cc);
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
