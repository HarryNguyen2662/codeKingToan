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

int a[305];
long long dp[305][305][305];
void solve() 
{	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for (int j = 2; 1ll*j*j <= a[i]; j++)
		{
			while(a[i]%(j*j) == 0)
			{
				a[i] /= (j*j);
			}
		}
	}
	sort(a + 1, a + 1 + n);

	dp[1][0][0] = 1;
	int sl = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		for (int e = 0; e + j < i; e++)
		if (a[i] != a[i + 1])
		{
			if (j) dp[i + 1][j + e - 1][0] = (dp[i + 1][j + e - 1][0] + dp[i][j][e]*1ll*j%MOD)%MOD;
			if (e) dp[i + 1][j + e - 1][0] = (dp[i + 1][j + e - 1][0] + dp[i][j][e]*1ll*e%MOD)%MOD;
			dp[i + 1][j + e][0] = (dp[i + 1][j + e][0] + dp[i][j][e]*1ll*(i + 1 - j - e)%MOD)%MOD;
		}
		else
		{
			if (j) dp[i + 1][j - 1][e] = (dp[i][j - 1][e] + dp[i][j][e]*1ll*j%MOD)%MOD;
			dp[i + 1][j][e + 1] = (dp[i + 1][j][e + 1] + dp[i][j][e]*1ll*(2*sl - e)%MOD)%MOD;
			dp[i + 1][j][e] = (dp[i + 1][j][e] + dp[i][j][e]*1ll*(i + 1 - j - 2*sl + e)%MOD)%MOD;
		}
		cout << a[i] << endl;
		if (a[i] == a[i + 1]) sl++; else sl = 1;
	}
	cout << dp[n][0][0];
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
