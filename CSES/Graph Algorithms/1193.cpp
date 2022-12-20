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

char s[1005][1005];
int dd[1005][1005], tv[1005][1005];

int x[4] = {0, 0, 1, -1};
int y[4] = {-1, 1, 0, 0};
char vt[4] = {'L', 'R', 'D', 'U'};
int n, m;

bool kt(int u, int v)
{
    if (u >= 1 && u <= n && v >= 1 && v <= m && s[u][v] != '#' && dd[u][v] == 0)
    {
        return true;
    }
    return false;
}

void bfs(int u, int v)
{
    queue<pair<int,int>> inque;
    inque.push({u, v}); dd[u][v] = 1;

    while(!inque.empty())
    {
        int u = inque.front().fi, v = inque.front().se; inque.pop();
      //  cout << u << " " << v << endl;
        for (int i = 0; i < 4; i++)
        {
            int new_u = u + x[i], new_v = v + y[i];
            if (kt(new_u, new_v)) 
            {
                dd[new_u][new_v] = dd[u][v] + 1;
                tv[new_u][new_v] = i;
                inque.push({new_u, new_v});
            }
        }
    }
}

void solve() 
{
    
    pair<int,int> st, ed;

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    {
        cin >> s[i][j];
        if (s[i][j] == 'A') st = {i, j};
        if (s[i][j] == 'B') ed = {i, j};
        tv[i][j] = -1;
    }

    bfs(st.fi, st.se);

    if (dd[ed.fi][ed.se] == 0)
    {
        cout << "NO"; return;
    }

    cout << "YES\n";

    cout << dd[ed.fi][ed.se] - 1 << "\n";

    vector<char> ldk;
    while(tv[ed.fi][ed.se] != -1)
    {
        int type = tv[ed.fi][ed.se];
        ldk.pb(vt[type]);
        ed.fi -= x[type]; ed.se -= y[type];
    }

    reverse(ldk.begin(), ldk.end());
    for (int i = 0; i < (int)ldk.size(); i++) cout << ldk[i];

}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
