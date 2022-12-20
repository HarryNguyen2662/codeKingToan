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
const long long MODo = 1e9 + 19972207;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long dp[2][2][2];
long long sum[2][2][2];
long long su[2][2][2];
long long ti[2][2][2];
long long f[1000005];

void solve() 
{
	int dem = 0;
	string s, st;
	cin >> s >> st;
	int n = (int)s.size();
	
	f[n] = 1;
	for (int i = n - 1; i; i--) f[i] = 10ll*f[i+1]%MODo;
	dp[0][0][0] = 1;

	for (int i = 0; i < n; i++)
	{
    for (int t = 0 ; t < 2; t++)
    for (int tt = 0; tt < 2; tt++)
    if (dp[i%2][t][tt])
    {
        if (s[i] == '?' && st[i] == '?')
        {
            (dp[1 - i%2][t][tt] += 10ll*dp[i%2][t][tt]) %= MODo;
            (dp[1 - i%2][1][tt] += 45ll*dp[i%2][t][tt]) %= MODo;
            (dp[1 - i%2][t][1] += 45ll*dp[i%2][t][tt]) %= MODo;
            
            (sum[1 - i%2][t][tt] += 90ll*f[i+1]%MODo*dp[i%2][t][tt] + 10ll*sum[i%2][t][tt]) %= MODo;
            (sum[1 - i%2][1][tt] += 405ll*f[i+1]%MODo*dp[i%2][t][tt] + 45ll*sum[i%2][t][tt]) %= MODo;
            (sum[1 - i%2][t][1] +=  405ll*f[i+1]%MODo*dp[i%2][t][tt] + 45ll*sum[i%2][t][tt]) %= MODo;
            
            (su[1 - i%2][t][tt] += 45ll*f[i+1]%MODo*dp[i%2][t][tt] + 10ll*su[i%2][t][tt]) %= MODo;
            (su[1 - i%2][1][tt] += 285ll*f[i+1]%MODo*dp[i%2][t][tt] + 45ll*su[i%2][t][tt]) %= MODo;
            (su[1 - i%2][t][1] +=  120ll*f[i+1]%MODo*dp[i%2][t][tt] + 45ll*su[i%2][t][tt]) %= MODo;
            
            (ti[1 - i%2][t][tt] += 45ll*f[i+1]%MODo*sum[i%2][t][tt] + 10ll*ti[i%2][t][tt] + 285ll*f[i+1]%MODo*f[i+1]%MODo*dp[i%2][t][tt]) %= MODo;
            (ti[1 - i%2][1][tt] += 285ll*f[i+1]%MODo*(sum[i%2][t][tt] - su[i%2][t][tt]) + 120ll*f[i+1]%MODo*su[i%2][t][tt] + 45ll*ti[i%2][t][tt] + 870ll*f[i+1]%MODo*f[i+1]%MODo*dp[i%2][t][tt]) %= MODo;
            (ti[1 - i%2][t][1] += 120ll*f[i+1]%MODo*(sum[i%2][t][tt] - su[i%2][t][tt]) + 285ll*f[i+1]%MODo*su[i%2][t][tt] + 45ll*ti[i%2][t][tt] + 870ll*f[i+1]%MODo*f[i+1]%MODo*dp[i%2][t][tt]) %= MODo;

            
        }
        else if (s[i] != '?' && st[i] != '?')
        {
            (dp[1 - i%2][max(t, (int)(s[i] > st[i]))][max(tt, (int)(st[i] > s[i]))] += dp[i%2][t][tt])%=MODo;
            
            (sum[1 - i%2][max(t, (int)(s[i] > st[i]))][max(tt, (int)(st[i] > s[i]))] += 1ll*(s[i] + st[i] - 2*'0')*f[i+1]%MODo*dp[i%2][t][tt] + sum[i%2][t][tt])%=MODo;   
            
            (su[1 - i%2][max(t, (int)(s[i] > st[i]))][max(tt, (int)(st[i] > s[i]))] += 1ll*(s[i] - '0')*f[i+1]%MODo*dp[i%2][t][tt] + su[i%2][t][tt])%=MODo;   
        
            (ti[1 - i%2][max(t, (int)(s[i] > st[i]))][max(tt, (int)(st[i] > s[i]))] += 1ll*(s[i] - '0')*f[i+1]%MODo*(sum[i%2][t][tt] - su[i%2][t][tt]) + 1ll*(st[i] - '0')*f[i+1]%MODo*su[i%2][t][tt] + 1ll*(s[i] - '0')*(st[i] - '0')*f[i+1]%MODo*f[i+1]%MODo*dp[i%2][t][tt] + ti[i%2][t][tt])%=MODo;  
        }
        else if (s[i] == '?')
        {
            (dp[1 - i%2][t][tt] += dp[i%2][t][tt]) %= MODo;
            (dp[1 - i%2][1][tt] += 1ll*(9 - st[i] + '0')*dp[i%2][t][tt]) %= MODo;
            (dp[1 - i%2][t][1] += 1ll*(st[i] - '0')*dp[i%2][t][tt]) %= MODo;
            
            (sum[1 - i%2][t][tt] += 2ll*(st[i] - '0')*f[i+1]%MODo*dp[i%2][t][tt] + sum[i%2][t][tt]) %= MODo;
            (sum[1 - i%2][1][tt] += 1ll*((st[i] - '0')*(9 - st[i] + '0') + (9 + st[i] - '0' + 1)*(9 - st[i] + '0')/2)*f[i+1]%MODo*dp[i%2][t][tt] + 1ll*(9 - st[i] + '0')*sum[i%2][t][tt]) %= MODo;
            (sum[1 - i%2][t][1] +=  1ll*((st[i] - '0')*(st[i] - '0') + (st[i] - '0' - 1)*(st[i] - '0')/2)*f[i+1]%MODo*dp[i%2][t][tt] + 1ll*(st[i] - '0')*sum[i%2][t][tt]) %= MODo;
            
            (su[1 - i%2][t][tt] += 1ll*(st[i] - '0')*f[i+1]%MODo*dp[i%2][t][tt] + su[i%2][t][tt]) %= MODo;
            (su[1 - i%2][1][tt] += 1ll*((9 + st[i] - '0' + 1)*(9 - st[i] + '0')/2)*f[i+1]%MODo*dp[i%2][t][tt] + 1ll*(9 - st[i] + '0')*su[i%2][t][tt]) %= MODo;
            (su[1 - i%2][t][1] +=  1ll*((st[i] - '0' - 1)*(st[i] - '0')/2)*f[i+1]%MODo*dp[i%2][t][tt] + 1ll*(st[i] - '0')*su[i%2][t][tt]) %= MODo;
            

            (ti[1 - i%2][t][tt] += 1ll*(st[i] - '0')*f[i+1]%MODo*sum[i%2][t][tt] + ti[i%2][t][tt] + 1ll*(st[i]-'0')*(st[i]-'0')*f[i+1]%MODo*f[i+1]%MODo*dp[i%2][t][tt]) %= MODo;
            (ti[1 - i%2][1][tt] += 1ll*((9 + st[i] - '0' + 1)*(9 - st[i] + '0')/2)*f[i+1]%MODo*(sum[i%2][t][tt] - su[i%2][t][tt]) + 1ll*(st[i] - '0')*(9 - st[i] + '0')*f[i+1]%MODo*su[i%2][t][tt] + 1ll*(9 - st[i] + '0')*ti[i%2][t][tt] + 1ll*((9 + st[i] - '0' + 1)*(9 - st[i] + '0')/2)*(st[i] - '0')*f[i+1]%MODo*f[i+1]%MODo*dp[i%2][t][tt]) %= MODo;
            (ti[1 - i%2][t][1] += 1ll*((st[i] - '0' - 1)*(st[i] - '0')/2)*f[i+1]%MODo*(sum[i%2][t][tt] - su[i%2][t][tt]) + 1ll*(st[i] - '0')*(st[i] - '0')*f[i+1]%MODo*su[i%2][t][tt] + 1ll*(st[i] - '0')*ti[i%2][t][tt] + 1ll*((st[i] - '0' - 1)*(st[i] - '0')/2)*(st[i] - '0')*f[i+1]%MODo*f[i+1]%MODo*dp[i%2][t][tt]) %= MODo;       

        }
        else if (st[i] == '?')
        {
            (dp[1 - i%2][t][tt] += dp[i%2][t][tt]) %= MODo;
            (dp[1 - i%2][t][1] += 1ll*(9 - s[i] + '0')*dp[i%2][t][tt]) %= MODo;
            (dp[1 - i%2][1][tt] += 1ll*(s[i] - '0')*dp[i%2][t][tt]) %= MODo;
            
            (sum[1 - i%2][t][tt] += 2ll*(s[i] - '0')*f[i+1]%MODo*dp[i%2][t][tt] + sum[i%2][t][tt]) %= MODo;
            (sum[1 - i%2][t][1] += 1ll*((s[i] - '0')*(9 - s[i] + '0') + (9 + s[i] - '0' + 1)*(9 - s[i] + '0')/2)*f[i+1]%MODo*dp[i%2][t][tt] + 1ll*(9 - s[i] + '0')*sum[i%2][t][tt]) %= MODo;
            (sum[1 - i%2][1][tt] +=  1ll*((s[i] - '0')*(s[i] - '0') + (s[i] - '0' - 1)*(s[i] - '0')/2)*f[i+1]%MODo*dp[i%2][t][tt] + 1ll*(s[i] - '0')*sum[i%2][t][tt]) %= MODo;
            
            (su[1 - i%2][t][tt] += 1ll*(s[i] - '0')*f[i+1]%MODo*dp[i%2][t][tt] + su[i%2][t][tt]) %= MODo;
            (su[1 - i%2][t][1] += 1ll*(s[i] - '0')*(9 - s[i] + '0')*f[i+1]%MODo*dp[i%2][t][tt] + 1ll*(9 - s[i] + '0')*su[i%2][t][tt]) %= MODo;
            (su[1 - i%2][1][tt] +=  1ll*(s[i] - '0')*(s[i] - '0')*f[i+1]%MODo*dp[i%2][t][tt] + 1ll*(s[i] - '0')*su[i%2][t][tt]) %= MODo;
            
            (ti[1 - i%2][t][tt] += 1ll*(s[i] - '0')*f[i+1]%MODo*sum[i%2][t][tt] + ti[i%2][t][tt] + 1ll*(s[i]-'0')*(s[i]-'0')*f[i+1]%MODo*f[i+1]%MODo*dp[i%2][t][tt]) %= MODo;
            (ti[1 - i%2][t][1] += 1ll*(s[i] - '0')*(9 - s[i] + '0')*f[i+1]%MODo*(sum[i%2][t][tt] - su[i%2][t][tt]) + 1ll*((9 + s[i] - '0' + 1)*(9 - s[i] + '0')/2)*f[i+1]%MODo*su[i%2][t][tt] + 1ll*(9 - s[i] + '0')*ti[i%2][t][tt] + 1ll*((9 + s[i] - '0' + 1)*(9 - s[i] + '0')/2)*(s[i] - '0')*f[i+1]%MODo*f[i+1]%MODo*dp[i%2][t][tt]) %= MODo;
            (ti[1 - i%2][1][tt] += 1ll*(s[i] - '0')*(s[i] - '0')*f[i+1]%MODo*(sum[i%2][t][tt] - su[i%2][t][tt]) + 1ll*((s[i] - '0' - 1)*(s[i] - '0')/2)*f[i+1]%MODo*su[i%2][t][tt] + 1ll*(s[i] - '0')*ti[i%2][t][tt] + 1ll*((s[i] - '0' - 1)*(s[i] - '0')/2)*(s[i] - '0')*f[i+1]%MODo*f[i+1]%MODo*dp[i%2][t][tt]) %= MODo;
            
        }
    }
    for (int t = 0 ; t < 2; t++)
    for (int tt = 0; tt < 2; tt++)
    {
        dp[i%2][t][tt] = sum[i%2][t][tt] = su[i%2][t][tt] = ti[i%2][t][tt] = 0;
    }
	}
	
	cout << (ti[n%2][1][1] + 2*MODo)%MODo;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("brentford40mu.inp","r",stdin); freopen("brentford40mu.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
