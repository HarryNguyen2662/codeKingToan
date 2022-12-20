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
int cnt = 0;
vector<int> a[500005];
int sx[500005], child[500005], in[500005], out[500005], fen[1000005];
bool block[500005];
void update(int id, int val)
{
    for (; id <= cnt; id += (id&(-id))) fen[id] += val;
}
int getres(int id)
{
    int res = 0;
    for (; id; id -= (id&(-id))) res += fen[id];
    return res;
}
void dfs(int u, int par)
{
    in[u] = ++cnt;
    for (auto v : a[u]) if (v != par) child[u]++;
    for (auto v : a[u])
    if (v != par)
    {
        sx[v] = 1ll*sx[u]*child[u]%MOD;
        dfs(v, u);
    }
    out[u] = ++ cnt;
}
void solve() 
{
    int n, q;
    cin >> n >> q;
    //cout << n << " " << q << endl;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    sx[1] = 1;
    dfs(1, 0);
    while(q--)
    {
        int type, u;
        cin >> type >> u;
        if (type == 2)
        {
            if (block[u] == false)
            {
                update(in[u], 1); update(out[u], -1);
            }
            else
            {
                update(in[u], -1); update(out[u], 1);
            }
            block[u] = 1 - block[u];
        }
        else
        {
            int cango = getres(in[u]);
            //cout << in[u] << " " << cango << endl;
            if (cango == 1)
            {
                //cout << "um ";
                if (block[u] == true) cout << "1 " << sx[u] << "\n";
                else cout << "0\n";
            }
            else if (cango == 0)
            {
                //cout <<"he ";
                if (child[u] == 0) cout << "1 " << sx[u] << "\n";
                else cout << "0\n";
            }
            else cout << "0\n";
        }
    }
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
