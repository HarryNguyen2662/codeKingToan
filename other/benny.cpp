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

int p[2005], a[2005], dp[1005][1005][2];
vector<int> ldk[2005];

void solve() 
{
	int n, k;
	vector<int> diff;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		diff.pb(a[i]);
	}

	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());
	int ti = (int)diff.size();

	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(ALL(diff), a[i]) - diff.begin() + 1;
		// cout << a[i] << endl;
		ldk[a[i]].pb(p[i]); 
	}

	for (int i = 1; i <= ti; i++)
	{
		sort(ALL(ldk[i]));
	}

	for (int i = 0; i <= ti; i++) for (int j = 0; j <= k; j++) 
	for (int e = 0; e < 2; e++) dp[i][j][e] = oo;

	dp[0][0][0] = 0;

	for (int i = 0; i < ti; i++)
	for (int j = 0; j <= k; j++)
	for (int e = 0; e < 2; e++)
	if (dp[i][j][e] < oo)
	{
		dp[i + 1][j][e] = min(dp[i + 1][j][e], dp[i][j][e]);
		if (e == 0)
		{
			for (int x = 1; x <= (int)ldk[i + 1].size() && j + x <= k; x++)
			{
				dp[i + 1][j + x][0] = min(dp[i + 1][j + x][0], dp[i][j][e] + 2*ldk[i + 1][x - 1]);
				dp[i + 1][j + x][1] = min(dp[i + 1][j + x][1], dp[i][j][e] + ldk[i + 1][x - 1]);
			}
		}
		else
		{
			for (int x = 1; x <= (int)ldk[i + 1].size() && j + x <= k; x++)
			{
				dp[i + 1][j + x][1] = min(dp[i + 1][j + x][1], dp[i][j][e] + 2*ldk[i + 1][x - 1]);
			}
		}
	}

	for (int i = 1; i <= ti; i++)
	{
		ldk[i].clear();
	}

	cout << dp[ti][k][1] << "\n";
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
