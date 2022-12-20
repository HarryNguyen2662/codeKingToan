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

int dp[2005][2005];

void solve() 
{
	string s;
	cin >> s;
	int n = (int)s.size();

	for (int i =1; i <= n; i++) for (int j = 1; j <= n; j++) dp[i][j] = 0;
	s = "@"  + s;

	for (int i = 1; i < n; i++)
	{
		if (s[i] != s[i + 1]) dp[i][i+1] = 1;
		else dp[i][i + 1] = 2;
	}

	for (int len = 4; len <= n; len += 2)
	{
		for (int i = 1; i <= n - len + 1; i++)
		{
			int j = i + len - 1;
			if (dp[i + 1][j - 1] == 3)
			dp[i][j] = 3;
			else if (dp[i + 1][j - 1] == 2)
			{
				if (s[i] > s[j])
				{
					if (dp[i][j - 2] == 3) dp[i][j] = dp[i][j-2];
					else if (dp[i][j - 2] == 2)
					{
						if (s[j] > s[j-1]) dp[i][j] = 3;
						else if (s[j] == s[j-1]) dp[i][j] = 2;
						else dp[i][j] = 1;
					}
					else dp[i][j] = 1;
				}
				else if (s[i] < s[j])
				{
					if (dp[i+2][j] == 3) dp[i][j] = 3;
					else if (dp[i+2][j] == 2)
					{
						if (s[i] > s[i + 1]) dp[i][j] = 3;
						else if (s[i] == s[i+1]) dp[i][j] = 2;
						else dp[i][j] = 1;
					}
					else dp[i][j] = 1;
				}
				else
				{
					if (dp[i][j - 2] == 3) dp[i][j] = dp[i][j-2];
					else if (dp[i][j - 2] == 2)
					{
						if (s[j] > s[j-1]) dp[i][j] = 3;
						else if (s[j] == s[j-1]) dp[i][j] = 2;
						else dp[i][j] = 2;
					}
					else dp[i][j] = 2;
					
					if (dp[i+2][j] == 3) dp[i][j] = 3;
					else if (dp[i+2][j] == 2)
					{
						if (s[i] > s[i + 1]) dp[i][j] = 3;
					}
					//cout << i << " " << j << " " << dp[i][j] << endl;
				}
			}
			else if (dp[i+1][j-1] == 1)
			{
				if (dp[i][j - 2] == 3) dp[i][j] = dp[i][j-2];
				else if (dp[i][j - 2] == 2)
				{
					if (s[j] > s[j-1]) dp[i][j] = 3;
					else if (s[j] == s[j-1]) dp[i][j] = 2;
					else dp[i][j] = 1;
				}
				else dp[i][j] = 1;
				
				if (dp[i+2][j] == 2)
				{
					if (s[i] == s[i + 1]) dp[i][j] = min(dp[i][j], 2);
					else dp[i][j] = 1;
				}
				else dp[i][j] = 1;
			}
		}
	}

	//cout << dp[2][3] << endl;

	if (dp[1][n] == 1)
	{
		cout << "Alice\n";
	}
	else if (dp[1][n] == 2)
	{
		cout << "Draw\n";
	}
	else
	{
		cout << "Bob\n";
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
