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

long long power(long long a, long long b)
{
	if (b == 0) return 1;
	long long aa = power(a, b/2);
	if (b%2) return aa*aa%MOD*a%MOD; else return aa*aa%MOD;
}
long long dp[100005][35];
pair<char, int> a[100005];

void solve() 
{
	int n, m;
	cin >> n >> m;
	string s, p;
	cin >> s >> p;
	int cnt = 0;
	int so = 0;
	for (int i = 0; i < (int)s.size(); i++)
	if (s[i] > '9' || s[i] < '0')
	{
		a[cnt].se = so;
		so = 0;
		a[++cnt].fi = s[i];
	}
	else
	{
		so = so*10 + s[i] - '0';
	}

	a[cnt].se = so;
	p = "@" + p;

	

	for (int i = 0; i <= cnt; i++) dp[i][0] = 1;
	for (int i = 1; i <= cnt; i++)
	for (int j = 1; j <= m; j++)
	{
		dp[i][j] += dp[i-1][j];
		dp[i][j] %= MOD;
		if (a[i].fi == p[j])
		{
			long long sc = 1;
			for (int e = 1;  j + e - 1 <= m; e++)
			{	
				if (a[i].fi != p[j + e - 1]) break;
				sc = 1ll*sc*(a[i].se - e + 1)%MOD*power(e, MOD - 2)%MOD;
				dp[i][j + e - 1] += dp[i-1][j-1]*sc%MOD;
				dp[i][j + e - 1] %= MOD;
			}
		}
	}
	cout << dp[cnt][m];
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
