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

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
vector<int>  ldk[1005];
int a[1000005], res[1000005];
void solve() 
{
    int n; 
    set<pair<int,int>> ss;
    cin >> n;
    for (int i = 1; i <= n*n; i++)
    {
        cin >> a[i];
        ldk[a[i]].pb(i);
    }
    int cnt = 0;
    for (int i = 1; i <= n + 1; i++) if ((int)ldk[i].size() > 0) ss.insert({(int)ldk[i].size(), i});
    for (int i = 1; i <= n; i++)
    if ((int)ss.size() >= 2)
    {  

        pair<int,int> u = *ss.begin(), v = *ss.rbegin();
        ss.erase(u); ss.erase(v);
      //  cout << u.se << " " << v.se << endl;
        if (u.fi + v.fi < n)
        {
            cout << "NO";
            return;
        }
        //int u = qa[w].back(); qa[w].pop_back();
        for (int j = 1; j <= n; j++)
        {
            if ((int)ldk[u.se].size() ==0) break;
            res[ldk[u.se].back()] = i;
            ldk[u.se].pop_back();
        }
        if ((int)ldk[u.se].size() > 0) 
        {
            ss.insert({(int)ldk[u.se].size(), u.se});   
        }
        // cout << i << endl;
        for (int e = u.fi + 1; e <= n; e++)
        {
            res[ldk[v.se].back()] = i;
            ldk[v.se].pop_back();
        } 
        if ((int)ldk[v.se].size() > 0) ss.insert({(int)ldk[v.se].size(), v.se});
    }
    else if ((int)ss.size() == 1)
    {
        pair<int,int> u = *ss.begin();
        for (int j = 1; j <= n; j++)
        {
            if ((int)ldk[u.se].size() == 0)
            {
                cout << "NO";
                return;
            }
            res[ldk[u.se].back()] = i;
            ldk[u.se].pop_back();
        }
        if ((int)ldk[u.se].size() > 0) ss.insert({(int)ldk[u.se].size(), u.se});
    }
    else
    {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= n*n; i++) cout << res[i] << " ";
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
