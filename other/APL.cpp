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

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
long long power(long long val, long long cs)
{
	if (cs == 0) return 1;
	long long y = power(val, cs/2);
	if (cs%2) return y*y%MOD*val%MOD; else return y*y%MOD;
}
long long fact[200005], infact[200005];	
long long C(int k, int n)
{
	//if (k == 0 && n == 1) return 0;
	if (k > n || k < 0 || n < 0) return 0;
	return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}
void solve() 
{
	fact[0] = 1;
	for (int i = 1; i <= 200000; i++) fact[i] = fact[i-1]*1ll*i%MOD;
	infact[200000] = power(fact[200000], MOD - 2);
	for (int i = 200000; i; i--) infact[i-1] = infact[i]*1ll*i%MOD;
	//cout << C(3, 5) - C(2, 5) << endl;
	int h1, h2, n;
	long long res = 0;
	cin >> h1 >> h2 >> n;
	int t = h2;
	h2 -= h1;
	h1 = -t - h1 - 2;
	for (int i = 0; i <= n; i++)
	{
		if (n - i + h2 < 0 ||(n - i + h2)%2) continue;
		long long cur1 = C((n-i+h2)/2, n-i);
		long long cur2 = 0;
		if (n - i + h1 >= 0 && (n - i + h1)%2 == 0) cur2 = C((n-i+h1)/2, n-i); 
		//cout<< i << " " <<  cur << endl;
		res = (res + C(i,n)*(cur1 - cur2 + MOD)%MOD)%MOD;
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
