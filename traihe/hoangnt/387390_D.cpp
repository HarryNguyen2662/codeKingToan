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
int n, m;
int dp[35][105][105], dem[35][105];
void solve() 
{
	cin >> n >> m;
	if (n == 1)
	{
		string s;
		cin >> s;
		cout << "0\n";
		return;
	}

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	{
		char x;
		cin >> x;
		dem[j][i] = (x - '0') + dem[j][i-1];
	}
	
	for (int i = 0; i <= m + 1; i++) for (int j = 0; j <= n; j++) for (int e = 0; e <= n; e++) dp[i][j][e] = oo;
	for (int j = 0; j <= n; j++) for (int e = 0; e <= n; e++) dp[m + 1][j][e] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)  dp[i][j+1][j] = 0;
	}
	for (int j = m; j; j--)
	{
		for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++)
		{
			for (int e = l-1; e <= r; e++)
			{
				dp[j][l][r] = min(dp[j][l][r], 
					dp[j + 1][l][e] + dp[j + 1][e + 1][r] + 
					dem[j][e] - dem[j][l-1] + (r - e) - (dem[j][r] - dem[j][e])); 
			}
		}
	}
	//cout << dp[2][3] << " " << dem[m][3] - dem[m][0] << endl;
	cout << dp[1][1][n] << "\n";
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
