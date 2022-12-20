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
const long long MODo = 1e9 + 19972207;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long dp[1000005][2][2];

void solve() 
{
	int dem = 0;
	string s, st;
	cin >> s >> st;
	int n = (int)s.size();
		
	dp[0][0][0] = 1;

	for (int i = 0; i < n; i++)
	for (int t = 0 ; t < 2; t++)
	for (int tt = 0; tt < 2; tt++)
	if (dp[i][t][tt])
	{
		if (s[i] == '?' && st[i] == '?')
		{
			(dp[i + 1][t][tt] += 10ll*dp[i][t][tt]) %= MODo;
			(dp[i + 1][1][tt] += 45ll*dp[i][t][tt]) %= MODo;
			(dp[i + 1][t][1] += 45ll*dp[i][t][tt]) %= MODo;

		}
		else if (s[i] != '?' && st[i] != '?')
		{
			(dp[i + 1][max(t, (int)(s[i] > st[i]))][max(tt, (int)(st[i] > s[i]))] += dp[i][t][tt])%=MODo;
		}
		else if (s[i] == '?')
		{
			(dp[i + 1][t][tt] += dp[i][t][tt]) %= MODo;
			(dp[i + 1][1][tt] += 1ll*(9 - st[i] + '0')*dp[i][t][tt]) %= MODo;
			(dp[i + 1][t][1] += 1ll*(st[i] - '0')*dp[i][t][tt]) %= MODo;
		}
		else if (st[i] == '?')
		{
			(dp[i + 1][t][tt] += dp[i][t][tt]) %= MODo;
			(dp[i + 1][t][1] += 1ll*(9 - s[i] + '0')*dp[i][t][tt]) %= MODo;
			(dp[i + 1][1][tt] += 1ll*(s[i] - '0')*dp[i][t][tt]) %= MODo;
		}
	}
	cout << dp[n][1][1];
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("brentford40mu.inp","r",stdin); freopen("brentford40mu.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
