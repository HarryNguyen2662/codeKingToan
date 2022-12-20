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
const long long oo12 = 1e12;
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
int n, m, q, dist[1505][1505], id[20];
bool uu[1505];
long long kc[1505][1505][2], dp[131075][17][17];
void dij(int u)
{
	for (int i = 1; i <= n; i++) kc[u][i][0] = kc[u][i][1] = oo12, uu[i] = false;
	kc[u][u][0] = kc[u][u][1] = 0;
	
	for(int i = 1; i <= n; i++)
	{
		int v = -1;
		for (int j = 1; j <= n; j++)
		if (!uu[j] && (v == -1 || kc[u][j][0] < kc[u][v][0])) v = j;
		if (kc[u][v][0] == oo12) break;
		uu[v] = true;
		for (int j = 1; j <= n; j++)
		if (kc[u][j][0] > kc[u][v][0] + dist[v][j])
		{
			kc[u][j][0] = kc[u][v][0] + dist[v][j];
		}
	}
	for (int i = 1; i <= n; i++) uu[i] = false;
	for(int i = 1; i <= n; i++)
	{
		int v = -1;
		for (int j = 1; j <= n; j++)
		if (!uu[j] && (v == -1 || kc[u][j][1] < kc[u][v][1])) v = j;
		if (kc[u][v][1] == oo12) break;
		uu[v] = true;
		for (int j = 1; j <= n; j++)
		if (kc[u][j][1] > kc[u][v][1] + dist[j][v])
		{
			kc[u][j][1] = kc[u][v][1] + dist[j][v];
		}
	}
}
void solve() 
{
	
	cin >> n >> m >> q;
	for (int i = 0 ; i < m; i ++) cin >> id[i];
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		cin >> dist[i][j];

	//dij(1);
	for (int i = 0; i < m; i++)
	{
		dij(id[i]);

	}
	//cout << kc[1][3][0] << endl;
	for (int i = 0; i < mask(m); i++) for (int j = 0; j < m; j++) for (int e = 0; e < m; e++)
	dp[i][j][e] = oo12;
	for (int i = 0; i < m; i++)
	{
		dp[mask(i)][i][i] = 0; 
		for (int msk = mask(i); msk < mask(m); msk++)
		for (int j = 0; j < m; j++)
		if (dp[msk][i][j] != oo12)
		{
			for(int e = 0; e < m; e++)
			if (!ck(msk, e))
			{
				int nmsk = (msk^mask(e));
				dp[nmsk][i][e] = min(dp[nmsk][i][e], dp[msk][i][j] + kc[id[j]][id[e]][0]);
			}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int u, v;
		cin >> u >> v;
		long long res = oo12;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				res = min(res, dp[mask(m)-1][i][j] + kc[id[i]][u][1] + kc[id[j]][v][0]);
		cout << res << " ";
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
