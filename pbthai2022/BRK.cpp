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

long long dp[2005][2005];
int w[2005], n;
int b[2005];

int ck1(int x, int y)
{
	return (x/w[y])%4;
}

long long cal(int k)
{
	if (k <= 0) return 0;

	for (int i = 0; i <= n; i++) for (int j = 0 ; j <= 1024; j ++) dp[i][j] = 0;

	dp[0][0] = 1;

	for (int i = 0; i < n; i++)
	for (int j = 0; j <= 1024; j++)
	if (dp[i][j])
	{
		int id = k + 1;
		for (int e = 1; e <= k; e++) if (!ck1(j, e)) 
		{
			id = e; break;
		}
		if (b[i + 1] == 0)
		{
			for (int q = 1; q <= 3; q++)
			{
				if (id <= k)
				{	
					dp[i + 1][j + q*w[id]] += dp[i][j];
					dp[i + 1][j + q*w[id]] %= MOD;
				}
				if (id > 1 && ck1(j, id - 1) == q)
				{
					dp[i + 1][j -q*w[id - 1]] += dp[i][j];
					dp[i + 1][j -q*w[id - 1]] %= MOD;
				}
			}
		}
		else
		if (b[i + 1] > 0)
		{
			if (id <= k)
			{	
				dp[i + 1][j + b[i + 1]*w[id]] += dp[i][j];
				dp[i + 1][j + b[i + 1]*w[id]] %= MOD;
			}
		}
		else 
		{
			if (id > 1 && ck1(j, id - 1) == -b[i + 1])
			{
				dp[i + 1][j + b[i + 1]*w[id - 1]] += dp[i][j];
				dp[i + 1][j + b[i + 1]*w[id - 1]] %= MOD;
			}
		}
	}

	return dp[n][0];
}

void solve() 
{
	int k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) 
	{
		char x; cin >> x; 
		if (x == '(') b[i] = 1;
		if (x == '[') b[i] = 2;
		if (x == '{') b[i] = 3;
		if (x == ')') b[i] = -1;
		if (x == ']') b[i] = -2;
		if (x == '}') b[i] = -3;
		if (x == '?') b[i] = 0;
	}

	w[1] = 1;
	for (int i = 2; i <= k; i++) w[i] = w[i-1]*4;


	cout << (cal(k) - cal(k - 1) + MOD)%MOD;
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
