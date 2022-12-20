#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 18
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

long long dp[200005], a[200005], f[200005];

void solve() 
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i-1];
		a[i-1] = dp[i-1];
	}

	dp[0] = 0;

	for (int i = 0; i <= log; i++) for (int j = 0 ; j < n; j++)
	if ((j&mask(i))) 
	{
		dp[j] += dp[j^mask(i)];
		dp[j] %= MOD;
	}
	
	for (int i = 0; i < n; i++)
	{
		f[i] = dp[i]*dp[i]%MOD;
	}

	for (int i = 0; i <= log; i++) for (int j = 0 ; j < n; j++)
	if ((j&mask(i))) 
	{
		f[j] -= f[j^mask(i)];
		f[j] += MOD; f[j] %= MOD;
	}

	long long res = 0;

	for (int j = 0; j < n; j++)
	{
		res += f[j]; res %= MOD;

		if (j == 0) res += a[0]*a[0]%MOD; else res += 2*a[0]%MOD*a[j]%MOD;
		res %= MOD;

		cout << res << " ";
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
    //cin >> testcase;
    while(testcase--)
        solve();
}
