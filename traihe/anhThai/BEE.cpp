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

int f[30000005], inf[30000005];
long long cal(int a, int b, int c)
{
	return 1ll*f[a + b + c]*1ll*inf[a]%MOD*1ll*inf[b]%MOD*1ll*inf[c]%MOD;
}

void solve() 
{
	int n ,m, k;
	cin >> n >> m >> k;
	int su = m + n + k;
	f[0] = 1;
	for (int i = 1; i <= su; i++) f[i] = 1ll*f[i-1]*i%MOD;
	inf[su] = power(f[su], MOD - 2);
	for (int i = su; i; i--) inf[i-1] = 1ll*inf[i]*i%MOD;
	int u = n/ 3, v = m/3, e = k/3;
	int uu = 2*u, vv = 2*v, ee = 2*e;
	//cout << u << " " << v << " " << e << endl;
	//cout << cal(2, 2, 2) << endl;
	//cout << cal(n - u, m - v, k - e) << endl;
	long long res = cal(u, v, e)*cal(n - u, m - v, k - e)%MOD + cal(uu, vv, ee)*cal(n - uu, m - vv, k -ee);
	res %= MOD;
	res = res - cal(u, v, e)*cal(uu - u, vv - v, ee - e)%MOD*cal(n - uu, m - vv, k -ee)%MOD;
	res = (res + MOD)%MOD;	
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
