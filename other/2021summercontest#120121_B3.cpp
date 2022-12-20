#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1 << (i))
#define setp(x) setprecision(x)
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 1e5;
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18;
bool maximize(int &x, const int &y)
{
    if (x < y)
    {
        x = y; 
        return true;
    }
    return false;
}
int limit = 0, limit1 = 0;
vector<pair<int,int> > open[2000000], close[2000000];
int l[400005], v[400005], r[400005], lazy[5000000];
pair<int,int> st[5000000];

//push down

//segment tree
void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = {0, l};
        return;
    }
    int mid = (l + r)/2;
    build(id*2, l, mid); build(id*2 + 1, mid + 1, r);
    st[id] = max(st[id*2], st[id*2+1]);
}
void dolazy(int id)
{
    int xx = lazy[id];
    lazy[id*2] += xx; lazy[id*2+1] += xx;
    st[id*2].fi += xx; st[id*2+1].fi += xx;
    lazy[id] = 0;
}
void update(int id, int l, int r, int u, int v, int vall)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        st[id].fi+=vall; lazy[id] += vall;
        return;
    }
    dolazy(id);
    int mid = (l + r)/2;
    update(id*2, l , mid, u , v, vall); update(id*2 + 1, mid + 1, r, u, v, vall);
    st[id] = max(st[id*2], st[id*2+1]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt", "r", stdin);
    freopen("goodbyedking.txt", "w", stdout);
    #else
    //online submission
    //freopen("tenbai.inp", "r", stdin); freopen("tenbai.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> ldk;
    
    //input
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> l[i] >> v[i] >> r[i];
        ldk.pb(l[i]); ldk.pb(v[i]); ldk.pb(r[i]);
    }
    
    //nen
    sort(ldk.begin(), ldk.end());
    ldk.resize(unique(ldk.begin(), ldk.end()) - ldk.begin());
    for(int i = 1 ; i <= n; i++)
    {
        l[i] = lower_bound(ldk.begin(), ldk.end(), l[i]) - ldk.begin() + 1;
        v[i] = lower_bound(ldk.begin(), ldk.end(), v[i]) - ldk.begin() + 1;
        r[i] = lower_bound(ldk.begin(), ldk.end(), r[i]) - ldk.begin() + 1;
        limit = max(limit, v[i]);
        limit1 = max(limit1, r[i]);
        open[l[i]].pb({v[i], r[i]});
        close[v[i]+1].pb({v[i], r[i]});
        //cout << l[i] <<" "<<v[i] <<" "<<r[i] << endl;
    }
    
    //khoi tao
    build(1, 1, limit1);

    //xuli
    int maxpoint = -1;
    pair<int,int> point = {-1, -1};
    for (int i = 1; i <= limit; i++)
    {
        for (auto v : open[i]) update(1, 1, limit1, v.fi, v.se, 1);
        for (auto v : close[i]) update(1, 1, limit1, v.fi, v.se, -1);
        
        pair<int,int> curpoint = st[1]; //cout << curpoint.fi <<" "<<curpoint.se << endl;
        
        if (maximize(maxpoint, curpoint.fi)) point = {i, curpoint.se};
    }
    
    //output
    cout << maxpoint<<"\n";
    for (int i = 1; i <= n; i++)  
    if (l[i] <= point.fi&&point.fi <= v[i]&&v[i] <= point.se&& point.se <= r[i])
    {
        cout << i << " ";
    }
}