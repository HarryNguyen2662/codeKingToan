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

int a[100005];
pair<int,int> dp[100005][2];


void solve() 
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) for (int j = 0; j < 2; j ++) dp[i][j] = {oo, 0};

	if (a[1] == 0 || a[1] == 1)
	{
		dp[1][0] = {1, -1};
	}
	if (a[1] == 0 || a[1] == 2)
	{
		dp[1][1] = {1, -1};
	}
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 2; j ++)
		if (dp[i-1][j].fi < oo && -dp[i-1][j].se + k > i)
		{
			if (a[i] != 0 && a[i] == 1 && j != 0)
			{
				dp[min(n, -dp[i-1][j].se + k - 1)][0] = min(dp[min(n, -dp[i-1][j].se + k - 1)][0], {dp[i-1][j].fi + 1, -i});
			}
			if (a[i] != 0 && a[i] == 2 && j != 1)
			{
				dp[min(n, -dp[i-1][j].se + k - 1)][1] = min(dp[min(n, -dp[i-1][j].se + k - 1)][1], {dp[i-1][j].fi + 1, -i});
			}
			if ((a[i] == 0 || a[i] == j + 1))
			{
				dp[i][j] = min(dp[i][j], dp[i-1][j]);
			}
		}
		else if (dp[i-1][j].fi < oo && -dp[i-1][j].se + k == i)
		{
			if (a[i] == 0 || a[i] == 1)
			{
				dp[i][0] = min(dp[i][0], {dp[i-1][j].fi + 1, -i});
			}
			if (a[i] == 0 || a[i] == 2)
			{
				dp[i][1] = min(dp[i][1], {dp[i-1][j].fi + 1, -i});
			}
		}
	}

	cout << min(dp[n][0].fi, dp[n][1].fi);
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
