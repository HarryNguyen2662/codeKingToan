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
vector<pair<int,int>> a[105], aa[105];
bool d[105][10005], dd[105][10005];
void dfs(int u, int len)
{
	d[u][len] = true;
	for (auto v : a[u]) if (d[v.fi][len + v.se] == false)
	{
		dfs(v.fi, len + v.se);
	}
}
void dfs1(int u, int len)
{
	dd[u][len] = true;
	for (auto v : aa[u]) if (dd[v.fi][len + v.se] == false)
	{
		dfs1(v.fi, len + v.se);
	}
}
void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w1, w2;
		cin >> u >> v >> w1 >> w2;
		a[u].pb({v, w1}); aa[u].pb({v, w2});
	}
	dfs(1, 0); dfs1(1, 0);
	for (int i = 0; i <= 10000; i++) if (d[n][i] && dd[n][i])
	{
		cout << i ;
		return;
	}
	cout << "IMPOSSIBLE";
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
