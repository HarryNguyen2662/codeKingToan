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
const long long MOD = 1e6 + 3;
const long long MOD1 = 998244353;
const long long MODo = 1e6 + 3;

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
int n;
int dp[2505][5055], a[1000005];
long long fact[2000005], infact[2000005];
long long C(int k, int nn)
{
	if (k > nn || k < 0 || nn < 0) return 0;
	return fact[nn]*infact[k]%MOD*infact[nn-k]%MOD;
}
long long power(long long val, long long cs)
{
	if (cs == 0) return 1;
	long long y = power(val, cs/2);
	if (cs%2) return y*y%MOD*val%MOD; else return y*y%MOD;
}
void sub1()
{
	int luu = 0;
	int lim = n + 5;
	for (int i = 1; i <= n; i++) if (a[i] > 0) 
	{
		luu = i; break;
	}
	//cout << luu << endl;
	dp[luu][0 + lim] = 1;
	int t = luu;
	for (int i = luu; i < n; i++)
	if (a[i + 1] == 0)
	{
		for (int j = max(a[luu] - n, 1); j <= a[luu] + n; j++)
		if (dp[i][j-a[luu]+lim] > 0)
		{	
			if (j > 1) dp[i+1][j-1-a[luu]+lim] += dp[i][j-a[luu]+lim], dp[i+1][j-1-a[luu]+lim] %= MODo;
			dp[i+1][j-a[luu]+lim] += dp[i][j-a[luu]+lim]; dp[i+1][j-a[luu]+lim] %= MODo;
			dp[i+1][j+1-a[luu]+lim] += dp[i][j-a[luu]+lim]; dp[i+1][j+1-a[luu]+lim] %= MODo;
		}
	}
	else if (abs(a[i+1] - a[luu]) <= n)
	{	
		if (a[i+1] > 1)
		dp[i+1][a[i+1]-a[luu]+lim] += dp[i][a[i+1]-1-a[luu]+lim], dp[i+1][a[i+1]-a[luu]+lim] %= MODo;
		dp[i+1][a[i+1]-a[luu]+lim] += dp[i][a[i+1]-a[luu]+lim];	dp[i+1][a[i+1]-a[luu]+lim] %= MODo;
		dp[i+1][a[i+1]-a[luu]+lim] += dp[i][a[i+1]+1-a[luu]+lim]; dp[i+1][a[i+1]-a[luu]+lim] %= MODo;
	}
	for (int i = luu; i > 1; i--)
	{
		for (int j = max(a[luu] - n, 1); j <= a[luu] + n; j++)
		if (dp[i][j-a[luu]+lim] > 0)
		{	
			if (j > 1) dp[i-1][j-1-a[luu]+lim] += dp[i][j-a[luu]+lim], dp[i-1][j-1-a[luu]+lim] %= MODo;
			dp[i-1][j-a[luu]+lim] += dp[i][j-a[luu]+lim]; dp[i-1][j-a[luu]+lim] %= MODo;
			dp[i-1][j+1-a[luu]+lim] += dp[i][j-a[luu]+lim]; dp[i-1][j+1-a[luu]+lim] %= MODo;
		}
	}
	long long res = 0, res1 = 0;
	for (int i = 0; i <= n + 1 + lim; i++) res += dp[1][i], res %= MODo, res1 += dp[n][i], res1 %= MODo;
	cout << res*res1%MODo;
}
void sub2()
{
	fact[0] = 1;
	for (int i = 1; i <= 1000000; i++) fact[i] = fact[i-1]*1ll*i%MOD;
	infact[1000000] = power(fact[1000000], MOD - 2);
	for (int i = 1000000; i; i--) infact[i-1] = infact[i]*1ll*i%MOD;
	//cout << C(1,2) << endl;
	vector<int> ldk;
	for (int i = 1; i <= n; i++) if (a[i] > 0)
	{
		ldk.pb(i);
	}
	long long res = 0, resres = 1;
	for (int i = 0; i < (int)ldk.size() - 1; i++) 
	{
		res = 0;
		int lim = ldk[i+1] - ldk[i] - 1;
		int val1 = a[ldk[i+1]] - a[ldk[i]], val2 = -a[ldk[i+1]] - a[ldk[i]];
		if (abs(a[ldk[i+1]] - a[ldk[i]]) <= ldk[i+1] - ldk[i] - 1)
		for (int j = 0; j <= lim; j++)
		{
			if (lim - j + val1 < 0 || (lim - j + val1)%2) continue;
			long long cur1 = C((lim - j + val1)/2, lim - j), cur2 = 0;
			if (lim - j + val2 >= 0 && (lim - j + val2)%2 == 0) cur2 = C((lim - j + val2)/2, lim - j);
			res = (res + C(j, lim)*(cur1 - cur2 + MOD)%MOD)%MOD;
		}
		val1 = a[ldk[i+1]]+1 - a[ldk[i]]; val2 = -a[ldk[i+1]]-1 - a[ldk[i]];
		if (abs(a[ldk[i+1]]+1 - a[ldk[i]]) <= ldk[i+1] - ldk[i] - 1)
		for (int j = 0; j <= lim; j++)
		{
			if (lim - j + val1 < 0 || (lim - j + val1)%2) continue;
			long long cur1 = C((lim - j + val1)/2, lim - j), cur2 = 0;
			if (lim - j + val2 >= 0 && (lim - j + val2)%2 == 0) cur2 = C((lim - j + val2)/2, lim - j);
			res = (res + C(j, lim)*(cur1 - cur2 + MOD)%MOD)%MOD;
		}
		if (a[ldk[i+1]] != 1)  {
		val1 = a[ldk[i+1]]-1 - a[ldk[i]]; val2 = -a[ldk[i+1]]+1 - a[ldk[i]];
		if (abs(a[ldk[i+1]] - 1 - a[ldk[i]]) <= ldk[i+1] - ldk[i] - 1)
		for (int j = 0; j <= lim; j++)
		{
			if (lim - j + val1 < 0 || (lim - j + val1)%2) continue;
			long long cur1 = C((lim - j + val1)/2, lim - j), cur2 = 0;
			if (lim - j + val2 >= 0 && (lim - j + val2)%2 == 0) cur2 = C((lim - j + val2)/2, lim - j);
			res = (res + C(j, lim)*(cur1 - cur2 + MOD)%MOD)%MOD;
		} }
		resres = resres*res%MOD;
	}
	for (int i = 1; i < ldk[0]; i++) resres = resres*3%MOD;
	for (int i = ldk.back() + 1; i <= n; i++) resres =resres*3%MOD;
	cout << resres;
}
void solve() 
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 2500) sub1(); else sub2();
}

int main() 
{   
	#ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
   	//freopen("ARRCNT.inp","r",stdin); freopen("ARRCNT.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}