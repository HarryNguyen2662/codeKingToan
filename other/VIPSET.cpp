#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6+5;
const int oo = 1e9;
long long c[350];
vector<int> b[350],a[350];
int dem[350],demm[350];
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission    
    #endif
    // freopen("bai1.inp","r", stdin);
    // freopen("bai1.out","w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n, res= 0;
        cin >> n;
        for (int i = 1; i <= n; i++ )
        {
            cin >> c[i];
           dem[i] = 0; b[i].clear(); demm[i] = 0; a[i].clear();
        }
        for (int i = 1; i<= n ;i++)
            for (int j = 1; j <= n; j++)
            if (i!=j&&c[i]%c[j] == 0)
            {
                dem[i]++;
                b[j].pb(i);
                a[i].pb(j);
                demm[j]++;
            }
        while(true)
        {
            int d=0,dd=0;
            for (int i = 1; i<= n; i++)
            if (dem[i]!=-1)
            {
                if (dem[d] < dem[i]) d = i;
            }
             for (int i = 1; i<= n; i++)
            if (demm[i]!=-1)
            {
                if (demm[d] < demm[i]) dd = i;
            }
            if (d == 0&&dd == 0) break;
           // cout<< d << " "<< dd<<endl;
            res++;
            if (dem[d] > demm[dd])
            {
                dem[d] = -1;
                for(auto v : b[d]) if (dem[v]!=-1) dem[v] --;
                for(auto v : a[d]) if (demm[v]!=-1) demm[v] --;
            }
            else
            {
                demm[dd] = -1;
                for(auto v : a[dd]) if (demm[v]!=-1) demm[v] --;
                for(auto v : b[dd]) if (dem[v]!=-1) dem[v] --;
            }
        }
        cout << n - res<<"\n";
    }
}   