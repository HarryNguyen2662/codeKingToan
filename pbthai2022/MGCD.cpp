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
int de[100005], a[100005];

long long power(long long x, long long y, long long z)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2, z);
	if (y%2) return xx*xx%z*x%z; else return xx*xx%z;
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		de[a[i]]++;
	}
	for (int i = 1; i <= lim; i++)
	for (int j = 2*i; j <= lim; j+= i) de[i] += de[j];
	long long res = 1;
	for (int i = lim; i; i--)
	{
		de[i] = (power(2, de[i], MOD - 1) - 1 + (MOD-1))%(MOD -1);
		for (int j = 2*i; j <= lim; j+= i) 
		{
			de[i] = (de[i] - de[j] + MOD - 1)%(MOD - 1);
		}
		res = res*power(i, de[i], MOD)%MOD;
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
