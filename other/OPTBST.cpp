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
bool maximize(long long &x, const long long &y)
{
	if (x > y)
	{
		x = y;
		return true;
	}
	return false;
}
long long su[2005], dp[2005][2005];
int root[2005][2005];
long long d(int i, int j)
{
	return su[j] - su[i-1];
}
void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		su[i] = su[i-1] + val;
	}
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) dp[i][j] = oo18;
	for (int len = 1; len <= n; len++)
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			int st = root[i][j-1] == 0 ? 1 : root[i][j-1];
			int ed = root[i+1][j] == 0 ? n : root[i+1][j];
			for (int k = st; k <= ed; k++)
			{
				if (maximize(dp[i][j], dp[i][k-1] + dp[k+1][j] + d(i,j)))
				{
					root[i][j] = k;
				}
			}
		}
	cout << dp[1][n];
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
