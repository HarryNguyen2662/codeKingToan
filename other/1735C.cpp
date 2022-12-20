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

bool dd[500];
char re[500];
char s[100005];

int pa[5000];

int findpar(int u)
{
    return pa[u] < 0 ? u : pa[u] = findpar(pa[u]);
}

bool merge(int u, int v)
{
    u = findpar(u); v = findpar(v);
    if (u == v)
    {
        return pa[u] == -26;
    }

    if (pa[u] > pa[v]) swap(u, v);

    pa[u] += pa[v];
    pa[v] = u;
    return true;
}

void solve() 
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> s[i];

    for (int i = 'a'; i <= 'z'; i++) 
    {
        re[i] = 0;
        dd[i] = false;
        pa[i] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (re[s[i]] > 0)
        {
            cout << (char)re[s[i]];
            continue;
        }
        for (int j = 'a'; j <= 'z'; j++) if (dd[j] == 0 && j != s[i] && merge(j, s[i]))
        {
            cout << (char)j;
            re[s[i]] = j;
            dd[j] = true;
            break;
        }
    }

    cout << "\n";
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
    cin >> testcase;
    while(testcase--)
        solve();
}
