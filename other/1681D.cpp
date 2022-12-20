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

long long dp[105][20][11];
void solve() 
{
	int n; 
	cin >> n;
	long long x;
	cin >> x;
	for (int t = 0; t <= 103; t++)
	for (int i = 0; i <= n; i++) 
	for (int w = 0; w <= 9; w++)
		dp[t][i][w] = -1;
	
	string ldk = to_string(x);
	int st = (int)ldk.size();
	for (int i = 0; i < st ; i++) dp[0][st][ldk[i] - '0'] = x;
	
	for (int i = 0; i <= 100; i++)
	for (int j = 1; j < n; j++)
	for (int w = 2; w <= 9; w++)
	if (dp[i][j][w] != -1)
	{
		long long newx = dp[i][j][w]*1ll*w;
		string ww = to_string(newx);
		int len = (int)ww.size();
		for (int e = 0; e < len; e++) dp[i+1][len][ww[e] - '0'] = max(dp[i+1][len][ww[e] - '0'], newx);
			
	}
	for (int i = 0; i <= 100; i++) for (int j = 0; j <= 9; j++) if (dp[i][n][j] != -1)
	{
		cout << i << " " << dp[i][n][j];
		return;
	}
	cout << -1;
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
