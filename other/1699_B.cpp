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

int dp[55][55];
void solve() 
{
	int n, m;
	cin >> n >> m;
	dp[1][1] = 1; 
	for (int i = 2; i <= m; i++)
	if (i%2 == 0) dp[1][i] = 1 - dp[1][i-1]; else dp[1][i] = dp[1][i-1];
	for (int i = 2; i <= n; i++)
	{
		if (i%2 == 0) dp[i][1] = 1 - dp[i-1][1]; else dp[i][1] = dp[i-1][1];
		for (int j = 2; j <= m; j++)
		if (j%2 == 0) dp[i][j] = 1 - dp[i][j-1]; else dp[i][j] = dp[i][j-1];
	}

	for (int i =1 ; i <= n; i++) 
	{
		for (int j = 1; j <= m; j++) cout << dp[i][j] << " ";
		cout << "\n";
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
