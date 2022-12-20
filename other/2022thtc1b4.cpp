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

long long f[1000005], inf[1000005];

long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

long long solve1(int n, int k)
{
	//cout << "hello ";
	if (k > n)
	{
		return 0;
	}
	long long res = power(k, n);
	for (int i = 1; i <= k; i++)
	{
		res += (i%2 ? -1ll : 1ll)*(f[k]*inf[k-i]%MOD*inf[i]%MOD*power(k-i, n)%MOD);
		res %= MOD; res += MOD;  res %= MOD;
	}
	return res;
}

long long solve2(int n, int k)
{
	if (2*k > n)
	{
		return 0;
	}
	if (k*2 == n)
	{
		return f[n]*power(inf[2], n/2)%MOD;
	}
	if (k*2 + 1 == n)
	{
		return f[n]*inf[3]%MOD*power(inf[2], n/2-1)%MOD*1ll*k%MOD;
	}
	long long res = solve1(n, k);
	//cout << res << endl;
	for (int i = 1; i <= k; i++)
	{
		res += (i%2 ? -1ll : 1ll)*(f[n]*inf[n-i]%MOD*f[k]%MOD*inf[k-i]%MOD*inf[i]%MOD*solve1(n-i, k - i)%MOD);
		res %= MOD; res += MOD;  res %= MOD;

	}
	return res;
}

void solve() 
{
	int n, k, m;
	cin >> n >> k >> m;

	f[0] = 1;
	for (int i = 1; i <= n; i++) f[i] = f[i-1]*1ll*i%MOD;
	inf[n] = power(f[n], MOD-2);
	for (int i = n; i; i--) inf[i-1] = inf[i]*1ll*i%MOD;

	if (m == 1) cout << solve1(n, k); else cout << solve2(n, k);
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
