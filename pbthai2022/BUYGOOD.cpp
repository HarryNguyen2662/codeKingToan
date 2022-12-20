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

long long dp[105][10005];

void solve() 
{
	int n, m;

	cin >> n >> m;
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++) dp[i][j] = oo15;

	dp[0][0] = 0;
	for (int i = 1; i <= m; i++)
	{
		int s, p, w;
		cin >> s >> p >> w;

		multiset<long long> ss;

		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = min(dp[i][j], dp[i-1][j]);
			ss.insert(dp[i-1][j] - 1ll*j*p);
			if (j > s)
			{
				ss.erase(ss.find(dp[i-1][j-s-1] - 1ll*(j - s - 1)*p));
			}
			if ((int)ss.size())
			{
				dp[i][j] = min(dp[i][j], *ss.begin() + 1ll*j*p + w);
			}
		}
	}
	cout << dp[m][n];
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
