#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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


long long c[2005][2005], dp[2005][2005];

void solve() 
{
	int n, x, y;
	cin >> n >> x >> y;

	for (int i = 0; i <= n; i++) c[0][i] = 1;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) c[i][j] = (c[i][j-1] + c[i-1][j-1])%MOD;

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= min(max(x, y), i); j++)
	{
		dp[i][j] = (1ll*(i - 1)*dp[i-1][j] + dp[i-1][j-1])%MOD;
	} 

	long long res = 0;

	for (int i = x; i <= n - y + 1; i++)
	{
		//cout << c[i-1][n-1] << endl;
		res = res + 1ll*dp[i - 1][x-1]*dp[n - i][y-1]%MOD*c[i - 1][n-1]%MOD;
		res %= MOD;
	}

	cout << res;
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    // //
    freopen("LINEUP.inp","r",stdin); freopen("LINEUP.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}