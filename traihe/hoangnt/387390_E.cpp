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

pair<int,int> a[505], b[505];
long long dp[2][501][501];
int cs[505];

bool cmp(const int &x, const int &y)
{
	return a[x] < a[y];
}

void solve() 
{
	int n, s1, s2;
	cin >> n >> s1 >> s2;
	for (int j = 0; j <= s1; j++) for (int e = 0; e <= s2; e++)
	dp[0][j][e] = dp[1][j][e] = oo15;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se >> b[i].fi >> b[i].se;
		cs[i] = i;
	}
	sort(cs + 1, cs + 1 + n, cmp);
	dp[0][0][0] = 0;
	int ti = 0;
	for (int id = 0; id < n; id++)
	{
		int i = cs[id+1] - 1;
		for (int j = 0; j <= s1; j++)
		for (int e = 0; e <= s2; e++)
		{
			dp[1 - ti][j][e] = min(dp[1- ti][j][e], dp[ti][j][e]);

			int w = max(j + a[i+1].fi - s1, 0);
			if (j != s1)
			dp[1- ti][min(j + a[i+1].fi, s1)][min(e + w, s2)] = min(dp[1-ti][min(j + a[i+1].fi, s1)][min(e + w, s2)],
				dp[ti][j][e] + a[i+1].se);
			dp[1 - ti][j][min(e + b[i+1].fi, s2)] = min(dp[1-ti][j][min(e + b[i+1].fi, s2)], dp[ti][j][e] + b[i+1].se);
		}
		for (int j = 0; j <= s1; j++)
		for (int e = 0; e <= s2; e++) dp[ti][j][e] = oo15;
		ti = 1 - ti;
	}
	//cout << dp[2][100][100] << endl;
	//cout << ti << endl;
	//ti = 1 - ti;
	if (dp[ti][s1][s2] == oo15)
	{
		cout << -1;
		return;
	}
	cout << dp[ti][s1][s2];
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
