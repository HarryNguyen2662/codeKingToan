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

long long f[2000005], dp[10005], inf[2000005];
long long cal(int a, int b)
{
	return f[a + b]*inf[a]%MOD*inf[b]%MOD;
}

pair<int,int> a[10005];

void solve() 
{
	int k;
	int n, m;
	cin >> n >> m >> k;
	//cout << n << m << k << endl;
	for (int i = 1; i <= k; i++)
	{
		cin >> a[i].fi >> a[i].se;
	}
	int su = n + m;
	f[0] = 1;
	for (int i = 1; i <= su; i++) f[i] = f[i-1]*1ll*i%MOD;
	inf[su] = power(f[su], MOD-2);
	for (int i = su; i; i--) inf[i-1] = inf[i]*1ll*i%MOD;
	sort(a + 1, a + 1 + k);
	//cout << cal(1, 1) << endl;
	for (int i = 1; i <= k; i++)
	{
		//cout << a[i].fi - 1 << " " << a[i].se - 1 << endl;
		dp[i] = cal(a[i].fi - 1, a[i].se -1);
		//cout << dp[i] << endl;
		for (int j = i-1; j; j--)
		if (a[j].fi <= a[i].fi && a[j].se <= a[i].se)
		{
			dp[i] = (dp[i] - dp[j]*cal(a[i].fi - a[j].fi, a[i].se - a[j].se)%MOD + MOD)%MOD;
		}
	}
	long long res = cal(n - 1, m - 1);
	//cout << res << endl;a[i].fi + a[i].se
	for (int i = 1; i <= k; i++)
	{
		res = res - dp[i]*cal(n - a[i].fi, m - a[i].se)%MOD;
		res = (res + MOD)%MOD;
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
