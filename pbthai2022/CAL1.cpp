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
const long long MOD = 1000003;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

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
		res.a = a*other.a%MOD; res.b = b + other.b;
		return res;
	}

	DATA operator /(const DATA &other)
	{
		DATA res(0, 0);
		res.a = a*power(other.a, MOD - 2)%MOD; res.b = b - other.b;
		return res;
	}
};

long long fact[MOD + 5];

DATA cal(long  long val)
{
	DATA res = {power(fact[MOD - 1], val/MOD)*fact[val%MOD], val/MOD};

	if (val < MOD)
	{
		return res;
	}

	return res*cal(val/MOD);
}


void solve() 
{
	long long a, b, n, k;
	cin >> a >> b >> n >> k;
	// a^(n-1)*b(m-1)*c(n - 1, n + k - 1)
	long long res = power(a, n - 1)*power(b, k - 1)%MOD;
	DATA cur = cal(n + k - 2), cur1 = cal(n - 1), cur2 = cal(k - 1);
	cur = cur/cur1; cur = cur/cur2;

	if (cur.b > 0) cout << "0\n"; else cout << cur.a*res%MOD << "\n";
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
    fact[0] = 1;
    for (int i = 1; i < MOD; i++) fact[i] = 1ll*i*fact[i-1]%MOD;
    cin >> testcase;
    while(testcase--)
        solve();
}
