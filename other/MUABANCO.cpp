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

int a[2000005], n;
vector<int> ldk;

struct DATA
{
    int Min, Max; pair<int,int> Pair[2];

    DATA()
    {
        Min = -1; Max = -1; Pair[0] = Pair[1] = {-1, -1};
    }

    DATA operator + (const DATA &other) const
    {
        DATA res;
        if (Pair[0].fi != -1 && other.Pair[0].fi != -1) 
        {
            res.Pair[0] = (a[Pair[0].se] - a[Pair[0].fi] > a[other.Pair[0].se] - a[other.Pair[0].fi] ? Pair[0] : other.Pair[0]);
            res.Pair[1] = (a[Pair[1].fi] - a[Pair[1].se] > a[other.Pair[1].fi] - a[other.Pair[1].se] ? Pair[1] : other.Pair[1]);
        }
        else if (other.Pair[0].fi != -1)
        {
            res.Pair[0] = other.Pair[0];
            res.Pair[1] = other.Pair[1];
        }
        else if (Pair[0].fi != -1)
        {
            res.Pair[0] = Pair[0];
            res.Pair[1] = Pair[1];
        }

        int x = Min, y = Max, z = other.Min, t = other.Max;

        if (t != -1 && x != -1)
        {
            if (res.Pair[0].fi == -1 || a[t] - a[x] > a[res.Pair[0].se] - a[res.Pair[0].fi]) 
                res.Pair[0] = {x, t};
        }

        if (y != -1 && z != -1)
        {
            if (res.Pair[1].fi == -1 || a[y] - a[z] > a[res.Pair[1].fi] - a[res.Pair[1].se])
                res.Pair[1] = {y, z};
        }

        if (y != -1 && t != -1) res.Max = (a[y] > a[t] ? y : t);
        else if (y != -1) res.Max = y;
        else if (t != -1) res.Max = t;

        if (x != -1 && z != -1) res.Min = (a[x] < a[z] ? x : z);
        else if (x != -1) res.Min = x;
        else if (z != -1) res.Min = z;

        return res;
    }
};

DATA sg[8000005];

void build(int id, int l, int r)
{
    if (l == r)
    {
        sg[id].Min = l;
        sg[id].Max = l;
        return;
    }

    int mid = (l + r) >> 1;
    build(id*2, l, mid); build(id*2 + 1, mid + 1, r);
    
    sg[id] = sg[id*2] + sg[id*2 + 1];
}

DATA getmax(int id, int l, int r, int u, int v)
{
    if (l > v || r < u) return DATA();

    if (u <= l && r <= v)
    {
        return sg[id];
    }

    int mid = (l + r) >> 1;

    return getmax(id*2, l, mid, u, v) + getmax(id*2 + 1, mid + 1, r, u, v);
}

void add(int l, int r, bool ti = 0)
{
    if (l >= r) return;

    pair<int, int> w = getmax(1, 1, n, l, r).Pair[ti];
    if (ti == 0)
    {
        if (a[w.se] - a[w.fi] <= 0) return;
        ldk.pb(a[w.se] - a[w.fi]);
    }
    else
    {   
        if (a[w.fi] - a[w.se] <= 0) return;
        ldk.pb(a[w.fi] - a[w.se]);
    }
    add(w.fi + 1, w.se - 1, 1 - ti); add(l, w.fi - 1, ti); add(w.se + 1, r, ti);
}

void solve() 
{
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);

    add(1, n);

    sort(ALL(ldk)); reverse(ALL(ldk));

    ll ans = 0;

    for (int i = 0; i < min(k, (int)ldk.size()); i++)
    {
        ans += ldk[i];
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
    // freopen("MUABANCO.inp","r",stdin); freopen("MUABANCO.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
