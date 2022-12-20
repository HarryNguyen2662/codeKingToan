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

long long u[1005][1005], l[1005][1005], r[1005][1005], c[1005], dp[1005][1005];
int p[1005];

long long dist(int ti, int st, int ed)
{
	if (st ==  ed) return 0;

	if (st < ed) return r[ti][ed-1] - r[ti][st-1];

	if (st > ed) return l[ti][ed + 1] - l[ti][st + 1];
}

void solve() 
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i < n; i++) for (int j = 1; j <= m; j++) cin >> u[i][j];

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 2; j <= m; j++) cin >> l[i][j];
		for (int j = m; j >= 1; j--) l[i][j] += l[i][j + 1];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++) 
		{
			cin >> r[i][j];
			r[i][j] += r[i][j-1];
		}
		r[i][m] += r[i][m-1];
	}

	for (int i = 1; i <= n; i++) cin >> p[i] >> c[i];

	for (int i = 1; i <= m; i++) dp[1][i] = min(dist(1, 1, i), dist(1, 1, p[1]) + dist(1, p[1], i) - c[1]) + u[1][i];	

	for (int i = 2; i <= n; i++)
	{
		long long cur = dp[i-1][1]; 
		long long cu = dp[i-1][1] + dist(i, 1, p[i]) - c[i];
		for (int j = 1; j <= m; j++)
		{
			cur = min(dp[i-1][j] - r[i][j-1], cur);
			cu = min(cu, dp[i-1][j] + dist(i, j, p[i]) - c[i]);

			dp[i][j] = cur + r[i][j-1];
		}

		cur = dp[i-1][m];

		for (int j = m; j; j--)
		{
			cur = min(dp[i-1][j] - l[i][j + 1], cur);

			dp[i][j] = min({dp[i][j], cur + l[i][j + 1], cu + dist(i, p[i], j)}) + u[i][j];
		}
	}


	cout << dp[n][m];
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
