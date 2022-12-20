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

vector<int> a[1000005];
long long fact[1000005], infact[1000005];
long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

long long dp[2000005];

int child[2000005];

long long c(int k, int n)
{
	return fact[n]*infact[k]%MOD*infact[n - k]%MOD;
}

void dfs(int u, int par)
{
	dp[u] = 1;
	child[u] = 1;

	for (auto v : a[u]) if (v != par)
	{
		dfs(v, u);
		child[u] += child[v];
		dp[u] = dp[u]*dp[v]%MOD*c(child[v], child[u] - 1)%MOD;
	}
}

void solve() 
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}
	int root;
	for (int i = 1; i <= n; i++) 
	{
		int val;
		cin >> val; if (val == 1) root = i;
	}
	if (k < n)
	{
		cout << 0; return;
	}

	fact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = 1ll*i*fact[i-1]%MOD;

	infact[n] = power(fact[n], MOD - 2);

	for (int i = n; i; i--) infact[i-1] = 1ll*i*infact[i]%MOD;


	dfs(root, 0);
	long long res = dp[root]*infact[n]%MOD;

	for (int i = 1; i <= n; i++)
	{
		res = 1ll*(k - n + i)*res%MOD;
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
    //freopen("SCORING.inp","r",stdin); freopen("SCORING.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
