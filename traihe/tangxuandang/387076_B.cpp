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
	long long aa = power(a, b/2);
	if (b%2) return aa*aa%MOD*a%MOD; else return aa*aa%MOD;
}

long long dp[55][10005], infact[55];
int m;

long long f(long long x, int mu)
{
	x %= MOD;

	for (int i = 0; i <= mu; i++)
	for (int j = 0; j <= m; j++) dp[i][j] = 0;

	dp[mu][0] = 1;

	for (int j = 0; j < m; j++)
	for (int i = 0; i <= mu; i++)
	if (dp[i][j] > 0)
	{
		for (int e = 0; e <= i; e++)
		{
			dp[e][j + 1] = (dp[e][j + 1] + dp[i][j]*infact[i+1]%MOD)%MOD;
		}
	}

	long long res = 0;
	long long tu = 1;
	for (int i = 0; i <= mu; i++)
	{
		res = (res + dp[i][m]*tu%MOD)%MOD;
		tu = tu*x%MOD;
	}
	return res;
}

void solve() 
{
	long long n; 
	vector<pair<long long, int>> ldk;
	cin >> n >> m; m;	
	
	for (int i = 2; 1ll*i*i <= n; i++)
	if (n%i == 0)
	{
		int dem = 0;
		while(n%i == 0)
		{
			dem++;
			n /= i;
		}
		ldk.pb({i, dem});
	}
	if (n != 1)
	{
		ldk.pb({n, 1});
	}

	infact[0] = 1;
	
	for (int i = 1; i <= 53; i++) infact[i] = power(i, MOD-2)%MOD; 

	long long res = 1;
	
	for (auto v : ldk)
	{
		long long w =  f(v.fi, v.se);
		res = res*w%MOD;
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
