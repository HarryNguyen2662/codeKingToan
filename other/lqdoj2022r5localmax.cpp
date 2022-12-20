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

long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

void solve() 
{
	ll n = 0, m = 0, k, nn = 0, mm = 0;
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
	{
		n = (n*10 + s[i] - '0')%(MOD - 1); 
		nn = (nn*10 + s[i] - '0')%MOD; 

	}

	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
	{
		m = (m*10 + s[i] - '0')%(MOD - 1); 
		mm = (mm*10 + s[i] - '0')%MOD; 		
	}

	cin >> k;


	ll ans = 0, re = power(k, (n*m%(MOD - 1) - n - m + 2*MOD - 1)%(MOD - 1))*1ll*nn%MOD*1ll*mm%MOD;


	for (int i = 1; i <= k; i++)
	{	
		ans += power(i - 1, (n - 1 + m - 1 + MOD - 1)%(MOD - 1))*re%MOD; ans %= MOD;
	}

	ans += power(k, n*m%(MOD - 1)); ans %= MOD;

	cout << ans << "\n";
}	

int main() 
{   
    freopen("LOCALMAX.inp","r",stdin); freopen("LOCALMAX.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
