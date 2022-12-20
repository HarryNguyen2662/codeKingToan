#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 998244353;
const int MAXN = 1e6;
const int oo = 1e9;
struct node
{
    int lz,vl;
} st[MAXN];
int c[MAXN], lst[MAXN], dd[MAXN], dp[350650][105];
void buildtree(int i, int l, int r)
{
   // if (l > r) return;
    st[i].lz = 0;
    if (l==r) 
    {
        st[i].vl = c[l];
        return;
    }
    int mid = (l+r)/2;
    buildtree(i*2, l, mid);
    buildtree(i*2+1, mid +1, r);
    st[i].vl = min (st[i*2].vl, st[i*2+1].vl);
}
void downtree(int i)
{
    int  x = st[i].lz;
    st[i*2].vl += x;
    st[i*2].lz += x;
    st[i*2+1].vl +=x;
    st[i*2+1].lz +=x;
    st[i].lz = 0;
}
void updtree(int i, int l, int r, int u, int v, int x)
{
    if (r < u || l > v) return;
    if (u <= l && r <= v)
    {
        st[i].vl += x;
        st[i].lz += x;
        return;
    }
    int mid = (l+r)/2;
    downtree(i);
    updtree(i*2, l, mid, u, v, x);
    updtree(i*2+1, mid + 1, r, u, v, x);
    st[i].vl = min(st[i*2].vl, st[i*2 + 1].vl);
}
int getmin(int i, int l, int r, int u, int v)
{
    if (r < u || l > v) return oo;
    if (u <= l && r <= v)
    {
        return st[i].vl;
    }
    downtree(i);
    int mid = (l + r)/2;
    return min(getmin(i*2, l, mid, u ,v ), getmin(i*2 + 1, mid + 1, r, u, v));
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >>n >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
    {
        lst[i] = dd[c[i]];
        dd[c[i]] = i;
    }
    for(int i = 1; i <= n; i ++)
        if(lst[i] > 0) dp[i][1] = dp[i-1][1] + i - lst[i]; else dp[i][1] = dp[i-1][1];
   // for (int i = 1; i<= n; i++) cout << dp[i][1]<<endl;
    for (int i = 2; i<= k; i++)
    {
        for (int j = 1; j <= n; j++) c[j] = dp[j][i-1];
        buildtree(1,1,n);
        for (int j = 1; j < i; j++) dp[j][i] = oo;
        dp[i][i] = 0;
        for (int j = i + 1; j <= n; j++)
        {
            if (lst[j] > i-1)
            {
                updtree(1, 1, n, i-1, lst[j]-1, j - lst[j]);
           //     cout << "check "<< j - lst[j]<<endl;
            }
            dp[j][i] = getmin(1, 1, n, i-1, j - 1);
         //   cout << dp[j][i]<<endl;
        }
    }
   // for (int i  = 1; i <= n; i++) cout << getmin(1,1,n,i,i)<<endl;
    cout << dp[n][k];
}