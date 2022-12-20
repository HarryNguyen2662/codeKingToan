#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 19
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
int xx[4] = {0, 0, -1, 1};
int yy[4] = {1, -1, 0, 0};
int cnt = 0, dd[1005][1005], par[1000005], high[1000005], lca[1000005][log+1], res[100005];
bool s[1005][1005];
vector<pair<int,int>> ldk;
int n;
pair<int,int> luu[100005], vt[100005];
void dfs(int x, int y, int dad)
{
	dd[x][y] = ++cnt;
	par[cnt] = -1;
	high[cnt] = high[dad] + 1;
	//cout << dad << " " << cnt << endl;
	lca[cnt][0] = dad;
	for (int i = 0; i < 4; i ++)
	{
		int nx = x + xx[i], ny = y + yy[i];
		//cout << x << " " << y << " " << nx << " " << ny << endl;
		if (nx < 1 || nx > n || ny < 1 || ny > n || s[nx][ny] || dd[nx][ny]) continue;
		
		dfs(nx, ny, dd[x][y]);
	}
}
int getlca(int u, int v)
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
int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}
void merge(int u, int v)
{
	u = findpar(u); v = findpar(v);
	if (u == v) return;
	if (par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
}
int dist(int u, int v)
{
	return high[u] + high[v] - high[getlca(u, v)];
}
void solve() 
{
	int m;
	cin >> n >> m;
	for (int i =1; i <= n; i++) for (int j = 1; j <= n; j++)
	{
		char helu;
		cin >> helu;
		if (helu == '1') s[i][j] = 1;
		//cout << s[i][j] << endl;
	}
	for (int i = 1; i <= n; i++) 
	{
		bool kt = false;
		for (int j = 1; j <= n; j++)
		if (s[i][j] == 0)
		{
			//cout << i << " " << j << endl;
			dfs(i, j, 1);
			kt = true;
			break;
		}
		//cout << kt << endl;
		if (kt) break;
	}
	for (int j = 1; j <= log; j ++) for (int i = 1; i <= cnt; i++) lca[i][j] = lca[lca[i][j-1]][j-1];
	int numans = 0;
	int numchange = 0;
	//cout << dd[1][1] << " " << high[7] << endl;
//	cout << getlca(1, 7) << endl;
	for (int i = 1; i <= m; i++)
	{
		int type;
		cin >> type;
		//cout << type << endl;
		if (type == 1)
		{
			numchange++;
			cin >> vt[numchange].fi >> vt[numchange].se;
			s[vt[numchange].fi][vt[numchange].se] = 1;
			ldk.pb({0, numchange});
		}
		else
		{
			numans++;	
			int x, y, u, v;
			cin >> x >> y >> u >> v;
			if (dd[x][y] && dd[u][v])
			{
				luu[numans] = {dd[x][y], dd[u][v]};
			}
			else luu[numans] = {-1, -1};
			ldk.pb({1, numans});
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	if (s[i][j] == 0)
	{
		for (int e = 0; e < 4; e++)
		{
			int ni = i + xx[e], nj = j + yy[e];
			if (ni >= 1 && ni <= n && nj >= 1 && nj <= n && !s[ni][nj])
			{
				merge(dd[i][j], dd[ni][nj]);
			}
		}
	}
	m--;
	for (; m >= 0; m--)
	{
		int cs = ldk[m].se;
		if (!ldk[m].fi)
		{
			int i = vt[cs].fi, j = vt[cs].se;
			s[i][j] = 0;
			for (int e = 0; e < 4; e++)
			{
				int ni = i + xx[e], nj = j + yy[e];
				if (ni >= 1 && ni <= n && nj >= 1 && nj <= n && !s[ni][nj])
				{
					merge(dd[i][j], dd[ni][nj]);
				}
			}
		}
		else
		{
			if (luu[cs].fi == -1) res[cs] = -1;
			else if (findpar(luu[cs].fi) == findpar(luu[cs].se)) res[cs] = dist(luu[cs].fi, luu[cs].se);
			else res[cs] = -1;
		}
	}
	//cout << numans << endl;
	for (int i = 1; i <= numans; i++) cout << res[i] << "\n";
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
