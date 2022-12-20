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
int a[1005];
long long cnt[5100], dp[1005][10010], f[10010];
void solve() 
{
	int n, lim = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		//cout << a[i] << endl;
		lim = max(lim, 2*a[i] + 1);
		cnt[a[i]]++;
	}
	sort(a + 1, a + 1 + n);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	for (int j = 0; j <= lim; j++)
	{
		f[j] += dp[i][j]; f[j] %= MOD;
		dp[i+1][min(j + a[i+1], lim)] += f[j]; dp[i+1][min(j + a[i+1], lim)] %= MOD;
		//cout << i + 1 << " " << min(j + a[i+1], lim) << " " << dp[i+1][min(j + a[i+1], lim)] << endl;
	}
	long long res = 0;
	for (int i = 1; i <= n; i++) for (int j = 2*a[i]+1; j <= lim; j++) res += dp[i][j], res %= MOD;
	for (int i = 1; 2*i <= lim; i++) if (cnt[i] >= 4)
	{
		res -= cnt[i]*(cnt[i]-1)%MOD*(cnt[i]-2)%MOD*(cnt[i]-3)%MOD*41666667%MOD;
		res += MOD; res %= MOD;
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
