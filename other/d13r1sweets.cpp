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
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long w;
bool f[1050000];
int a[1000005], tf[1050000], dd[1000005], n, k;
bitset<3335> dp[105][3335];
bool daco[3335][3335];

void solve1()
{
    f[0] = true;
    for (int i = 0 ; i < mask(n); i++)
    if (f[i])
    {
        int sum = 0;
        for (int j = 0; j < n; j ++) if (i&mask(j))
        {
            sum += a[j]; sum %= w;
        }
        for (int j = 0; j < n; j++) if (!(i&mask(j)))
        if (sum + a[j] <= w)
        {
            f[i^mask(j)] = true;
            tf[i^mask(j)] = j; 
        } 
    }
    if (!f[mask(n) - 1])
    {
        cout << -1;
        exit(0);
    }
    int t = mask(n)-1;
    int sum = 0;
    int cnt = 1;
    while (t != 0)
    {
        dd[tf[t]] = cnt;
        sum += a[tf[t]];
        if (sum == w)
        {
            cnt++; sum = 0;
        }
        t = t^mask(tf[t]);
    } 
    for (int i = 0; i < n; i++) cout << dd[i] << " "; 
}

void solve2()
{
    vector<pair<int,int> > ldk;
    int w1 = w, w2 = w, cs = n;
    ldk.pb({0, 0}); daco[0][0] = true; dp[0][0][0] = 1;
    bool kt = false;
    for (int i = 0; i < n; i++)
    {
        int dai = (int)ldk.size();
        for (int j = 0; j < dai; j++)
        {
            pair<int,int> v = ldk[j];
            dp[i+1][v.fi][v.se] = 1;
            if (v.fi + a[i] <= v.se)
            {
                dp[i+1][v.fi + a[i]][v.se] = 1;
                if (v.fi + a[i] == w)
                {
                    kt = true;
                    cs = i+1; break;
                }
                if (daco[v.fi + a[i]][v.se] == false)
                {
                    daco[v.fi + a[i]][v.se] = true;
                    ldk.pb({v.fi + a[i], v.se});
                }
            }
            if (v.se + a[i] <= w)
            {
                dp[i+1][v.fi][v.se + a[i]] = 1;
                if (daco[v.fi][v.se + a[i]] == false)
                {
                    daco[v.fi][v.se + a[i]] = true;
                    ldk.pb({v.fi, v.se + a[i]});
                }
            }
        }
        if (kt) break;
    }
    if (dp[n][w][w] == 0 && !kt)
    {
        cout << -1; 
        exit(0);
    }
    for (int i = n; i > cs; i--) dd[i] = 3;
    for (int i = cs; i; i--)
    {
        if (w1 >= a[i-1] &&dp[i-1][w1-a[i-1]][w2] == 1)
        {
            dd[i] = 1;
            w1 -= a[i-1];
        }
        else if (w2 >= a[i-1] &&dp[i-1][w1][w2-a[i-1]] == 1)
        {
            dd[i] = 2;
            w2 -= a[i-1];
        }
        else dd[i] = 3;
    }
    for (int i = 1; i <= n; i++) cout << dd[i] <<" ";
}

void solve3()
{
    for (int sl = 1; sl <= k; sl++)
    {
        long long sum = w;
        for(int i = n; i; i--) if (sum >= i && dd[i] == 0)
        {
            sum -=i; dd[i] = sl;
        }
        if (sum != 0)
        {
            cout << -1;
            exit(0);
        }
    }
    for (int i = 1; i <= n; i++) cout << dd[i] << " ";
}


void solve() 
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        w += a[i];
    }
    if (w % k)
    {
        cout <<-1;
        return ;
    }
    w /= k;
    if (n <= 29) solve1(); else
    if (n <= 100 && k == 3) solve2();
    else solve3();
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
