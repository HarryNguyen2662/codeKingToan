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

int pri[300005];

void solve() 
{
	int n; long long m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) pri[i] = i;
	for (int i = 2; i <= n; i++)
	if (pri[i] == i)
	for (int j = 2*i; j <= n; j += i) pri[j] = i;

	long long res = m%MOD1;
	long long res1 = m%MOD1;
	long long cur = m%MOD1;
	long long pre = 1;
	long long adu = m%MOD1;

	for (int i = 2; i <= n; i++)
	{
		if (pri[i] == i && oo18/i > pre) pre = 1ll*i*pre;
		cur = 1ll*((m/pre)%MOD1)*cur%MOD1;
		res += cur; res %= MOD1; 
		adu = (m%MOD1)*adu%MOD1;
		res1 += adu; res1 %= MOD1;
	}


	cout << (res1 -  res + MOD1)%MOD1;
}

MODtem
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
