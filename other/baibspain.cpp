#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353; 
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18;   
const long long oooo = 9223372036854775807;
int n, a[100005], b[100005];
struct segment
    {
        long long sum, lazy, mn, sum1, lazy1, index, cnt;
        segment()
        {
            sum = lazy = mn = sum1 = lazy1 = index = cnt = 0;
        }
};
segment st[400005];
    
void build(int id, int l, int r)
{
    if (l > r) return;
    if (l == r)
    {
        st[id].index = l;   
        st[id].sum = a[l];
        st[id].mn = b[l]-a[l];
        return;
    }
    int mid = (l + r)/2;
    build(id*2, l, mid); build(id*2 + 1, mid + 1, r);
    st[id].sum = st[id*2].sum + st[id*2+1].sum;
    if (st[id*2].mn <= st[id*2+1].mn)
    {
        st[id].mn = st[id*2].mn; st[id].index = st[id*2].index;
    }
    else
    {
        st[id].mn = st[id*2+1].mn; st[id].index = st[id*2+1].index;
    }
}
void dolazy(int id, int l, int r)
{
    int mid = (l+r)/2;
    int val = st[id].lazy;
    st[id*2].sum += 1ll*(mid-l+1)*val; st[id*2].mn -= val; st[id*2].sum1 += st[id*2].cnt*1ll*val;
    st[id*2].lazy += val;
    st[id*2+1].sum += 1ll*(r-mid)*val; st[id*2+1].mn -= val; st[id*2+1].sum1 += st[id*2+1].cnt*1ll*val; 
    st[id*2+1].lazy += val;
    st[id].lazy = 0;
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (r < u || l > v) return;
    if (u <= l && r <= v)
    {
        st[id].sum += 1ll*(r-l+1)*val;
        st[id].sum1 += st[id].cnt*val;
        st[id].lazy += val;
        st[id].mn -= val; 
        return;
    }
    dolazy(id, l, r);
    int mid = (l + r)/2;
    update(id*2, l, mid, u, v, val); update(id*2 + 1, mid + 1, r, u, v, val);
    st[id].sum = st[id*2].sum + st[id*2+1].sum;
    st[id].sum1 = st[id*2].sum1 + st[id*2+1].sum1;
    if (st[id*2].mn <= st[id*2+1].mn)
    {
        st[id].mn = st[id*2].mn; st[id].index = st[id*2].index;
    }
    else
    {
        st[id].mn = st[id*2+1].mn; st[id].index = st[id*2+1].index;
    }
}
void turnon(int id, int l, int r, int x, int val)
{
    if (l > x || r < x) return;
    if (l == r)
    {
        st[id].sum1 = val;
        st[id].cnt = 1;
        st[id].mn = oo18; st[id].index = -1;
        return;
    }
    dolazy(id, l, r);
    int mid = (l + r)/2;
    turnon(id*2, l, mid, x, val); turnon(id*2+1, mid+1, r, x, val);
    st[id].cnt = st[id*2].cnt + st[id*2+1].cnt;
    st[id].sum1 = st[id*2].sum1 + st[id*2+1].sum1;
    if (st[id*2].mn <= st[id*2+1].mn)
    {
        st[id].mn = st[id*2].mn; st[id].index = st[id*2].index;
    }
    else
    {
        st[id].mn = st[id*2+1].mn; st[id].index = st[id*2+1].index;
    }
}
int getmin(int id, int l, int r, int u, int v)
{
    if (r < u || l > v) return -1;
    if (u <= l && r <= v)
    {
        return id;
    }
    dolazy(id, l, r);
    int mid = (l + r)/2;
    int x = getmin(id*2, l, mid, u, v), y = getmin(id*2+1, mid+1, r, u, v);
    if (x != -1 && y != -1)
    {
        if (st[x].mn <= st[y].mn) return x;
        else return y;
    }
    else if (x == -1) return y;
    else return x;
}
void query(int l, int r, int val)
{
    update(1, 1, n, l, r, val);
    int t = getmin(1, 1, n ,l, r);
    while (t != -1 && st[t].mn <= 0)
    {
        turnon(1, 1, n, st[t].index, -st[t].mn);
        t = getmin(1, 1, n, l, r);
    }
}
long long getsum(int id, int l, int r, int u, int v)
{
    if (r < u || l > v) return 0;
    if (u <= l && r <= v)
    {
        return st[id].sum - st[id].sum1;
    }
    dolazy(id, l, r);
    int mid = (l + r)/2;
    return getsum(id*2, l, mid, u, v) + getsum(id*2+1, mid + 1, r, u, v);
}
void getres(int l, int r)
{
    cout << getsum(1, 1, n, l, r)<<"\n";
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    build(1, 1, n);
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 0)
        {
            int d;
            cin >> d;
            query(l, r, d);
        }
        else
        {
            getres(l, r);
        }
    }
}
