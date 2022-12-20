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

long long power(long long a, long long b)
{
	if (b == 0) return 1;
	long long x = power(a, b/2);
	if (b%2) return x*x%MOD*a%MOD; else return x*x%MOD;
}

long long dp[10][100], fact[100], infact[100], lt[100];
int sl[10];

long long c(int k, int n)
{
	return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}
void solve() 
{
	int n = 9;
	for (int i = 1; i <= 9; i ++) cin >> sl[i];

	long long res = 0;
	for (int i = 1; i <= 9; i++) if (sl[i] > 0)
	{
		sl[i]--;
		for (int e = 0; e <= n; e++) for (int j = 0; j <= 81; j++) dp[e][j] = 0;
		dp[0][0] = 1;
		for (int e = 0; e < n; e++) for (int j = 0; j <= 81; j++)
		if (dp[e][j] > 0)
		{
			for (int w = 0; w <= sl[e+1]; w++) 
			dp[e+1][j + w] += dp[e][j]*c(w, j + w)%MOD, dp[e+1][j+w] %= MOD;
		}
		//cout << dp[9][1] << endl;
		long long re = 0;
		for (int e = 81; e >= 0; e--)
		{
			re = re + dp[n][e]; re %= MOD;
			res = res + re*lt[e]%MOD*1ll*i%MOD;
			res %= MOD;
		}
		sl[i]++;
	}
	cout << res << "\n";
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
    lt[0] = fact[0] = 1;
    for (int i = 1; i <= 81; i++)
    {
    	lt[i] = lt[i-1]*10%MOD;
    	fact[i] = fact[i-1]*1ll*i%MOD;
    }
    infact[81] = power(fact[81], MOD - 2);
    for (int i = 81; i >= 1; i--) infact[i-1] = infact[i]*1ll*i%MOD;
    cin >> testcase;
    while(testcase--)
        solve();
}
