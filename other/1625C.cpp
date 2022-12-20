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
int dp[505][505];
pair<int,int> a[505];
void solve() 
{
    int n, l, k;
    cin >> n >> l >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].se;
    }
    if (a[n].fi != l)
    {
        n++;
        a[n].fi = l;
    }
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = oo;
    dp[1][0] = 0;
    for (int i = 2; i <= n; i++)
    for (int j = 0; j <= k; j++)
    {
        for (int e = i; e >= 2; e--)
        if (j >= (i - e))
        dp[i][j] = min(dp[i][j], dp[e-1][j - (i - e)] + (a[i].fi - a[e-1].fi)*a[e-1].se);
    }
    int res = oo;
    for (int j = 0; j <= k; j++)
    if (dp[n][j] != oo)
    {
        res = min(res, dp[n][j]);
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
  //  cin >> testcase;
    while(testcase--)
        solve();
}
