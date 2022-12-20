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

int n; long long m;
long long dp[5005], f[5005], dpp[5005];
int a[5005];
long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}
void sub1()
{
	n--;
	m--;
	//cout << n << " " << m << endl;
	if (n > m)
	{
		cout << 0;
		exit(0);
	}
	m = m%MOD;
	long long tu = 1, mau = 1;
	for (int i = 1; i <= n; i++)
	{
		tu = tu*(m - i + 1 + MOD)%MOD;
		mau = mau*1ll*i%MOD;
	}
	//cout << tu << " " << power(mau, MOD - 2) << endl;
	cout << tu*power(mau, MOD - 2)%MOD;
	exit(0);
}
void sub2()
{
	//cout << m << endl;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[j] = f[j%a[i]];
			f[j%a[i]] = (f[j%a[i]]+ dpp[j])%MOD;
			//if (j == 20) cout << i << " " <<dp[j] << endl;
			if (i == n && j == m)
			{
				cout << dp[j];
				return;
			}
		}
		for (int j = 1; j <= m; j++)
		{
			dpp[j] = dp[j]; dp[j] = 0;
			f[j%a[i]] = 0;
		}
	}
}
void solve() 
{
	cin >> n >> m;
	if (n == 1)
	{
		int va;
		cin >> va;
		if (m%va == 0) cout << 1;
		else cout << 0;
		return;
	}
	if (n > 1000 && m > 5000) sub1();
	for (int i = 1; i <= n; i++) cin >> a[i];
	sub2(); 
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
