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

long long dp[5005][5005];

char s[5005], st[5005];

void solve() 
{
	vector<int> ldk;
	long long n, x, y;
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) cin >> s[i]; for (int i = 1; i <= n; i++) cin >> st[i];

	for (int i = 1; i <= n; i++) if (s[i] != st[i]) ldk.pb(i);

	if ((int)ldk.size()%2)
	{
		cout << "-1\n"; return;
	}

	if (y <= x)
	{
		if ((int)ldk.size() == 2 && ldk[0] + 1 == ldk[1]) 
		{
			if (n == 2)
			{
				cout << x << "\n"; return;
			}

			if (ldk[0] - 2 >= 1 || ldk[1] + 2 <= n) 
				{
					cout << min(x, 2*y) << "\n";
					return;
				}
			if (ldk[1] - 2 >= 1 && ldk[0] + 2 <= n)
			{
				cout << min(x, 3*y) << "\n"; return;
			}
			cout << x << "\n"; return;
		}

		cout << 1ll*(int)ldk.size()/2*y << "\n";
		return;
	}

	for (int i = 0; i <= (int)ldk.size(); i ++) for (int j = 0; j <= (int)ldk.size(); j++) dp[i][j] = oo18;

	dp[0][0] = 0;
	for (int i = 1; i <= (int)ldk.size(); i++)
	for (int j = 0; j <= (int)ldk.size(); j++)
	{
		if (j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
		if (i > 1) dp[i][j] = min(dp[i][j], dp[i-2][j] + 1ll*(ldk[i-1] - ldk[i-2])*x);
	}

	long long re = oo18;

	for (int i = 0; i <= (int)ldk.size(); i++) if (i%2 == 0) re = min(re, dp[(int)ldk.size()][i] + 1ll*i/2*y);
	
	cout << re << "\n";

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
