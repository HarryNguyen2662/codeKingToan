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
const long long lim = 4e18 + 5;
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
bool cam[105][105], pick[105];
int n, m, luu[105];
long long k, dp[105], dem = 0, f[21][1050000];
void sub1(int i, int old)
{
	if (i == n + 1)
	{
		dem++;
		if (dem == k)
		{
			for (int j = 1; j <= n; j++) cout << luu[j] << " ";
			exit(0);
		}
		return;
	}
	for (int j = 1; j <= n; j++) if (!pick[j] && !cam[old][j]) 
	{
		pick[j] = true;
		luu[i] = j;
		sub1(i + 1, j);
		pick[j] = false;
	}
}
void sub2()
{
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i-1] > lim/i) dp[i] = lim + 5; else dp[i] = dp[i-1]*1ll*i;
	}
	for (int i = 1; i <= n; i++)
	{
		int cur;
		for (int j = 1; j <= n; j++)
		if (pick[j] == false)
		{	
			cur = j;
			if (k > dp[n - i])
			{
				k -= dp[n - i];
			}
			else break;
		}
		pick[cur] =  true;
		cout << cur << " "; 
	}
}
void sub3()
{
	for (int i = 0; i < n; i++) f[i][mask(n)-1] = 1;
	for (int i = mask(n) - 2; i > 0; i--)
	for (int j = i; j > 0; j ^= (j&(-j)))
	{
		int id1 = __builtin_ctz(j&(-j));
		for (int e = mask(n) - 1 - i; e > 0; e ^= (e&(-e)))
		{
			int id2 = __builtin_ctz(e&(-e));
			if (!cam[id1+1][id2+1]) 
			{
				if (f[id1][i] <= lim - f[id2][i|mask(id2)]) f[id1][i] += f[id2][i|mask(id2)];
			}
		}
	}
	//cout << f[0][1] << endl;
	int old = 0;
	int mk = 0;
	for (int i = 1; i <= n; i++)
	{
		int id = 0;
		for (int j = 0; j < n; j++)
		if (!cam[old][j+1] && !ck(mk, j))
		{
			if (k > f[j][mk|mask(j)])
			{
				k -= f[j][mk|mask(j)];
			}
			else 
			{
				id = j;
				break;
			}
		}
		cout << id + 1 << " ";
		old = id + 1;
		mk |= mask(id);
	}
}
void solve() 
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		cam[u][v] = cam[v][u] = true;
	}
	if (n <= 20) sub3();
	else if (m == 0) sub2();
	else if (k <= 100000) sub1(1, 0);
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
