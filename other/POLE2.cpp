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
int SQR(int val)
{
	return val*val;
}
long long dp[4005][4005];
int c[4005], h[4005];
void solve() 
{
	int n, d, lim = 0;
	n = ReadInt(); d = ReadInt();
	for (int i = 1; i < n; i++) c[i] = ReadInt();
	for (int i = 1; i <= n; i++) h[i] = ReadInt(), lim = max(lim, h[i]);
    //cout << lim << endl;
	for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= lim; j++) dp[i][j] = oo15;
	for (int i = h[n]; i <= lim; i++) dp[n][i] = SQR(h[n] - i);
	for (int i = n; i >= 2; i--)
	for (int j = h[i]; j <= lim; j++)
	{
		for (int e = max(h[i-1], j - d); e <= min(lim, j + d); e++)
		dp[i-1][e] = min(dp[i-1][e], dp[i][j] + c[i-1]*abs(e-j) + SQR(e - h[i-1]));
	}
	long long res = oo15;
	for (int i = 0; i <= lim; i++) res = min(res, dp[1][i]);
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
    //freopen("POLE2.inp","r",stdin); freopen("POLE2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
