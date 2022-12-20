#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 1337377;
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18;
const long long oooo = 9223372036854775807;
long long n, k, f[105], sz, g[85][85], a[85];
void solve()
{
    cin >> n >> k;
    for (long long i = sz; i >= 1; i--)
    {
        if (n >= f[i])
        {
            n -= f[i];
            a[i] = 1;
        }
        else a[i] = 0;
    }
    long long res = 0, cnt = 0;
    for (long long i = sz; i >= 1; i--)
    {
        if (a[i] == 0) continue;
        for (long long j = max(0ll, k - cnt); j <= i - 1; j++)
        {
            res += g[i - 1][j] * (j + cnt);
        }
        cnt++;
    }

    if (cnt >= k) res += cnt;
    cout << res << '\n';

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    f[1] = 1;
    f[2] = 2;
    sz = 2;
    while (f[sz] <= 1e15)
    {
        sz++;
        f[sz] = f[sz - 1] + f[sz - 2];
    }
    g[0][0] = 1;
    g[1][0] = 1;
    g[1][1] = 1;
    g[2][0] = 1;
    g[2][1] = 2;
    g[2][2] = 0;
    for (long long i = 3; i <= sz; i++)
    {
        for (long long j = 0; j <= i; j++)
        {
            g[i][j] = g[i - 1][j];
            if (j > 0) g[i][j] += g[i - 2][j - 1];
        }
    }
    cout << g[50][20]<< endl;
    //cout << " hello ";
    int testcase;
    cin >> testcase; 
    while (testcase--) solve();
}
