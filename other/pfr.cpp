#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back#include<bits/stdc++.h>
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
vector<int> a[100005], aa[100005], ldk[100005];
int low[100005], num[100005], c[100005], p[100005], dd[100005], cnt = 0, tplt = 0;
stack<int> st;
pair<int,int> dem[100005];
int t0 = 0;
void tarjan(int u)
{
    st.push(u);
    low[u] = num[u] = ++cnt;
    for (auto v : a[u])
    if (num[v] > 0)
    {
        low[u] = min(low[u], num[v]);
    }
    else if (num[v] == 0)
    {
        tarjan(v);
        if (low[v] != -1) low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u])
    {
        if (st.top() == u)
        {
            st.pop();
            low[u] = num[u] = oo;
        }
        else
        {
            tplt++;
            while(true)
            {
                int v = st.top(); st.pop();
                low[v] = num[v] = -1;
                ldk[tplt].pb(v);
                if (v == u) break;
            }
        }
    }
}
void dfs(int u, int dai)
{
    t0 = max(t0, dai);
    for(auto v : aa[u])
    if (num[v] != -1)
    {
        c[v] = c[u];
        dfs(v, dai + 1);
    }
}
void update(int val, int ti)
{
    if (dd[val] == ti) return;
    dem[val].fi = max(dem[val].fi, dem[val].se); dem[val].se = 0; dd[val] = ti;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u; cin >> u;
        a[i].pb(u);
        aa[u].pb(i);
    }
    

    for(int i = 1; i <= n; i++) if (num[i] == 0) tarjan(i);
    for(int i = 1; i <= tplt; i++)
    {
        for (auto v : ldk[i])
        {
           // cout << v << " ";
            c[v] = (int)ldk[i].size();
            dfs(v, 0);
        }
        //cout << endl;
    }
    for (int i = 2; i <= n; i++)
        if (p[i] == 0)
        for (int j = i; j <= n; j += i) p[j] = i;
    for (int i = 1; i <= n; i++)
    {
        while(c[i] > 1)
        {
            update(p[c[i]], i);
            dem[p[c[i]]].se++;
            c[i] /= p[c[i]];
        }
    }
    

    long long res = 1;
    

    for (int i = 2; i <= n; i++)
    {
        int dai = max(dem[i].fi, dem[i].se);
        while(dai--) res = res*1ll*i%MOD;
    }
    cout << (res + t0)%MOD;
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
