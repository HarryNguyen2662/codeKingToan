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

int dp[2][26][26];
string s[700005];
void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	dp[1][s[1][0] - 'a'][s[1].back() - 'a'] = (int)s[1].size();


	for (int i = 2; i <= n; i++)
	{
		int w = (int)s[i].size();
		dp[i%2][s[i][0] - 'a'][s[i].back() - 'a'] = w;
		for (int j = 0; j < 26; j++)
		{
			if (dp[1 - i%2][j][s[i][0] - 'a'])
			dp[i%2][j][s[i].back() - 'a'] = max(dp[i%2][j][s[i].back() - 'a'], dp[1-i%2][j][s[i][0] - 'a'] + w);
			for (int e = 0; e < 26; e++) 
			{
				dp[i%2][j][e] = max(dp[i%2][j][e], dp[1-i%2][j][e]);
				dp[1-i%2][j][e] = 0;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < 26; i++)
	{
		res = max(dp[n%2][i][i], res);
	}
	cout << res;
}


int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("puzzles.inp","r",stdin); freopen("puzzles.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
