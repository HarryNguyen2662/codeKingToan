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
const long long nMOD = 166666668;
const long long nnMOD = 500000004;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long dp[1005][1005], luu[1005][1005], f[1005];

void solve() 
{
	int n, k;
	long long res = 0;
	cin >> n >> k;

	f[0] = 1;
	for(int i = 1; i <= n; i++) f[i] = (f[i-1]*10 + 1)%k;

	dp[0][0] = 1;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < k; j++)
	if (dp[i][j])
	for (int digit = (i == 0); digit <= 7; digit++)
	{
		int nj = (j + 1ll*digit*f[n-i-1]*(i + 1))%k;
		//int nj = (11*j + (i + 1)*digit)%k;
		dp[i+1][nj] += dp[i][j]; dp[i+1][nj] %= MOD;
	}


	for (int i = 0; i < k; i++)
	{
		if ((i + i + i)%k == 0)
		{
			res += 1ll*dp[n][i]*(dp[n][i] - 1)%MOD*(dp[n][i] - 2)%MOD*nMOD%MOD;
			res += MOD; res %= MOD;
		}

		int val = 1ll*dp[n][i]*(dp[n][i]-1)%MOD*nnMOD%MOD;

		if (((k - i - i)%k + k)%k < i)
		{
			res += 1ll*val*dp[n][((k - i - i)%k + k)%k]%MOD;
			res %= MOD;
		} 

		int w = (k - i)%k;
		for (int j = 0; j < i; j++)
		{
			res += 1ll*dp[n][i]*luu[j][w]%MOD;
			res %= MOD;

			luu[i][(i + j)%k] = (luu[i][(i + j)%k] + 1ll*dp[n][i]*dp[n][j]%MOD)%MOD;
		}

		luu[i][(i + i)%k] = (luu[i][(i + i)%k] + val)%MOD;
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
    //freopen("TUPLE.inp","r",stdin); freopen("TUPLE.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
