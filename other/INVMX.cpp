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
long long dp[200005][105], f[200005][105], cost[200005], dem[200005][105], de[105], dm[200005][105];
void solve() 
{
	int n, k, cnt = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		if (val == 0)
		{
			cnt++;
			cost[cnt] = cost[cnt-1];
			for (int j = 1; j <= k; j++) dem[cnt][j] = dem[cnt-1][j], dm[cnt][j] = dm[cnt-1][j];
		}
		else
		{
			dem[cnt][val]++;
			dm[cnt][val]++;
			de[val]++;
			for (int j = val + 1; j <= k; j++) 
			{
				cost[cnt] += de[j];
				dem[cnt][j]++;
			}
			for (int j = val - 1; j >= 1; j--)
			{
				dm[cnt][j]++;
			}
		}
	}
//	cout << dem[2][7] << endl;
//	cout << cost[2] -cost[1] << endl;
	for (int i = 1; i < cnt; i++)
	{
		for (int j = k; j ; j--)
		{
			long long cur = 0;
			for (int e = i; e >= 1; e--)
			{
				dp[i][j] = max(dp[i][j], f[e-1][j+1] + cur + 1ll*(e-1)*(dem[i][j] - dem[e-1][j] + i - e + 1) + cost[i] - cost[e-1]);
				cur += dem[i][j-1] - dem[e-1][j-1];
			}
			f[i][j] = max(f[i][j+1], dp[i][j]);
		}
	}
	cout << dp[2][1] << endl;
	long long res = 0;
	for (int j = k; j; j--)
	{
		long long cur = 0;
		for (int e = cnt; e >= 1; e--)
		{
			res = max(res, f[e-1][j+1] + cur + 1ll*(e-1)*(dem[cnt][j] - dem[e-1][j] + cnt - e ) + cost[cnt] - cost[e-1]);
			cur += dem[cnt][j-1] - dem[e-1][j-1];
		}
	}
	cout << res;
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
