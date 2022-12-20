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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long dp[3005][3005], fen[3005][3005], a[3005];
int n;

void update(int ti, int id, long long val)
{
    for (; id; id -= (id&(-id))) fen[ti][id] = max(fen[ti][id], val);
}

long long getmax(int ti, int id)
{
    long long res = -oo15;
    for (; id <= n; id += (id&(-id))) res = max(res, fen[ti][id]);
    return res; 
}

void solve() 
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        for (int j = 1; j <= n; j++) fen[i][j] = -oo15;
    }
    
    for (int i = 1; i <= n; i++) fen[1][i] = a[i];
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = i - 1; j; j--)
        {
            dp[i][j] = getmax(j, i - j) + a[i];
            update(i, i - j, dp[i][j]);
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dp[n][i]);
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
