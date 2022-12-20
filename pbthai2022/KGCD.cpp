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

long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

long long fact[1000005], infact[1000005], dem[1000005], de[1000005];

vector<int> uoc[1000005];

long long A(int k, int n)
{
	if (k > n) return 0;

	return fact[n]*infact[n - k]%MOD;
}

void solve() 
{
	int n, k;
	cin >> n >> k;
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fact[i] = 1ll*i*fact[i-1]%MOD;
		for (int j = 1; 1ll*j*j <= i; j++) if (i%j == 0)
		{
			uoc[i].pb(j); if (j != i/j) uoc[i].pb(i/j);
		}
		sort(ALL(uoc[i]));
	}

	infact[n] = power(fact[n], MOD - 2); for (int i = n; i; i--) infact[i-1] = 1ll*i*infact[i]%MOD;

	long long res = 0;
	for (int i = 1; i < k; i++) for (auto v : uoc[i]) dem[v]++;
	
	for (int i = k; i <= n; i++)
	{
		for (auto v : uoc[i])
		{
			res -= 1ll*v*de[v]%MOD; res += MOD; res  %= MOD;
			for (auto vv : uoc[v]) if (vv != v) de[vv] = (de[vv] + de[v])%MOD; 
			de[v] -= A(k, dem[v]); de[v] += MOD; de[v] %= MOD;
		}

		for (int j = (int)uoc[i].size() -1; j >= 0; j--)
		{
			dem[uoc[i][j]]++;
			de[uoc[i][j]] += A(k, dem[uoc[i][j]]);  de[uoc[i][j]] %= MOD;
			for (auto vv : uoc[uoc[i][j]]) if (vv != uoc[i][j]) de[vv] = (de[vv] - de[uoc[i][j]] + MOD)%MOD; 
			res += 1ll*uoc[i][j]*de[uoc[i][j]]%MOD;  res  %= MOD;
		}

		cout << res << "\n";
	}
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
