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

const int lim = 100000;

bool dd[lim + 5];
int cs[lim + 5], a[lim + 5];
long long fact[lim + 5], infact[lim + 5];


long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

long long c(int k, int n)
{
	return fact[n]*infact[k]%MOD*infact[n - k]%MOD;
}

void prepare()
{
	fact[0] = 1;

	for (int i = 1; i <= lim; i++) fact[i] = 1ll*i*fact[i-1]%MOD;

	infact[lim] = power(fact[lim], MOD - 2);

	for (int i = lim; i; i--) infact[i - 1] = 1ll*i*infact[i]%MOD;


}

void solve() 
{	
	int n;
	cin >> n;
	int st = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cs[a[i]] = i;
		dd[i - 1] = 0;
	}
	dd[n] = 0;

	int mex = 1;
	int l = cs[0], r = cs[0];

	//cout << l << " " << r << endl;
	int du = 0;
	dd[0] = true;

	long long res = 1;
	while(mex < n)
	{
		if (cs[mex] > r)
		{
			for (int i = r + 1; i <= cs[mex]; i++) dd[a[i]] = true, du++;
		}
		else
		{
			for (int i = cs[mex]; i <= l - 1; i++) dd[a[i]] = true, du++;
		}
		du--;
		l = min(l, cs[mex]); r = max(r, cs[mex]);
		int adu = 0;
		while(dd[mex]) 
		{
			mex++;
			adu++;
		}
		adu--;
		res = res*c(adu, du)%MOD*fact[adu]%MOD; res %= MOD;
		du -= adu;
	}
	cout << res << "\n";
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

    prepare();
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
