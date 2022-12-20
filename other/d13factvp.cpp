#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
#define fi first
#define se second
#define pb push_back
#define log 12
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
const long long oo15 = 1e15, oo18 = 1e15+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int lim = 1000000;
vector<int> ldk[1000005], a[100005];
ll dist[100005][log][3], s[100005], c[100005], luu[100005][log][2];
int pri[lim + 5];
bool ok[100005][log];
ll ans = -oo18;

void dfs(int u, int par)
{
    int n = (int)ldk[c[u]].size();
    vector<ll> mx(n, -oo18);

    for (auto v : a[u])
    if (v != par)
    {
        dfs(v, u);
        int nn = (int)ldk[c[v]].size();

        for (int i = 0, j = 0; i < n; i++)
        {
            while(j + 1 < nn && ldk[c[v]][j] < ldk[c[u]][i]) j++;
            if (j < nn && ldk[c[v]][j] == ldk[c[u]][i])
            {
                if (dist[v][j][0] > dist[u][i][0])
                {
                    mx[i] = dist[u][i][1];
                    dist[u][i][1] = dist[u][i][0];
                    dist[u][i][0] = dist[v][j][0];
                }
                else if (dist[v][j][0] > dist[u][i][1])
                {
                    mx[i] = dist[u][i][1];
                    dist[u][i][1] = dist[v][j][0];
                }
                else mx[i] = max(mx[i], dist[v][j][0]);
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        if (dist[u][i][0] > -oo18 && dist[u][i][1] > -oo18 && mx[i] > -oo18)
        ans = max(ans, 2*dist[u][i][0] + 2*dist[u][i][1] + 2*mx[i] + 3*s[u]);
        else if (dist[u][i][0] > -oo18 && dist[u][i][1] > -oo18)
        ans = max(ans, 2*dist[u][i][0] + 2*dist[u][i][1] + 3*s[u]);

        if (dist[u][i][0] == -oo18) dist[u][i][0] = 0; else
        {
            luu[u][i][0] = dist[u][i][0] + s[u];
            ok[u][i] = true;
        }

        if (dist[u][i][1] > -oo18)
        {
            luu[u][i][1] = dist[u][i][1] + s[u];
        }

        dist[u][i][0] = max(dist[u][i][0], 0ll);

        if (dist[u][i][1] > -oo18) dist[u][i][1] = max(dist[u][i][1], 0ll);

        dist[u][i][0] += s[u]; 
        if (dist[u][i][1] > -oo18)
        dist[u][i][1] += s[u];

        //cout << u << " " << ldk[c[u]][i] << " " << dist[u][i][0] << " " << dist[u][i][1] << "\n";
    }
}

void dfs1(int u, int par)
{
    int n = (int)ldk[c[u]].size();

    for (int i = 0; i < n; i++)
    if (ok[u][i] && dist[u][i][2] > -oo18)
    {   
        if (luu[u][i][1] > -oo18)
        ans = max(ans, 2*(luu[u][i][0] + luu[u][i][1] + dist[u][i][2]) - 3*s[u]);
        
        ans = max(ans, 2*(luu[u][i][0] + dist[u][i][2]) - s[u]);
    }

    for (auto v : a[u])
    if (v != par)
    {   
        int nn = (int)ldk[c[v]].size();

        for (int i = 0, j = 0; i < nn; i++)
        {
            while(j + 1 < n && ldk[c[u]][j] < ldk[c[v]][i]) j++;
            if (j < n && ldk[c[v]][i] == ldk[c[u]][j])
            {
                if (dist[u][j][2] > -oo18)
                {
                    dist[v][i][2] = dist[u][j][2] + s[v];
                }
                 
                dist[v][i][2] = max(dist[v][i][2], s[u] + s[v]);
                
                if (dist[u][j][0] > -oo18 && dist[v][i][0] + s[u] != dist[u][j][0])
                {
                    dist[v][i][2] = max(dist[v][i][2], dist[u][j][0] + s[v]);
                }
                else if (dist[u][j][1] > -oo18)
                {
                    dist[v][i][2] = max(dist[v][i][2], dist[u][j][1] + s[v]);
                }
            }
        }
        dfs1(v, u);
    }
}

void solve() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < log; j ++) dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = luu[i][j][0] = luu[i][j][1] = -oo18;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }


    for (int i = 2; i <= lim; i++)
    if (pri[i] == 0)
    {
        for (int j = i; j <= lim; j += i)
        {
            pri[j] = i;
        }
    }

    for (int i = 1; i <= n; i++)
    if (c[i] != 1 && (int)ldk[c[i]].size() == 0)
    {
        int val = c[i];
        while(val > 1)
        {
            if ((int)ldk[c[i]].size() == 0 || ldk[c[i]].back() != pri[val])
            ldk[c[i]].pb(pri[val]);
            val /= pri[val];
        }
        reverse(ALL(ldk[c[i]]));
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }
    dfs(1, 0); dfs1(1, 0);

    if (ans == -oo18)
    {
        cout << "No Solution"; return;
    }
    cout << ans;
}

int main() 
{   
     #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
