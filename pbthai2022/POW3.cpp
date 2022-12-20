#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

int dp[10005][1005][3][2];

void change(vector<int> &res, string &s)
{
	vector<int> adu;

	for (int i = (int)s.size() - 1; i >= 0; i--) 
	{
		adu.pb(s[i] - '0');
	}

	while((int)adu.size() != 1 || adu[0] != 0)
	{
		int du = 0;
		for (int i = (int)adu.size() - 1; i >= 0; i--)
		{
			du = (du*10 + adu[i]);
			adu[i] = du/3; du %= 3;
		}
		res.pb(du);
		while((int)adu.size() > 1 && adu.back() == 0) adu.pop_back();
	}

}

void solve() 
{
	string L, R;
	int k;

	cin >> L >> R >> k; 

	vector<int> limL; change(limL, L);
	vector<int> limR; change(limR, R);

	while((int)limL.size() < (int)limR.size()) limL.pb(0);

	int n = (int)limR.size();

	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= k; j++)
	for (int kk = 0; kk < 3; kk++)
	for (int kkk = 0; kkk < 2; kkk++)
	dp[i][j][kk][kkk] = 0;

	dp[0][0][1][1] = 1;
	for (int i = 0; i < n; i++)
	for (int j = 0; j <= k; j++)
	for (int kk = 0; kk < 3; kk++)
	for (int kkk = 0; kkk < 2; kkk++)
	if (dp[i][j][kk][kkk])
	for (int cur = 0; cur <= 2; cur++)
	if (kkk == 0 || (kkk && cur <= limR[n - i - 1]))
	{	
		int nk = 0, nkk = 0;
		if (kk == 2 || (kk == 1 && cur > limL[n - i - 1])) nk = 2; else if (kk == 1 && cur == limL[n - i - 1]) nk = 1;
		if (kkk && cur == limR[n - i - 1]) nkk = 1; 

		dp[i+1][j + cur][nk][nkk] += dp[i][j][kk][kkk];
		dp[i+1][j + cur][nk][nkk] %=MOD;

	}

	//cout << dp[2][1][2][1] << " " << dp[2][1][2][0] << endl;

	long long res = 0;
	for (int i = 1; i <= 2; i++) for (int j = 0; j < 2; j++)
	for (int e = 0; e <= k; e++)
	{
		res += dp[n][e][i][j]; res %= MOD;
	}

	cout << res << "\n";
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
