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

int dp[50][30][30][30][30];

void solve() 
{
	string s;
	cin >> s;
	s = "@" + s;

	dp[0][0][0][0][0] = 1;

	for (int i = 0; i < 48; i++)
	for (int l = 0; l <= 25; l++)
	for (int r = 0; r <= 25; r++)
	for (int u = 0; u <= 25; u++)
	for (int d = 0; d <= 25; d++)
	if (dp[i][l][r][u][d])
	{
		cout << i << " " << l << " " << r << " " << u << " " << d << " " << dp[i][l][r][u][d] << endl;
		if (s[i+1] == 'L' && l + 1 - r <= 0)
		{
			dp[i + 1][l + 1][r][u][d] += dp[i][l][r][u][d];
		}
		else if (s[i+1] == 'R' && r + 1 - l <= 6)
		{
			dp[i+1][l][r + 1][u][d] += dp[i][l][r][u][d];
		}
		else if (s[i+1] == 'U' &&  u + 1 - d <= 0)
		{
			dp[i+1][l][r][u + 1][d] += dp[i][l][r][u][d];
		}
		else if (s[i+1] == 'D' && d + 1 - u <= 6)
		{
			dp[i+1][l][r][u][d + 1] += dp[i][l][r][u][d];
		}
		else
		{
			if ( l + 1 - r <= 0)
			{
				dp[i + 1][l + 1][r][u][d] += dp[i][l][r][u][d];
			}
			if (r + 1 - l <= 6)
			{
				dp[i+1][l][r + 1][u][d] += dp[i][l][r][u][d];
			}
			if (  u + 1 - d <= 0)
			{
				dp[i+1][l][r][u + 1][d] += dp[i][l][r][u][d];
			}
			if ( d + 1 - u <= 6)
			{
				dp[i+1][l][r][u][d + 1] += dp[i][l][r][u][d];
			}
		}
	}

	long long res = 0;
	for (int i = 0; i <= 25; i++) for (int j = 6; j <= 25; j++) res = res + dp[48][i][i][j - 6][j];
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
