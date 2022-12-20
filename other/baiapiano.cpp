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
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18;   
const long long oooo = 9223372036854775807;
int  dp[100005], trace[100005];
bool kt[100005];
int a[100005];
vector<int> aa[100005];
bool visit[100005];
bool check(int i, int j)
{
    if (a[j] > a[i] && kt[a[j]-a[i]] == false) return true;
    return false;
}
void dfs(int u)
{
    visit[u] = true;
    for (auto v : aa[u])
    {
        if (visit[v] == 0) dfs(v);
        if (dp[v] > dp[u])
        {
            dp[u] = dp[v] ;
            trace[u] = v;
        }
    }
    dp[u] ++;
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
    kt[1] = true; kt[0] = true;
    for (int i = 2; 1ll*i*i <= 100002; i++)
        for (int j = i*i; j <= 100002; j += i) kt[j] = 1;
    int n;
    cin >> n;
    for (int i = 1 ; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i-j > 0 && check(i, i-j)) aa[i].pb(i-j);
            if (i+j <= n && check(i, i+j)) aa[i].pb(i+j);
        }
    }
    int t = 0;
    for (int i = 1; i <= n; i++) if (visit[i] == false) 
        {
            dfs(i);
            if (dp[t] < dp[i]) t = i;
        }
    cout << dp[t] <<"\n";
    while(t != 0)
    {
        cout << t << " ";
        t = trace[t];
    }
}