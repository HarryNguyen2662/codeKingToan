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

long long power(long long x, long long y, long long z)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2, z);
	if (y%2) return xx*xx%z*x%z; else return xx*xx%z;
}

long long p, pp, phipp, fact[1000005], muu[1000005];
long long mu = 0;

struct DATA
{
	long long a, b;
	DATA(const long long &_a, const long long &_b)
	{
		a = _a; b = _b;
	}

	DATA operator *(const DATA &other)
	{
		DATA res(0, 0);
		res.a = a*other.a%pp; res.b = b + other.b;
		return res;
	}

	DATA operator /(const DATA &other)
	{
		DATA res(0, 0);
		res.a = a*power(other.a, phipp - 1, pp)%pp; res.b = b - other.b;
		return res;
	}
};

DATA cal(long long n)
{
	DATA res(power(fact[pp-1], n/pp, pp)*fact[n%pp]%pp, n/p);
	if (n < p)
	{
		return res;
	}

	return res*cal(n/p);
}

long long calphi(long long n)
{

	long long res = n;

	for (int i = 2; i*i <= n; i++)
	if (n%i == 0)
	{
		res -= res/i;

		while(n%i == 0) n/=i;
	}

	if (n > 1) res -= res/n;

	return res;
}

void solve() 
{
	long long n, k, mod, m, mi;
	cin >> n >> k >> mod; k--; n += k;

	//cout << n << " " << k << endl;

	long long Mod = mod;

	long long res = 0;

	for (int i = 2; i*i <= mod; i++)
	if (mod%i == 0)
	{	

		p = i;
		pp = 1;
		
		mu = 0;
		while(mod%i == 0)
		{
			mu++;
			pp *= p; mod /= i;
		}
		phipp = calphi(pp);
		
		m = Mod/pp;
		m = m*power(m, phipp - 1, pp)%Mod;
		
		fact[0] = 1;
		for (int e = 1; e < pp; e++) 
		if (e%p == 0) fact[e] = fact[e-1]; else fact[e] = 1ll*e*fact[e-1]%pp;

	
		DATA cur = cal(n), cur1 = cal(k), cur2 = cal(n - k);

		cur = cur/cur1; cur = cur/cur2;


		if (cur.b < mu) res = (res + power(p, cur.b, pp)*cur.a%pp*m%Mod)%Mod;
	}

	if (mod > 1)
	{
		m = Mod/mod;
		p = mod;
		pp = mod;
	
		phipp = calphi(pp);
		
		m = m*power(m, phipp - 1, pp)%Mod;
		fact[0] = 1;
		for (int e = 1; e < pp; e++) 
		if (e%p == 0) fact[e] = fact[e-1]; else fact[e] = 1ll*e*fact[e-1]%pp;

	
		DATA cur = cal(n), cur1 = cal(k), cur2 = cal(n - k);

		cur = cur/cur1; cur = cur/cur2;

		if (cur.b < 1) res = (res + cur.a%pp*m%Mod)%Mod;
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
