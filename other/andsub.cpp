#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 19
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

const int lim = mask(20) - 1;
int dem[lim + 5];
long long fact[lim + 5];

void solve() 
{
	int n;
	cin >> n;
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int x = 0;
		cin >> x;
		x ^= lim;
		dem[x]++;
		fact[i] = fact[i-1]*2%MOD;
	}

	for (int j = 0; j <= log; j++)
		for (int i = 0; i <= lim; i++)
		if (ck(i, j)) dem[i] += dem[i^mask(j)];
	
	long long res = fact[dem[lim]];

	for (int i = 1; i <= lim; i++) 
	{
		if (getbit(i)%2 == 0) res += fact[dem[i^lim]]; else res -= fact[dem[i^lim]];
		res = (res%MOD + MOD)%MOD;
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
