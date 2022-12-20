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

long long c[2000005], inc[2000005], f[2000005];

long long combi(int n, int k)
{
	if (k > n) return 0;
	return c[n]*inc[k]%MOD*inc[n - k]%MOD;
}

void solve() 
{
	int n;
	cin >> n;
	f[1] = 1;
	c[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		c[i] = c[i-1]*1ll*i%MOD;
	}
	inc[n] = power(c[n], MOD-2);
	for (int i = n; i; i--) inc[i-1] = inc[i]*1ll*i%MOD;
	for (int i = 3; i <= 2*n; i+=2) f[i] = f[i-2]*1ll*i%MOD;
	long long res = 0;
	//cout << res << endl;
	long long cs, w = 1;
	w = 1;
	if (n%2 == 0)
	{
		res = f[n-1]*f[n-1]%MOD;
	}
	for (int i = 1; i <= n; i++)
	if ((n - i)%2 == 0)
	{
		long long w = 1;
		if (i != n) w = f[n - i - 1]*f[n-i-1]%MOD;
		//cout << combi(n, i)*w << " " << i << endl;
		res = (res + combi(n, i)*w%MOD)%MOD;
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
