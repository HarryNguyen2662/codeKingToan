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

long long dp[505][505], f[505][505];

bool ck[505];

void solve() 
{
	string s, t;
	cin >> s >> t;
	int n = (int)s.size(), m = (int)t.size();
	s = "@" + s; t = "@" + t; 

	for (int i = 1;i <= n; i++) ck[i] = false;
	for (int i = m; i <= n; i++)
	{
		ck[i] = true;
		for (int j = 1; j <= m; j++)
		if (t[j] != s[i - m + j])

		{
			ck[i] = false;
			break;
		}	
	}
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= n/m +1; j++) dp[i][j] = f[i][j] = 0;

	dp[0][0] = 1;

	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= n/m +1; j++)
	{
		if (!ck[i]) f[i][j] = (dp[i-1][j] + f[i-1][j])%MOD;
		else if (j)
		{
			dp[i][j] = (dp[i-m][j-1] + f[i - m][j - 1])%MOD;
			for (int e = i - 1; e >= i - m + 1; e--) if (ck[e])
			{
				f[i][j] += dp[e][j];
				f[i][j] %= MOD;
			}
		}
	}


	for (int i = 0; i <= n/m + 1; i++)
	if (dp[n][i] + f[n][i] > 0)
	{
		cout << i << " " << (dp[n][i] + f[n][i])%MOD << "\n"; return;
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
    cin >> testcase;
    while(testcase--)
        solve();
}
