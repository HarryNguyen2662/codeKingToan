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

int cs[305], a[305], dp[305][305], f[305][305], dem[305], dd[305], ff[305][305], cs1[305];

void solve() 
{
	int n, t;
	cin >> n >> t;
	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (cs1[a[i]] == 0) cs1[a[i]] = i;
		cs[a[i]] = i; 
		dem[a[i]]++;
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++) 
		{
			dp[i][j] = 1;
			if (a[i] <= a[j] && i < j)
			{
				dp[i][j] = 2;
				for (int e = i + 1; e < j; e++) if (a[e] <= a[j] && a[e] >= a[i]) dp[i][j] = max(dp[i][j], dp[i][e] + 1);
			}
		}
	}

	for (int ti = 1; ti <= 300; ti++)
	for (int i = 1; i <= 300; i++)
	{

		for (int j = 1; j <= cs[i]; j++)
		if (a[j] <= i)
		{
			f[i][ti] = max(f[i][ti], f[a[j]][ti-1] + dp[j][cs[i]]);
		}
		f[i][ti] = max(f[i][ti], f[i-1][ti]);
	}

	for (int ti = 1; ti <= 300; ti++)
	for (int i = 300; i >= 1; i--)
	{
		for (int j = cs1[i]; j <= n; j++)
		if (a[j] >= i)
		{
			ff[i][ti] = max(ff[i][ti], ff[a[j]][ti-1] + dp[cs1[i]][j]);
		}
		ff[i][ti] = max(ff[i][ti], ff[i + 1][ti]);
	}

	
	for (int i = 0; i <= min(t, 300); i++)
	for (int j = 0; j <= min(300, t - i); j++)
	for (int u = 1; u <= 300; u++) res = max(res, f[u][i] + (t  - i - j)*dem[u] + ff[u][j]);
	
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
