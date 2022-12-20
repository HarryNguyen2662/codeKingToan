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

ll g[1505], f[1505], cost[1505][1505], dp[1505][1505];

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		f[i] = oo18;
		for (int j = 1; j <= n; j++) 
		{
			dp[i][j] = oo18;
			cin >> cost[i][j];
		}
		g[i] = g[i-1] + cost[i-1][i];
	}
	if (n == 1)
	{
		cout << "0\n"; return;
	}

	f[1] = cost[1][2]; dp[1][1] = 0;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i - 1; j++) 
		{
			dp[i][i-1] = min(dp[i][i-1], g[i-1] - g[j + 1] + f[j] + cost[i][j]);
			dp[i][j] = min(dp[i][j], dp[i-1][j] + cost[i][i-1]);
		}
		dp[i][i-1] = min(dp[i][i-1], dp[i-1][i-1] + cost[i][i-1]);

		for (int j = 1; j <= i - 1; j++)
		if (dp[i][j] < oo18)
		{
			f[i] = min(f[i], dp[i][j] + cost[j][i + 1]);
		}
	}

	ll ans = g[n];

	for (int j = 1; j < n; j++)
	{
		ans = min(ans, f[j] + g[n] - g[j + 1]);
		ans = min(ans, dp[n][j]);
	}

	cout << ans;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("putnik.inp","r",stdin); freopen("putnik.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
	