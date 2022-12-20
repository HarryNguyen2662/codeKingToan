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


long long fact[8004], ifact[8004];
int lg[8004], g[4001][4001], f[8001];


long long power(long long a, long long b)
{
	if (b == 0) return 1;
	long long aa = power(a, b/2);
	if (b%2) return aa*aa%MOD1*a%MOD1; else return aa*aa%MOD1;
}

long long c(int k, int n)
{
	return fact[n]*ifact[k]%MOD1*ifact[n-k]%MOD1;
}


void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		while(mask(lg[i]) <= i) lg[i]++;
	}

	fact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = 1ll*i*fact[i-1]%MOD1;
	ifact[n] = power(fact[n], MOD1 - 2);
	for (int i = n; i; i--) ifact[i-1] = 1ll*i*ifact[i]%MOD1;


	f[1] = 1; f[2] = 2; f[3] = 2;
	for (int i = 4; i <= n; i++)
	{
		int l = mask(lg[i] - 2) - 1;
		int r = mask(lg[i] - 1) - 1;

		for (int j  = max(l, i - r - 1); j <= min(r, i - l - 1); j++)
			f[i] = (f[i] + 1ll*f[j]*f[i - j - 1]%MOD1*c(j, i - 1)%MOD1)%MOD1;
	}


	for (int i = 1; i <= lg[n]; i++) g[1][i] = 1;
	g[2][2] = 2; g[3][2] = 2;

	for (int j = 3; j <= lg[n]; j++)
	for (int i = 2; i <= min((int)mask(j) - 1, n); i++)
	{
		g[i][j] = 2ll*g[i-1][j-1]%MOD1;
		for (int e = 1; e <= i - 2; e++)
			g[i][j] = (g[i][j] + 1ll*g[e][j-1]*g[i - e - 1][j-1]%MOD1*c(e, i - 1)%MOD1)%MOD1;
	}

	
	cout << (g[n][lg[n]] - f[n] + MOD1)%MOD1 << " 0";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("bst.inp","r",stdin); freopen("bst.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
