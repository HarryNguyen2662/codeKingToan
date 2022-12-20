#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

const int lim = 10000000;

int fact[lim + 5], infact[lim + 5], f[lim + 5], dem[lim + 5][2];
bool ke[lim + 5], ti[lim + 5];
int cnt, fs[lim];

long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

ll c(int n, int k)
{
	if (k > n) return 0;

	return 1ll*fact[n]*infact[k]%MOD*1ll*infact[n - k]%MOD;
}

void prepare()
{
	fact[0] = 1;
	for (int i = 1; i <= lim; i++) 
	{
		f[i] = i;
		fact[i] = 1ll*i*fact[i - 1]%MOD;
		if (i%2) ti[i] = 0; else ti[i] = 1 - ti[i/2];
	}


	fs[++cnt] = 1;
	for (int i = 2; 1ll*i*i <= lim; i++)
	{
		if (ke[i] ==  false)
		for (int j = i*i; j <= lim; j += i)
		{
			ke[j] = true;
			if (f[j/i]%i) f[j] = f[j/i]*i; else f[j] = f[j/i]/i;
		}

	}
	infact[lim] = power(fact[lim], MOD - 2);
	for (int i = lim; i; i--) 
	{
		if (f[lim - i + 1] == lim - i + 1) fs[++cnt] = lim - i + 1;
		infact[i - 1] = 1ll*i*infact[i]%MOD;
	}
}

void solve() 
{
	int n; ll k;
	cin >> n >> k;

	if (k > n)
	{
		cout << "-1 0\n"; return;
	}

	if (k == 1)
	{
		cout << "0 " << n << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		dem[f[i]][ti[i]]++;
	}

	ll ans = 0;

	for (int i = 1; i <= cnt; i++)
	{
		if (fs[i] > n) break;
		
		ans +=  c(dem[fs[i]][0], k) + c(dem[fs[i]][1], k);
		while(ans >= MOD) ans -= MOD;

		dem[fs[i]][0] = dem[fs[i]][1] = 0;
	}


	if (ans == 0)
	{
		cout << "49 " << c(n, k) << "\n"; return;
	}

	cout << "1 " << ans << "\n";
}

int main() 
{   
	#ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("SUSSET.inp","r",stdin); freopen("SUSSET.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    prepare();  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
