#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const long long oo = 1e2;
int s[1000005];
long long st[4000005];
vector<int> ldk[1000005];
int lim[1000005];
int dem[1000005];
bool minimize(int &x, int y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else return false;
}
void updt(int id, int l, int r, int i, long long vl)
{
    if (l > i || r < i) return;
    if ( l == r)
    {
        st[id] = vl;
        return;
    }
    int mid = (l + r)/2;
    updt(id*2, l, mid, i, vl);
    updt(id*2 + 1, mid + 1, r, i, vl);
    st[id] = min(st[id*2], st[id*2 + 1]);
}
long long getmin(int id, int l, int r, int u, int v)
{
    if (l > v || r < u) return oo;
    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r)/2;
    return min(getmin(id*2, l, mid, u ,v), getmin(id*2+1, mid +1, r, u, v));
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission    
    #endif
     //freopen("guard.inp","r", stdin);
     //freopen("guard.out","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt, t;
    cin >> tt >> t;
    while ( t -- )
    {
        int n, k , q,x,y;
        cin >> n >> k >> q;
        for (int i = 1; i <= q; i ++) 
            cin >> s[i];
        int l =  1; int demm = 0;
       // memset(dem, 0 , sizeof dem);
        for (int i = 1; i <= q; i++)
        {
            cin >> x;
            for (int j = 1; j <= x; j++)
            {
                cin >> y;
             //   cout << y << endl;
                if (dem[y] == 0) demm++;
                dem[y]++;
                ldk[i].pb(y);
            }
           // cout <<ldk[l].size()<<"fuvk "<<endl;
            while (l < i && demm > k)
            {
                for (auto  v: ldk[l])
                {
                //   cout << " check " << v << endl;
                    dem[v]--; if (dem[v] == 0 ) demm--;
                }
                l++;
            }
            lim[i] = l;
            //cout << l << endl;
        }
        while (l <= q)
            {
                for (auto  v: ldk[l])
                {
                //   cout << " check " << v << endl;
                    dem[v]--; 
                }
                l++;
            }
        updt(1,1,q,1,0);
       // updt(1,1,q,1,0);
        long long kk;
        for (int i = 1; i <= q; i++)
        {
             ldk[i].clear();
             kk = getmin(1, 1, q, lim[i], i);
             updt(1, 1, q ,i + 1, kk + s[i+1]);
            //cout <<getmin(1, 1, q, 1, 1)<<" "<<getmin(1, 1, q, 2, 2)<<" ";
            //cout <<getmin(1, 1, q, 3, 3)<<" "<<getmin(1, 1, q, 4, 4)<<endl;
        }
        cout << kk<<" ";
    }
}   