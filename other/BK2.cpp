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
int dp[5001][5001][2], nopen[5005], nclose[5005], dd[2];
void solve() 
{
	int k;
	cin >> k;
	string s;
	cin >> s;
	int n = (int)s.size();
	for (int i = n; i >= 0; i--)
	{
		nopen[i] = dd[0];
		nclose[i] = dd[1];
		if (i && s[i-1] == '(') dd[0] = i; else dd[1] = i;
	}
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++)
	for (int j = 0; j <= k; j++)
	for (int ok = 0; ok < 2; ok++)
	if (dp[i][j][ok] > 0)
	{
		if (nopen[i] != 0)
		{
			if (j < k) dp[nopen[i]][j + 1][ok||(j+1==k)] += dp[i][j][ok], dp[nopen[i]][j + 1][ok||(j+1==k)] %= MOD;
		}
		if (nclose[i] != 0)
		{
			if (j > 0) dp[nclose[i]][j-1][ok] += dp[i][j][ok], dp[nclose[i]][j-1][ok] %= MOD;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res += dp[i][0][1], res %= MOD;
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
