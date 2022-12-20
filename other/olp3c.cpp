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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long power(long long a, long long b)
{
	if (b == 0) return 1;
	long long x = power(a, b/2);
	if (b%2) return x*x%MOD*a%MOD; else return x*x%MOD;
}
long long dp[605][605], dt[605];
void solve() 
{
	int n, t, a, b;
	
	cin >> n >> t >> a >> b;
	b += a;

	long long res = 1;
	
	dt[0] = 1;
	for (int i = 1; i <= max(n, t); i++) 
	{
		if (i <= n)
		res = res*1ll*i%MOD;
		if (i <= t)
		res = res*1ll*i%MOD;
		dt[i] = dt[i-1]*power(i, MOD - 2)%MOD;
	}
		
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	for (int j = 0; j <= t; j++)
	if (dp[i][j])
	{
		int st = 0;
		if (i+1 <= a) st = 1; else if (i + 1 <= b) st = 2; 
		for (int e = st; j + e <= t; e += 3)
		dp[i+1][j + e] = (dp[i+1][j + e] + dt[e]*dp[i][j]%MOD)%MOD;	
	}
	cout << res*dp[n][t]%MOD*dt[a]%MOD*dt[b-a]%MOD*dt[n-b]%MOD;
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
