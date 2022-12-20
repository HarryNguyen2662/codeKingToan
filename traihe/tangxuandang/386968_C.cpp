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

char s[3005];
long long dp[3005][3005], dpp[3005][3005], hv[3005];
void solve() 
{
	int n;
	cin >> n;
	hv[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		hv[i] = hv[i-1]*1ll*i%MOD;
		cin >> s[i];
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i ++)
	for (int j = 0 ; j <= n; j++)
	if (dp[i][j])
	{	
		if (s[i+1] == '>')
		{
			(dp[i+1][j+1] += dp[i][j])%=MOD;
			(dp[i+1][j] += dp[i][j]*1ll*j%MOD)%=MOD;
		}
		else
		{
			if (j)
			(dp[i+1][j-1] += dp[i][j]*1ll*(j)%MOD*1ll*(j-1)%MOD)%=MOD;
			(dp[i+1][j] += dp[i][j]*1ll*j%MOD)%=MOD;
		}
	}
	dpp[n+1][0] = 1;
	for (int i = n+1; i > 1; i--)
	for (int j = 0 ; j <= n; j++)
	if (dpp[i][j])
	{	
		if (s[i-1] == '<')
		{
			(dpp[i-1][j+1] += dpp[i][j])%=MOD;
			(dpp[i-1][j] += dpp[i][j]*1ll*j%MOD)%=MOD;
		}
		else
		{
			if (j)
			(dpp[i-1][j-1] += dpp[i][j]*1ll*(j)%MOD*1ll*(j-1)%MOD)%=MOD;
			(dpp[i-1][j] += dpp[i][j]*1ll*j%MOD)%=MOD;
		}
	}
	//cout << dpp[3][0] << endl;
	for (int i = 1; i <= n; i++)
	{
		long long res = 0;
		for (int j = 1; j <= n; j++)
		{ 
			//(res += dpp[i+1][j])%MOD;
			(res += dp[i-1][j]*dpp[i+1][j]%MOD*2%MOD*hv[j]%MOD*hv[j]%MOD)%=MOD;
			(res += dp[i-1][j-1]*dpp[i+1][j]%MOD*hv[j-1]%MOD*hv[j]%MOD)%=MOD;
			(res += dp[i-1][j]*dpp[i+1][j-1]%MOD*hv[j-1]%MOD*hv[j]%MOD)%=MOD;
		}
		cout << res << " ";
	}
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
