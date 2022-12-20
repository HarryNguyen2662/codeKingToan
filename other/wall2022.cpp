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

map<int,int> dd;
int a[5005], dp[5005][5005], mn[5005][5005], pre[5005];

void solve() 
{	
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pre[i] = dd[a[i]];
		dd[a[i]] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		dd[a[i]] = 0;
	}


	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) dp[i][j] = mn[i][j] = oo;

	dp[0][0] = 0; mn[0][0] = 0;
	int ans = oo;

	for (int i = 1; i <= n; i++)
	{ 
		for (int j = 0; j <= k; j++)		
		{
			dp[i][j] = min (dp[i][j], dp[pre[i]][j] + (i - pre[i] - 1));
			if (j)
			dp[i][j] = min(dp[i][j], mn[i-1][j-1] + i - 1);
			mn[i][j] = min(mn[i-1][j], dp[i][j] - i);
			ans = min(ans, dp[i][j] + (n - i));
		}
	}

	cout << ans << "\n";

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
