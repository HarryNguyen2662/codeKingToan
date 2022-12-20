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

long long dp[10001][10001];
int n, m;
int a[1000005], b[1000005];
void trau1()
{
	//cout << n*m << endl;
	for (int i = 0; i <= n*m; i++) for (int j = 0; j <= n*m; j++) dp[i][j] = oo18;
	dp[0][0] = 0;
	for (int i = 1; i <= n*m; i++)
 	for (int j = 0; j <= n*m/2; j++)
	{
		if (j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + a[(i-1)%n]);
		dp[i][j] = min(dp[i][j], dp[i-1][j+1] + b[(i-1)%n]);
	}
	cout << dp[n*m][0];
}
void trau2()
{
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = oo18;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
 	for (int j = 0; j <= n/2; j++)
	{
		if (j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + a[(i-1)%n]);
		dp[i][j] = min(dp[i][j], dp[i-1][j+1] + b[(i-1)%n]);
	}
	cout << dp[n][0]*m;
}
void solve() 
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < n; j++) cin >> b[j];
	if (1ll*n*m <= 10000) trau1();
	else if (n == 1)
	{
		cout << 1ll*(m/2)*a[0] + 1ll*(m/2)*b[0];
	}
	else if (n <= 10000)
	{
		trau2();
	}
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
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
