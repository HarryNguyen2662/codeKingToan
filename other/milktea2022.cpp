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

int dp[105][105], dem[105][2], de[105];
string s[105];

void solve() 
{
	int n, m, p;
	cin >> n >> m >> p;

	for (int i = 0; i <= p; i++) dem[i][0] = dem[i][1] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= p; j++)
		{
			char x;
			cin >> x;
			dem[j][1 - x + '0']++;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> s[i];
	}

	sort(s + 1, s + 1 + m);

	for (int i = 2; i <= m; i++)
	{
		de[i] = 0;
		for (int j = 0; j < p; j++)
		if (s[i][j] == s[i-1][j])
		{
			de[i]++;
		}
		else break;
	}

	for (int i = 0; i <= p; i++) for (int e = 0; e <= m; e++) dp[i][e] = oo;

	bool kt = false, kt1 = false;
	for (int i = 1; i <= m; i++) 
	{
		if (s[i][0] == '0') kt = true;
		if (s[i][0] == '1') kt1 = true;

		dp[1][i] = dem[1][s[i][0] - '0'];

	}
	if (!kt) dp[1][0] = dem[1][0];
	if (!kt1) dp[1][0] = min(dp[1][0], dem[1][1]);

	for (int i = 1; i < p; i++)
	for (int j = 0; j <= m; j++)
	if (dp[i][j] < oo)
	{
		if (j == 0)
		{
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + min(dem[i + 1][0], dem[i + 1][1]));
		}
		else
		for (int e = 0; e < 2; e++)
		if (e == s[j][i] - '0')
		{
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dem[i + 1][e]);
		}
		else
		{
			bool ktt = true;

			for (int w = j + 1; w <= m; w++) 
			{
				if (de[w] < i) break;
				if (de[w] == i && s[w][i] - '0' == e)
				{
					ktt = false;
					break;
				}
			}

			for (int w = j; w >= 2; w--) 
			{
				if (de[w] < i) break;
				if (de[w] == i && s[w-1][i] - '0' == e)
				{
					ktt = false;
					break;
				}
			}
			if (ktt) dp[i + 1][0] = min(dp[i+1][0], dp[i][j] + dem[i + 1][e]);
		}
	}

	cout << dp[p][0] << "\n";
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
