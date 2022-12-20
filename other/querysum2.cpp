#include<bits/stdc++.h>
using namespace std;
int a[100005];
struct NODE
{
    long long val, lazy;
} st[400005];
void down(int id, int mid, int l, int r)
{
    long long t = st[id].lazy;
    st[id*2].val += 1ll*t*(mid-l+1);
    st[id*2 + 1].val += 1ll*t*(r - mid);
    st[id*2].lazy += t;
    st[id*2 + 1].lazy += t;
    st[id].lazy = 0;
}
void build(int id, int l, int r)
{
    if (l > r)
    {
        return ;
    }
    if (l == r)
    {
        st[id].val = a[l];
        return ;
    }
    int mid = (l + r)/2;
    build(id*2, l, mid); build(id*2 + 1, mid + 1, r);
    st[id].val = st[id*2].val + st[id*2 + 1].val;
}
void update(int id, int l, int r, int u, int v, long long vall)
{
    if (l > v || r < u) 
    {
        return;
    }
    if (u <= l && r <= v)
    {
        st[id].val += 1ll*vall*(r-l+1);
        st[id].lazy += vall;
        return;
    }
    int mid = (l + r)/2;
    down(id, mid, l, r);
    update(id*2, l, mid, u, v, vall);
    update(id*2 + 1, mid + 1, r, u, v, vall);
    st[id].val = st[id*2].val + st[id*2 + 1].val;
}
long long getsum(int id, int l, int r, int u, int v)
{
    if (l > v || r < u)
    {
        return 0;
    }
    if (u <= l && r <=v)
    {
        return st[id].val;
    }
    int mid = (l + r)/2;
    down(id, mid, l, r);
    return getsum(id*2, l, mid, u, v) + getsum(id*2 + 1, mid + 1, r, u, v);
} 
int main()
{
    freopen("yeunhi.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    int n, q, type, u, v; long long vall;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >>a[i];  
    }
    build(1, 1, n);
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> u >> v >> vall;
            update(1, 1, n, u, v, vall);
        }
        else
        {
            cin >> u >> v;
            cout << getsum(1, 1, n, u, v) << endl;
        }
    }
}