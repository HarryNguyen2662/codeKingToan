#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
void  build(int i, int id, int l , int r, int val)
{
    if (i < l || r < i) {
        return ;
    }
    if (l==r)
    {
        a[id]+=val;
        return;
    }
    int mid = (l+r)/2;
    build(i, id*2 ,l , mid, val);
    build(i, id*2+1,mid+1, r, val);
    a[id]=a[id*2]+a[id*2+1];
}
long long sum(int id, int l, int r, int v, int u)
{
    if (l > u || r < v) 
    {
        return 0;
    }
    if (v <= l && u >= r)
    {
        return a[id];
    }
    int mid = (l + r)/2;
    return sum(id*2, l, mid ,v ,u)+sum(id*2+1, mid+1, r, v, u);
}
int main()
{
    freopen("yeunhi.txt", "r", stdin);
    int n, q ,x, u , val, type;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        build(i, 1, 1, n, x);
    }
    while(q--)
    {
        cin>> type >> u >> val;
        if (type == 1) 
        {
            build(u, 1, 1, n, val);
        }
        else cout<< sum(1, 1, n, u, val) << endl;
    }
}