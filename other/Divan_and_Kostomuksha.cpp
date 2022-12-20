#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
long long dem[20000005], dp[20000005];
bool pr[20000005];
void solve()
{
    int n, maxval = 0;
    vector<int> prime;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        maxval = max(maxval, val);
        dem[val]++;
    }
    pr[1] = pr[0] = true;
    for (int i = 2; 1ll*i*i <= maxval; i++)
        if (pr[i] == false)
            for (int j = i*i; j <= maxval; j+= i) pr[j] = true;
    for (int i = 1; i <= maxval; i++) if (!pr[i]) prime.pb(i);

    for (int i = 1; i <= maxval; i++)
    {
        //for (auto v : prime)
        for (int j = 2*i; j <= maxval; j+=i)
        {
            //if (1ll*v*i > maxval) break;
            dem[i] += dem[j];
        }
    }
    for (int i = maxval; i; i--)
    {
        dp[i] = dem[i]*i;
        for (auto v : prime)
        {
            if (1ll*v*i > maxval) break;
            dp[i] = max(dp[i], dp[v*i] + (dem[i] - dem[v*i])*i);
        }
    }
    cout << dp[1];
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    // 
    #endif
    //freopen("dienbien.inp","r",stdin); freopen("dienbien.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}