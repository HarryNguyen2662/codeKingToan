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
bool minimize(int &x, const int &y)
{
	if (y < x)
	{
		x = y;
		return true;
	}
	return false;
}
int dist[25][25], dp[1049000][25], trace[1049000][25];
void solve() 
{
	int n, m;
	cin >> n >> m;
	if (n == 1)
	{
		cout << "0\n";
		cout << "1";
		return;
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dist[i][j] = oo;
	for (int i = 1; i <= m; i++)
	{
		int u, v, val;
		cin >> u >> v >> val;
		dist[u][v] = min(dist[u][v], val);
	}
	for (int i = 0; i < mask(n); i++)
	for (int j = 1; j <= n; j++)
	dp[i][j] = oo, trace[i][j] = -1;
	dp[1][1] = 0;
	for (int i = 1; i < mask(n); i++)
	for (int e = 1; e <= n; e++)
	if (dp[i][e] < oo)
	{
		for (int  j = 1; j < n; j++) if (!ck(i, j))
		{
			if (minimize(dp[i^mask(j)][j+1], dp[i][e] + dist[e][j + 1]))
			trace[i^mask(j)][j+1] = e;
		}
	}
	int luu = -1;
	int res = oo;
	for (int i = 2; i <= n; i++) if (minimize(res, dp[mask(n)-1][i] + dist[i][1])) luu = i;
	cout << res << "\n";
	n = mask(n) - 1;
	vector<int> ldk;
	while (n > 0)
	{
		ldk.pb(luu);
		int t = trace[n][luu];
		n ^= mask(luu-1);
		luu = t;
	}
	reverse(ALL(ldk)); for (auto v : ldk) cout << v << " ";
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
