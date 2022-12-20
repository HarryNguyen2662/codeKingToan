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
const int lim = 100000;
inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}
long long power(long long x, int n)
{
	if (n == 0) return 1;
	long long y = power(x, n/2);
	if (n%2) return y*y%MOD*x%MOD; else return y*y%MOD;
}
void WriteInt(int x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int dem[100005];
long long dp[100005], dpp[100005];
void solve()
{
	int n;
	long long sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		int val;
		cin >> val;
		dem[val]++;
	}
	for (int i = 1; i <= lim; i++)
	{
		long long sum = 0;
		long long sum1 = 0;
		int w = 0;
		for (int j = i; j <= lim; j += i)
		{
			w += dem[j];
			sum += 1ll*dem[j]*j%MOD; sum %= MOD;
			sum1 += 1ll*dem[j]*j%MOD*1ll*j%MOD; sum1 %= MOD;
		}
		if (w < 2) continue;
		dp[i] = sum*sum%MOD - sum1 + MOD; dp[i] %= MOD;
	}
	//cout << endl;
	//cout << dp[1] << endl;
	long long res = 0;
	for (int i = lim; i; i--)
	{
		for (int j = 2*i; j  <= lim; j += i)
		{
			dp[i] = dp[i] - dp[j] + MOD; dp[i] %= MOD;
		}

		//cout << dp[i] << " " << dpp[i] << endl;
		long long val = dp[i];
		val %= MOD;
		//cout << val << endl;
		res += 1ll*val*power(2*i, MOD - 2);
		res %= MOD;
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

