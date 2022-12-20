#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int lim = 125250;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 9223372036854775807;
int a[100005];
int n, k, q;
void sub1()
{
    if (k == 1)
    {
        cout << a[1] + a[2] << "\n";
    }
    else 
    {
        cout << max(a[1], a[2]) << "\n";
    }
    int dem = 0;
    while(q--)
    {
        dem++;
        int l, r;
        cin >> l >> r;
        for (int i = l; i <= r; i++) a[i]--;
        if (k == 1)
        {
            cout << a[1] + a[2] + dem << "\n";
        }
        else 
        {
            cout << max(a[1], a[2]) + dem<< "\n";
        }   
    }
}
int st[400005], lazy[400005];
void dolazy(int id)
{
    int &add = lazy[id];
    st[id*2] += add; lazy[id*2] += add;
    st[id*2+1] += add; lazy[id*2+1] += add; 
    add = 0;
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (r < u || v < l) return;
    if (u <= l && r <= v)
    {
        st[id] += val; lazy[id] += val;
        return;
    }
    dolazy(id);
    int mid = (l + r)/2;
    update(id*2, l, mid, u, v, val); update(id*2+1, mid + 1, r, u, v, val);
    st[id] = max(st[id*2], st[id*2 + 1]);
}
void sub2()
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        update(1, 1, n, i, i, a[i]);
    }

    cout << max(sum/k + (sum%k !=0), 1ll*st[1]) << "\n";
    int dem = 0;
    while(q--)
    {
        dem++;
        int l, r;
        cin >> l >> r;
        sum -= (r - l + 1);
        update(1, 1, n, l, r, -1);
        cout << max(sum/k + (sum%k != 0), 1ll*st[1]) + dem <<"\n";
    }
}
void solve()
{   
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
    }
    if (n == 2) sub1(); else sub2();
}
int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    solve();
}
