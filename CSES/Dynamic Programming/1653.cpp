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
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
int a[30];
long long dp[1048580][22];
void solve() 
{
	int n; long long x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < mask(n); i++)
	{
		int m = getbit(i);
		for (int j = 0; j <= m; j++)
		{
			dp[i][j] = oo15;
			for (int e = 0; e < n; e++) if (ck(i, e))
			{
				if (j > 0 && dp[i^mask(e)][j-1] <= x)
				dp[i][j] = min(dp[i][j], 1ll*a[e]);
				else dp[i][j] = min(dp[i][j], dp[i^mask(e)][j] + a[e]);
			}
		}
	}
	for (int i = 0; i <= n; i++) if (dp[mask(n)-1][i] <= x)
	{
		cout << i + 1;
		return;
	}
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
