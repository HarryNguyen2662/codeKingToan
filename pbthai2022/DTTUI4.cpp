#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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
const long long MOD = 998244353;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll c[250][250], dp[202][202][202];
pair<int, ll> a[205];

void solve() 
{
    int n, S, k;
    cin >> n >> S >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }

    for (int i = 0; i <= k; i++) c[i][0] = 1;

    for (int i = 1; i <= k; i++) for (int j = 1; j <= k; j++) 
    {
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        if (c[i][j] >= MOD) c[i][j] -= MOD;
    }

    dp[0][0][0] = 1;

    for (int i = 0; i < n; i++)
    for (int j = 0; j <= S; j++)
    {
        dp[i + 1][j][0] += dp[i][j][0]; 
        if (dp[i + 1][j][0] >= MOD) dp[i + 1][j][0] -= MOD;
       
        if (j + a[i + 1].fi <= S)
        {
            dp[i + 1][j + a[i + 1].fi][0] += dp[i][j][0];
            if (dp[i + 1][j + a[i + 1].fi][0] >= MOD) dp[i + 1][j + a[i + 1].fi][0] -= MOD;
        }

        for (int e = 1; e <= k; e++)
        {
            dp[i + 1][j][e] += dp[i][j][e]; if (dp[i + 1][j][e] >= MOD) dp[i + 1][j][e] -= MOD;

            if (j + a[i + 1].fi <= S)
            {
                ll cur = 1;
                for (int ee = 0; ee <= e; ee++)
                {
                    dp[i + 1][j + a[i + 1].fi][e] += dp[i][j][e - ee]*cur%MOD*c[e][ee]%MOD; 
                    if (dp[i + 1][j + a[i + 1].fi][e] >= MOD) dp[i + 1][j + a[i + 1].fi][e] -= MOD; 
            
                    cur = a[i + 1].se*cur%MOD;
                }
            }
        }
    }

//    for (int i = 0; i <= k; i++) cout << dp[2][1][i] << "\n";

    ll ans = 0;
    for (int i = 0; i <= S; i++) 
    {
        ans += dp[n][i][k]; if (ans >= MOD) ans -= MOD;
    }

    cout << ans;
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
