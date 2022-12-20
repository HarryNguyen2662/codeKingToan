#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1 << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int lim = 125250;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
long long dp[2005][2005][2];
char s[2005];
void solve()
{
    int n, k;
    cin >> n >> k;
    int dem = 0;
    for (int i = 1; i <= 2*n; i+= 2)
    {
        cin >> s[i]; s[i + 1] = '?';
        if (s[i] == '?') dem++;
    }
    //for (int i = 1; i <= 2*n; i++) cout << s[i];
    //cout << endl;
    dp[0][0][0] = 1;
    for (int i = 0; i < 2*n; i++)
        for (int j = 0; j <= k; j++)
            for (int ok = 0; ok < 2; ok++)
            if (dp[i][j][ok] > 0)
            {
                if(j + 1 <= k && (s[i+1] =='?' || s[i+1] == '(' || s[i+1] == '{' || s[i+1] == '['))
                {
                    dp[i+1][j+1][(ok || j + 1 == k)] += dp[i][j][ok];
                    dp[i+1][j+1][(ok || j + 1 == k)] %= MOD;
                }
                if(j - 1 >= 0 && (s[i+1] =='?' || s[i+1] == ')' || s[i+1] == '}' || s[i+1] == ']'))
                {   
                    dp[i+1][j-1][ok] += dp[i][j][ok];
                    dp[i+1][j-1][ok] %= MOD;
                }
            }
    long long res = dp[2*n][0][1];
    for (int i = 1; i <= dem; i++) res = res*3%MOD;
    cout << res;
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
    solve();
}
