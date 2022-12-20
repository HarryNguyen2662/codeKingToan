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

int x[4] = {-1, 0, 0, 1};
int y[4] = {0, -1, 1, 0};
int a[20][20];
vector<int> ldk, res;
int n = 4;

void dfs(int u, int v, int pre)
{
    //cout << "helo " << endl;
    if ((int)ldk.size() == 26)
    {
        return;
    }
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        bool kt = true;
        for (int j = 1; j <= n; j++) if (a[i][j] != (i - 1)*n + j)
        {
            kt = false; 
            break;
        } else dem++;
        if (!kt) break;
    }
    if (dem + 11 - (int)ldk.size() < 0) return;
    if (dem == 15)
    {
       // cout << (int)ldk.size() << "\n";
        if ((int)ldk.size() < (int)res.size()) res = ldk;
        return;
    }

    for (int i = 0; i < 4; i++)
    if (3 - i != pre)
    {
        int nu = u + x[i], nv = v + y[i];
        if (nu < 1 || nu > n || nv < 1 || nu > n || a[nu][nv] <= dem - dem%4) continue;
        swap(a[u][v], a[nu][nv]); ldk.pb(a[u][v]); dfs(nu, nv, i);
        swap(a[u][v], a[nu][nv]); ldk.pop_back(); 
    }
}

void solve() 
{
   pair<int,int> st;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
        cin >> a[i][j];
        if (a[i][j] == 0)
        {
            st = {i , j};
        }
    }
    for (int i = 1; i <= 25; i++) res.pb(-1);
    dfs(st.fi, st.se, -1);
    cout << (int)res.size() << "\n";
    for (auto v : res) cout << v << " ";
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
