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

int dp[52][5002][52];

void solve() 
{	
	int n, k;
	
	cin >> n >> k;

	int su = n*n;

	dp[0][su][0] = 1;

	for (int i = 0; i < n; i++)
	for (int j = 0; j <= 2*su; j++)
	for (int e = 0; e <= min(i, n - i); e++)
	if (dp[i][j][e])
	{
		if (j + 2*(i + 1) <= 2*su && e)
 		{
			dp[i + 1][j + 2*(i + 1)][e - 1] += 1ll *e*e%MOD*dp[i][j][e]%MOD;
			dp[i + 1][j + 2*(i + 1)][e - 1]  %= MOD;
		}

		if (e && e <= min(i + 1, n - i - 1))
		{
			dp[i + 1][j][e] += 2ll*e*dp[i][j][e]%MOD; dp[i + 1][j][e] %= MOD;
		}

		if (e <= min(i + 1, n - i - 1))
		dp[i + 1][j][e] += dp[i][j][e]; dp[i + 1][j][e] %= MOD;

		if (j - 2*(i + 1) >= 0 && e + 1 <= min(i + 1, n - i - 1))
		{
			dp[i + 1][j - 2*(i + 1)][e+1] += dp[i][j][e];
			dp[i + 1][j - 2*(i + 1)][e+1] %= MOD;
		}

	}
	

	cout << dp[n][k + su][0];
}	

int main() 
{   
    //#ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
