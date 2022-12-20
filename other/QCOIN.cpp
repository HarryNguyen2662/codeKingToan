#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}
void WriteInt(int x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
void add(int &x, const int &y)
{
	x += y;
	if (x >= MOD) x -= MOD;
}
int dp[6005][6005];
int w[6005];
pair<int,int> a[6005];
bool cmp(const pair<int,int> &x, const pair<int,int> &y)
{
	if (x.se != y.se)
	return x.se > y.se;
	return x.fi > y.fi;
}
void solve()
{
	int n, sum;
	cin >> n >> sum;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i].fi >> a[i].se; 
	}
	int res =0;
	int cnt = 0;
	for (int i = 1; i <= sum; i++) if (sum%i == 0) w[++cnt] = i; 
	for (int e = 1; e <= cnt; e++)
	{
		int ww = sum/w[e];
		dp[0][0] = 1;
		for (int i = 0; i < n; i++)
		for (int j = 0 ; j <= ww; j++)
		if (dp[i][j] > 0)
		{
			add(dp[i+1][j], dp[i][j]);
			if (j + a[i +1].se <= ww && a[i+1].fi >= w[e]) add(dp[i+1][j + a[i+1].se], dp[i][j]);
		}
		add(res, dp[n][ww]);
		for (int i = 0; i <= n; i++) for (int j = 0; j <= ww; j++) dp[i][j] = 0;
	}
	WriteInt(res);
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
