#include<bits/stdc++.h>
using namespace std;
struct Kingtapcodelazy
{
    long long lazy, val;
} a[1000005];
void down (int id)
{
    long long t = a[id].lazy;
    a[id*2].lazy+=t;
    a[id*2+1].lazy+=t;
    a[id*2].val+=t;
    a[id*2+1].val+=t;
    a[id].lazy=0;
}
void update(int id, int l, int r, int u, int v, long long vall)
{
    if (l >v || r < u)
    {
        return ;
    }   
    if (u <= l && r <= v)
    {
        a[id].lazy+=vall;
        a[id].val+=vall;
        return ;
    }
    int mid = (l + r)/2;
    down(id);
    update(id*2, l, mid, u, v, vall);
    update(id*2+1, mid+1, r, u , v, vall);
    a[id].val=max(a[id*2].val, a[id*2+1].val);
}
long long getmax(int id, int l, int r, int u , int v)
{
    if (l > v || r < u)
    {
        return -1;
    }
    if (u <= l && r <= v)
    {
        return a[id].val;
    }
    int mid = (l + r)/2;
    down(id);
    return max(getmax(id*2, l, mid, u, v),getmax(id*2+1, mid+1, r, u, v));
}
int main()
{
    freopen("yeunhi.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q, v, u, type; long long x, vall;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        update(1, 1, n, i, i, x);
    }
    while(q--)
    {
        cin >> type;
        if (type ==1)
        {
            cin >> u >> v >> vall;
            update(1, 1, n, u, v, vall);
        }
        else
        {
            cin >> u >> v;
            cout<< getmax(1, 1, n, u, v) << endl;
        }
    }
}