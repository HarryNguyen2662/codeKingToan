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

const int lim = 1000000;

long long fact[1000005], infact[1000005];

long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

long long c(int k, int n)
{
	return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}

void solve() 
{
	int n, m;
	cin >> n >> m;

	n = 2*n;
	long long res = fact[n];



	for (int i = 1; i <= m; i++)
	if (i%2)
	{
		//cout << i << " " << n - i << endl;
		res -= power(2, i)*c(i, m)%MOD*fact[n - i]%MOD*infact[n - i - i]%MOD*fact[n - 2*i]%MOD;
		res += MOD; res %= MOD;
	} 
	else
	{
		res +=  power(2, i)*c(i, m)%MOD*fact[n - i]%MOD*infact[n - i - i]%MOD*fact[n - 2*i]%MOD;
		res %= MOD;
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
    int testcase = 1;

    fact[0] = 1;

    for (int i = 1; i <= lim; i++)
    {
    	fact[i] = fact[i-1]*1ll*i%MOD;
    }

    infact[lim] = power(fact[lim], MOD-2);

    for (int i = lim; i >= 1; i --)  infact[i-1] = 1ll*i*infact[i]%MOD;
    cin >> testcase;
    while(testcase--)
        solve();
}
